#include "product_manager.h"
#include "product_data_source.h"
#include "operation_processor.h"
#include "uuid_generator.h"

using namespace sf1r;

ProductManager::ProductManager(ProductDataSource* data_source, OperationProcessor* op_processor, const PMConfig& config)
:data_source_(data_source), op_processor_(op_processor), uuid_gen_(new UuidGenerator()), config_(config)
{
}

ProductManager::~ProductManager()
{
    delete uuid_gen_;
}


bool ProductManager::HookInsert(PMDocumentType& doc)
{
    izenelib::util::UString uuid = uuid_gen_->Gen(doc);
    PMDocumentType new_doc(doc);
    doc.property(config_.uuid_property_name) = uuid;
    new_doc.property(config_.docid_property_name) = uuid;
    new_doc.property(config_.itemcount_property_name) = izenelib::util::UString("1", izenelib::util::UString::UTF_8);
    op_processor_->Append(1, new_doc);
    return true;
}

bool ProductManager::HookUpdate(uint32_t fromid, PMDocumentType& to, bool r_type)
{
    return HookUpdateNew_(fromid, to);
//         uint32_t fromid = from.getId();
//         uint32_t toid = to.getId();
//         if(fromid==toid) // if(r_type) ??
//         {
//             HookUpdateSame_(from, to);
//         }
//         else
//         {
//             HookUpdateNew_(from, to);
//         }
    
}

bool ProductManager::HookDelete(uint32_t docid)
{
    PMDocumentType from;
    if(!data_source_->GetDocument(docid, from)) return false;
    izenelib::util::UString from_uuid;
    if(!GetUuid_(from, from_uuid)) return false;
    std::vector<uint32_t> docid_list;
    data_source_->GetDocIdList(from_uuid, docid_list, docid); // except from.docid
    if(docid_list.empty()) // the from doc is unique, so delete it in A
    {
        PMDocumentType del_doc;
        del_doc.property(config_.docid_property_name) = from_uuid;
        op_processor_->Append(3, del_doc);
    }
    else
    {
        PMDocumentType diff_properties;
        ProductPrice price;
        GetPrice_(docid_list, price);
        diff_properties.property(config_.price_property_name) = price.ToUString();
        diff_properties.property(config_.docid_property_name) = from_uuid;
        diff_properties.property(config_.itemcount_property_name) = izenelib::util::UString(boost::lexical_cast<std::string>(docid_list.size()), izenelib::util::UString::UTF_8);
        op_processor_->Append(2, diff_properties);
    }
    return true;
}

void ProductManager::GenOperations()
{
    op_processor_->Finish();
}

bool ProductManager::HookUpdateNew_(uint32_t fromid, PMDocumentType& to)
{
    PMDocumentType from;
    if(!data_source_->GetDocument(fromid, from)) return false;
    izenelib::util::UString from_uuid;
    if(!GetUuid_(from, from_uuid)) return false;
    std::vector<uint32_t> docid_list;
    data_source_->GetDocIdList(from_uuid, docid_list, fromid); // except from.docid
    if(docid_list.empty()) // the from doc is unique, so delete it and insert 'to'
    {
        PMDocumentType new_doc(to);
        to.property(config_.uuid_property_name) = from_uuid;
        new_doc.property(config_.docid_property_name) = from_uuid;
        new_doc.property(config_.itemcount_property_name) = izenelib::util::UString("1", izenelib::util::UString::UTF_8);
        op_processor_->Append( 2, new_doc);// if r_type, only numberic properties in 'to'
    }
    else
    {
        ProductPrice from_price;
        ProductPrice to_price;
        if(!GetPrice_(fromid, from_price)) return false;
        if(!GetPrice_(to.getId(), to_price)) return false;
        //update price only
        if(from_price!=to_price)
        {
            PMDocumentType diff_properties;
            ProductPrice price(to_price);
            GetPrice_(docid_list, price);
            diff_properties.property(config_.price_property_name) = price.ToUString();
            diff_properties.property(config_.docid_property_name) = from_uuid;
            //auto r_type? itemcount no need?
//                 diff_properties.property(config_.itemcount_property_name) = izenelib::util::UString(boost::lexical_cast<std::string>(docid_list.size()+1), izenelib::util::UString::UTF_8);
            
            op_processor_->Append( 2, diff_properties );
        }
    }
    return true;
}

bool ProductManager::GetPrice_(uint32_t docid, ProductPrice& price)
{
    PMDocumentType doc;
    if(!data_source_->GetDocument(docid, doc)) return false;
    Document::property_const_iterator it = doc.findProperty(config_.price_property_name);
    if(it == doc.propertyEnd())
    {
        return false;
    }
    izenelib::util::UString price_str = it->second.get<izenelib::util::UString>();
    if(!price.Parse(price_str)) return false;
    return true;
}

void ProductManager::GetPrice_(const std::vector<uint32_t>& docid_list, ProductPrice& price)
{
    for(uint32_t i=0;i<docid_list.size();i++)
    {
        ProductPrice p;
        if(GetPrice_(docid_list[i], p))
        {
            price += p;
        }
    }
}

bool ProductManager::GetUuid_(const PMDocumentType& doc, izenelib::util::UString& uuid)
{
    PMDocumentType::property_const_iterator it = doc.findProperty(config_.uuid_property_name);
    if(it == doc.propertyEnd())
    {
        return false;
    }
    uuid = it->second.get<izenelib::util::UString>();
    return true;
}
