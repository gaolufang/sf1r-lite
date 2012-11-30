/**
 * @file process/RouterInitializer.cpp
 * @date Created <2012-11-22 16:19:10>
 *
 * This file is generated by generators/router_initializer.rb from config file
 * generators/router_initializer.yml. Do not edit this file directly. Please read
 * the config file, update options there and re-run the ruby script to
 * update this file.
 */

#include "RouterInitializer.h"
#include <util/driver/ActionHandler.h>

#include <memory> // for std::auto_ptr

#include "controllers/AutoFillController.h"
#include "controllers/CommandsController.h"
#include "controllers/KeywordsController.h"
#include "controllers/DocumentsController.h"
#include "controllers/TestController.h"
#include "controllers/StatusController.h"
#include "controllers/LogAnalysisController.h"
#include "controllers/FacetedController.h"
#include "controllers/QueryCorrectionController.h"
#include "controllers/TopicController.h"
#include "controllers/RecommendController.h"
#include "controllers/ServiceController.h"
#include "controllers/ProductController.h"
#include "controllers/SynonymController.h"
#include "controllers/CollectionController.h"
#include "controllers/QueryNormalizeController.h"

namespace sf1r
{

void initializeDriverRouter(::izenelib::driver::Router& router, IService* service, bool enableTest)
{
    {
        AutoFillController auto_fill;
        const std::string controllerName("auto_fill");
        typedef ::izenelib::driver::ActionHandler<AutoFillController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr indexHandler(
            new handler_type(
                auto_fill,
                &AutoFillController::index
            )
        );

        router.map(
            controllerName,
            "index",
            indexHandler.get()
        );
        indexHandler.release();
    }

    {
        QueryCorrectionController query_correction;
        const std::string controllerName("query_correction");
        typedef ::izenelib::driver::ActionHandler<QueryCorrectionController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr indexHandler(
            new handler_type(
                query_correction,
                &QueryCorrectionController::index
            )
        );

        router.map(
            controllerName,
            "index",
            indexHandler.get()
        );
        indexHandler.release();
    }

    {
        QueryNormalizeController query_normalize;
        const std::string controllerName("query_normalize");
        typedef ::izenelib::driver::ActionHandler<QueryNormalizeController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr add_QueryHandler(
            new handler_type(
                query_normalize,
                &QueryNormalizeController::add_Query
            )
        );

        router.map(
            controllerName,
            "add_Query",
            add_QueryHandler.get()
        );
        add_QueryHandler.release();

        handler_ptr delete_QueryHandler(
            new handler_type(
                query_normalize,
                &QueryNormalizeController::delete_Query
            )
        );

        router.map(
            controllerName,
            "delete_Query",
            delete_QueryHandler.get()
        );
        delete_QueryHandler.release();
    }

    {
        CommandsController commands;
        const std::string controllerName("commands");
        typedef ::izenelib::driver::ActionHandler<CommandsController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr indexHandler(
            new handler_type(
                commands,
                &CommandsController::index
            )
        );

        router.map(
            controllerName,
            "index",
            indexHandler.get()
        );
        indexHandler.release();

        handler_ptr index_query_logHandler(
            new handler_type(
                commands,
                &CommandsController::index_query_log
            )
        );

        router.map(
            controllerName,
            "index_query_log",
            index_query_logHandler.get()
        );
        index_query_logHandler.release();

        handler_ptr optimize_indexHandler(
            new handler_type(
                commands,
                &CommandsController::optimize_index
            )
        );

        router.map(
            controllerName,
            "optimize_index",
            optimize_indexHandler.get()
        );
        optimize_indexHandler.release();
    }

    {
        KeywordsController keywords;
        const std::string controllerName("keywords");
        typedef ::izenelib::driver::ActionHandler<KeywordsController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr indexHandler(
            new handler_type(
                keywords,
                &KeywordsController::index
            )
        );

        router.map(
            controllerName,
            "index",
            indexHandler.get()
        );
        indexHandler.release();

        handler_ptr inject_query_correctionHandler(
            new handler_type(
                keywords,
                &KeywordsController::inject_query_correction
            )
        );

        router.map(
            controllerName,
            "inject_query_correction",
            inject_query_correctionHandler.get()
        );
        inject_query_correctionHandler.release();

        handler_ptr inject_query_recommendHandler(
            new handler_type(
                keywords,
                &KeywordsController::inject_query_recommend
            )
        );

        router.map(
            controllerName,
            "inject_query_recommend",
            inject_query_recommendHandler.get()
        );
        inject_query_recommendHandler.release();
    }

    {
        DocumentsController documents;
        const std::string controllerName("documents");
        typedef ::izenelib::driver::ActionHandler<DocumentsController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr createHandler(
            new handler_type(
                documents,
                &DocumentsController::create
            )
        );

        router.map(
            controllerName,
            "create",
            createHandler.get()
        );
        createHandler.release();

        handler_ptr destroyHandler(
            new handler_type(
                documents,
                &DocumentsController::destroy
            )
        );

        router.map(
            controllerName,
            "destroy",
            destroyHandler.get()
        );
        destroyHandler.release();

        handler_ptr duplicate_withHandler(
            new handler_type(
                documents,
                &DocumentsController::duplicate_with
            )
        );

        router.map(
            controllerName,
            "duplicate_with",
            duplicate_withHandler.get()
        );
        duplicate_withHandler.release();

        handler_ptr getHandler(
            new handler_type(
                documents,
                &DocumentsController::get
            )
        );

        router.map(
            controllerName,
            "get",
            getHandler.get()
        );
        getHandler.release();

        handler_ptr get_doc_countHandler(
            new handler_type(
                documents,
                &DocumentsController::get_doc_count
            )
        );

        router.map(
            controllerName,
            "get_doc_count",
            get_doc_countHandler.get()
        );
        get_doc_countHandler.release();

        handler_ptr get_freq_group_labelsHandler(
            new handler_type(
                documents,
                &DocumentsController::get_freq_group_labels
            )
        );

        router.map(
            controllerName,
            "get_freq_group_labels",
            get_freq_group_labelsHandler.get()
        );
        get_freq_group_labelsHandler.release();

        handler_ptr get_key_countHandler(
            new handler_type(
                documents,
                &DocumentsController::get_key_count
            )
        );

        router.map(
            controllerName,
            "get_key_count",
            get_key_countHandler.get()
        );
        get_key_countHandler.release();

        handler_ptr get_summarizationHandler(
            new handler_type(
                documents,
                &DocumentsController::get_summarization
            )
        );

        router.map(
            controllerName,
            "get_summarization",
            get_summarizationHandler.get()
        );
        get_summarizationHandler.release();

        handler_ptr get_topicHandler(
            new handler_type(
                documents,
                &DocumentsController::get_topic
            )
        );

        router.map(
            controllerName,
            "get_topic",
            get_topicHandler.get()
        );
        get_topicHandler.release();

        handler_ptr get_topic_with_simHandler(
            new handler_type(
                documents,
                &DocumentsController::get_topic_with_sim
            )
        );

        router.map(
            controllerName,
            "get_topic_with_sim",
            get_topic_with_simHandler.get()
        );
        get_topic_with_simHandler.release();

        handler_ptr indexHandler(
            new handler_type(
                documents,
                &DocumentsController::index
            )
        );

        router.map(
            controllerName,
            "index",
            indexHandler.get()
        );
        indexHandler.release();

        handler_ptr log_group_labelHandler(
            new handler_type(
                documents,
                &DocumentsController::log_group_label
            )
        );

        router.map(
            controllerName,
            "log_group_label",
            log_group_labelHandler.get()
        );
        log_group_labelHandler.release();

        handler_ptr searchHandler(
            new handler_type(
                documents,
                &DocumentsController::search
            )
        );

        router.map(
            controllerName,
            "search",
            searchHandler.get()
        );
        searchHandler.release();

        handler_ptr set_top_group_labelHandler(
            new handler_type(
                documents,
                &DocumentsController::set_top_group_label
            )
        );

        router.map(
            controllerName,
            "set_top_group_label",
            set_top_group_labelHandler.get()
        );
        set_top_group_labelHandler.release();

        handler_ptr similar_toHandler(
            new handler_type(
                documents,
                &DocumentsController::similar_to
            )
        );

        router.map(
            controllerName,
            "similar_to",
            similar_toHandler.get()
        );
        similar_toHandler.release();

        handler_ptr similar_to_imageHandler(
            new handler_type(
                documents,
                &DocumentsController::similar_to_image
            )
        );

        router.map(
            controllerName,
            "similar_to_image",
            similar_to_imageHandler.get()
        );
        similar_to_imageHandler.release();

        handler_ptr updateHandler(
            new handler_type(
                documents,
                &DocumentsController::update
            )
        );

        router.map(
            controllerName,
            "update",
            updateHandler.get()
        );
        updateHandler.release();

        handler_ptr update_inplaceHandler(
            new handler_type(
                documents,
                &DocumentsController::update_inplace
            )
        );

        router.map(
            controllerName,
            "update_inplace",
            update_inplaceHandler.get()
        );
        update_inplaceHandler.release();

        handler_ptr visitHandler(
            new handler_type(
                documents,
                &DocumentsController::visit
            )
        );

        router.map(
            controllerName,
            "visit",
            visitHandler.get()
        );
        visitHandler.release();
    }

    {
        StatusController status;
        const std::string controllerName("status");
        typedef ::izenelib::driver::ActionHandler<StatusController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr indexHandler(
            new handler_type(
                status,
                &StatusController::index
            )
        );

        router.map(
            controllerName,
            "index",
            indexHandler.get()
        );
        indexHandler.release();
    }

    if (enableTest)
    {
        TestController test;
        const std::string controllerName("test");
        typedef ::izenelib::driver::ActionHandler<TestController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr echoHandler(
            new handler_type(
                test,
                &TestController::echo
            )
        );

        router.map(
            controllerName,
            "echo",
            echoHandler.get()
        );
        echoHandler.release();

        handler_ptr sleepHandler(
            new handler_type(
                test,
                &TestController::sleep
            )
        );

        router.map(
            controllerName,
            "sleep",
            sleepHandler.get()
        );
        sleepHandler.release();
    }

    {
        LogAnalysisController log_analysis;
        const std::string controllerName("log_analysis");
        typedef ::izenelib::driver::ActionHandler<LogAnalysisController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr delete_databaseHandler(
            new handler_type(
                log_analysis,
                &LogAnalysisController::delete_database
            )
        );

        router.map(
            controllerName,
            "delete_database",
            delete_databaseHandler.get()
        );
        delete_databaseHandler.release();

        handler_ptr delete_record_from_system_eventsHandler(
            new handler_type(
                log_analysis,
                &LogAnalysisController::delete_record_from_system_events
            )
        );

        router.map(
            controllerName,
            "delete_record_from_system_events",
            delete_record_from_system_eventsHandler.get()
        );
        delete_record_from_system_eventsHandler.release();

        handler_ptr delete_record_from_user_queriesHandler(
            new handler_type(
                log_analysis,
                &LogAnalysisController::delete_record_from_user_queries
            )
        );

        router.map(
            controllerName,
            "delete_record_from_user_queries",
            delete_record_from_user_queriesHandler.get()
        );
        delete_record_from_user_queriesHandler.release();

        handler_ptr inject_user_queriesHandler(
            new handler_type(
                log_analysis,
                &LogAnalysisController::inject_user_queries
            )
        );

        router.map(
            controllerName,
            "inject_user_queries",
            inject_user_queriesHandler.get()
        );
        inject_user_queriesHandler.release();

        handler_ptr merchant_countHandler(
            new handler_type(
                log_analysis,
                &LogAnalysisController::merchant_count
            )
        );

        router.map(
            controllerName,
            "merchant_count",
            merchant_countHandler.get()
        );
        merchant_countHandler.release();

        handler_ptr product_countHandler(
            new handler_type(
                log_analysis,
                &LogAnalysisController::product_count
            )
        );

        router.map(
            controllerName,
            "product_count",
            product_countHandler.get()
        );
        product_countHandler.release();

        handler_ptr product_update_infoHandler(
            new handler_type(
                log_analysis,
                &LogAnalysisController::product_update_info
            )
        );

        router.map(
            controllerName,
            "product_update_info",
            product_update_infoHandler.get()
        );
        product_update_infoHandler.release();

        handler_ptr system_eventsHandler(
            new handler_type(
                log_analysis,
                &LogAnalysisController::system_events
            )
        );

        router.map(
            controllerName,
            "system_events",
            system_eventsHandler.get()
        );
        system_eventsHandler.release();

        handler_ptr user_queriesHandler(
            new handler_type(
                log_analysis,
                &LogAnalysisController::user_queries
            )
        );

        router.map(
            controllerName,
            "user_queries",
            user_queriesHandler.get()
        );
        user_queriesHandler.release();
    }

    {
        FacetedController faceted;
        const std::string controllerName("faceted");
        typedef ::izenelib::driver::ActionHandler<FacetedController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr clickHandler(
            new handler_type(
                faceted,
                &FacetedController::click
            )
        );

        router.map(
            controllerName,
            "click",
            clickHandler.get()
        );
        clickHandler.release();

        handler_ptr get_custom_queryHandler(
            new handler_type(
                faceted,
                &FacetedController::get_custom_query
            )
        );

        router.map(
            controllerName,
            "get_custom_query",
            get_custom_queryHandler.get()
        );
        get_custom_queryHandler.release();

        handler_ptr get_custom_rankHandler(
            new handler_type(
                faceted,
                &FacetedController::get_custom_rank
            )
        );

        router.map(
            controllerName,
            "get_custom_rank",
            get_custom_rankHandler.get()
        );
        get_custom_rankHandler.release();

        handler_ptr get_merchant_scoreHandler(
            new handler_type(
                faceted,
                &FacetedController::get_merchant_score
            )
        );

        router.map(
            controllerName,
            "get_merchant_score",
            get_merchant_scoreHandler.get()
        );
        get_merchant_scoreHandler.release();

        handler_ptr get_ontologyHandler(
            new handler_type(
                faceted,
                &FacetedController::get_ontology
            )
        );

        router.map(
            controllerName,
            "get_ontology",
            get_ontologyHandler.get()
        );
        get_ontologyHandler.release();

        handler_ptr get_product_scoreHandler(
            new handler_type(
                faceted,
                &FacetedController::get_product_score
            )
        );

        router.map(
            controllerName,
            "get_product_score",
            get_product_scoreHandler.get()
        );
        get_product_scoreHandler.release();

        handler_ptr get_repHandler(
            new handler_type(
                faceted,
                &FacetedController::get_rep
            )
        );

        router.map(
            controllerName,
            "get_rep",
            get_repHandler.get()
        );
        get_repHandler.release();

        handler_ptr get_static_repHandler(
            new handler_type(
                faceted,
                &FacetedController::get_static_rep
            )
        );

        router.map(
            controllerName,
            "get_static_rep",
            get_static_repHandler.get()
        );
        get_static_repHandler.release();

        handler_ptr manmadeHandler(
            new handler_type(
                faceted,
                &FacetedController::manmade
            )
        );

        router.map(
            controllerName,
            "manmade",
            manmadeHandler.get()
        );
        manmadeHandler.release();

        handler_ptr set_custom_rankHandler(
            new handler_type(
                faceted,
                &FacetedController::set_custom_rank
            )
        );

        router.map(
            controllerName,
            "set_custom_rank",
            set_custom_rankHandler.get()
        );
        set_custom_rankHandler.release();

        handler_ptr set_merchant_scoreHandler(
            new handler_type(
                faceted,
                &FacetedController::set_merchant_score
            )
        );

        router.map(
            controllerName,
            "set_merchant_score",
            set_merchant_scoreHandler.get()
        );
        set_merchant_scoreHandler.release();

        handler_ptr set_ontologyHandler(
            new handler_type(
                faceted,
                &FacetedController::set_ontology
            )
        );

        router.map(
            controllerName,
            "set_ontology",
            set_ontologyHandler.get()
        );
        set_ontologyHandler.release();

        handler_ptr static_clickHandler(
            new handler_type(
                faceted,
                &FacetedController::static_click
            )
        );

        router.map(
            controllerName,
            "static_click",
            static_clickHandler.get()
        );
        static_clickHandler.release();
    }

    {
        TopicController topic;
        const std::string controllerName("topic");
        typedef ::izenelib::driver::ActionHandler<TopicController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr get_in_date_rangeHandler(
            new handler_type(
                topic,
                &TopicController::get_in_date_range
            )
        );

        router.map(
            controllerName,
            "get_in_date_range",
            get_in_date_rangeHandler.get()
        );
        get_in_date_rangeHandler.release();

        handler_ptr get_similarHandler(
            new handler_type(
                topic,
                &TopicController::get_similar
            )
        );

        router.map(
            controllerName,
            "get_similar",
            get_similarHandler.get()
        );
        get_similarHandler.release();

        handler_ptr get_temporal_similarHandler(
            new handler_type(
                topic,
                &TopicController::get_temporal_similar
            )
        );

        router.map(
            controllerName,
            "get_temporal_similar",
            get_temporal_similarHandler.get()
        );
        get_temporal_similarHandler.release();
    }

    {
        RecommendController recommend;
        const std::string controllerName("recommend");
        typedef ::izenelib::driver::ActionHandler<RecommendController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr add_userHandler(
            new handler_type(
                recommend,
                &RecommendController::add_user
            )
        );

        router.map(
            controllerName,
            "add_user",
            add_userHandler.get()
        );
        add_userHandler.release();

        handler_ptr do_recommendHandler(
            new handler_type(
                recommend,
                &RecommendController::do_recommend
            )
        );

        router.map(
            controllerName,
            "do_recommend",
            do_recommendHandler.get()
        );
        do_recommendHandler.release();

        handler_ptr get_userHandler(
            new handler_type(
                recommend,
                &RecommendController::get_user
            )
        );

        router.map(
            controllerName,
            "get_user",
            get_userHandler.get()
        );
        get_userHandler.release();

        handler_ptr purchase_itemHandler(
            new handler_type(
                recommend,
                &RecommendController::purchase_item
            )
        );

        router.map(
            controllerName,
            "purchase_item",
            purchase_itemHandler.get()
        );
        purchase_itemHandler.release();

        handler_ptr rate_itemHandler(
            new handler_type(
                recommend,
                &RecommendController::rate_item
            )
        );

        router.map(
            controllerName,
            "rate_item",
            rate_itemHandler.get()
        );
        rate_itemHandler.release();

        handler_ptr remove_userHandler(
            new handler_type(
                recommend,
                &RecommendController::remove_user
            )
        );

        router.map(
            controllerName,
            "remove_user",
            remove_userHandler.get()
        );
        remove_userHandler.release();

        handler_ptr top_item_bundleHandler(
            new handler_type(
                recommend,
                &RecommendController::top_item_bundle
            )
        );

        router.map(
            controllerName,
            "top_item_bundle",
            top_item_bundleHandler.get()
        );
        top_item_bundleHandler.release();

        handler_ptr track_eventHandler(
            new handler_type(
                recommend,
                &RecommendController::track_event
            )
        );

        router.map(
            controllerName,
            "track_event",
            track_eventHandler.get()
        );
        track_eventHandler.release();

        handler_ptr update_shopping_cartHandler(
            new handler_type(
                recommend,
                &RecommendController::update_shopping_cart
            )
        );

        router.map(
            controllerName,
            "update_shopping_cart",
            update_shopping_cartHandler.get()
        );
        update_shopping_cartHandler.release();

        handler_ptr update_userHandler(
            new handler_type(
                recommend,
                &RecommendController::update_user
            )
        );

        router.map(
            controllerName,
            "update_user",
            update_userHandler.get()
        );
        update_userHandler.release();

        handler_ptr visit_itemHandler(
            new handler_type(
                recommend,
                &RecommendController::visit_item
            )
        );

        router.map(
            controllerName,
            "visit_item",
            visit_itemHandler.get()
        );
        visit_itemHandler.release();
    }

    {
        ServiceController service;
        const std::string controllerName("service");
        typedef ::izenelib::driver::ActionHandler<ServiceController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr process_overdueHandler(
            new handler_type(
                service,
                &ServiceController::process_overdue
            )
        );

        router.map(
            controllerName,
            "process_overdue",
            process_overdueHandler.get()
        );
        process_overdueHandler.release();

        handler_ptr renewHandler(
            new handler_type(
                service,
                &ServiceController::renew
            )
        );

        router.map(
            controllerName,
            "renew",
            renewHandler.get()
        );
        renewHandler.release();
    }

    {
        ProductController product;
        const std::string controllerName("product");
        typedef ::izenelib::driver::ActionHandler<ProductController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr add_new_groupHandler(
            new handler_type(
                product,
                &ProductController::add_new_group
            )
        );

        router.map(
            controllerName,
            "add_new_group",
            add_new_groupHandler.get()
        );
        add_new_groupHandler.release();

        handler_ptr append_to_groupHandler(
            new handler_type(
                product,
                &ProductController::append_to_group
            )
        );

        router.map(
            controllerName,
            "append_to_group",
            append_to_groupHandler.get()
        );
        append_to_groupHandler.release();

        handler_ptr get_multi_price_historyHandler(
            new handler_type(
                product,
                &ProductController::get_multi_price_history
            )
        );

        router.map(
            controllerName,
            "get_multi_price_history",
            get_multi_price_historyHandler.get()
        );
        get_multi_price_historyHandler.release();

        handler_ptr get_top_price_cut_listHandler(
            new handler_type(
                product,
                &ProductController::get_top_price_cut_list
            )
        );

        router.map(
            controllerName,
            "get_top_price_cut_list",
            get_top_price_cut_listHandler.get()
        );
        get_top_price_cut_listHandler.release();

        handler_ptr migrate_price_historyHandler(
            new handler_type(
                product,
                &ProductController::migrate_price_history
            )
        );

        router.map(
            controllerName,
            "migrate_price_history",
            migrate_price_historyHandler.get()
        );
        migrate_price_historyHandler.release();

        handler_ptr remove_from_groupHandler(
            new handler_type(
                product,
                &ProductController::remove_from_group
            )
        );

        router.map(
            controllerName,
            "remove_from_group",
            remove_from_groupHandler.get()
        );
        remove_from_groupHandler.release();

        handler_ptr update_a_docHandler(
            new handler_type(
                product,
                &ProductController::update_a_doc
            )
        );

        router.map(
            controllerName,
            "update_a_doc",
            update_a_docHandler.get()
        );
        update_a_docHandler.release();
    }

    {
        SynonymController synonym;
        const std::string controllerName("synonym");
        typedef ::izenelib::driver::ActionHandler<SynonymController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr add_synonymHandler(
            new handler_type(
                synonym,
                &SynonymController::add_synonym
            )
        );

        router.map(
            controllerName,
            "add_synonym",
            add_synonymHandler.get()
        );
        add_synonymHandler.release();

        handler_ptr delete_synonymHandler(
            new handler_type(
                synonym,
                &SynonymController::delete_synonym
            )
        );

        router.map(
            controllerName,
            "delete_synonym",
            delete_synonymHandler.get()
        );
        delete_synonymHandler.release();

        handler_ptr update_synonymHandler(
            new handler_type(
                synonym,
                &SynonymController::update_synonym
            )
        );

        router.map(
            controllerName,
            "update_synonym",
            update_synonymHandler.get()
        );
        update_synonymHandler.release();
    }

    {
        CollectionController collection;
        const std::string controllerName("collection");
        typedef ::izenelib::driver::ActionHandler<CollectionController> handler_type;
        typedef std::auto_ptr<handler_type> handler_ptr;

        handler_ptr create_collectionHandler(
            new handler_type(
                collection,
                &CollectionController::create_collection
            )
        );

        router.map(
            controllerName,
            "create_collection",
            create_collectionHandler.get()
        );
        create_collectionHandler.release();

        handler_ptr delete_collectionHandler(
            new handler_type(
                collection,
                &CollectionController::delete_collection
            )
        );

        router.map(
            controllerName,
            "delete_collection",
            delete_collectionHandler.get()
        );
        delete_collectionHandler.release();

        handler_ptr get_kvHandler(
            new handler_type(
                collection,
                &CollectionController::get_kv
            )
        );

        router.map(
            controllerName,
            "get_kv",
            get_kvHandler.get()
        );
        get_kvHandler.release();

        handler_ptr rebuild_collectionHandler(
            new handler_type(
                collection,
                &CollectionController::rebuild_collection
            )
        );

        router.map(
            controllerName,
            "rebuild_collection",
            rebuild_collectionHandler.get()
        );
        rebuild_collectionHandler.release();

        handler_ptr set_kvHandler(
            new handler_type(
                collection,
                &CollectionController::set_kv
            )
        );

        router.map(
            controllerName,
            "set_kv",
            set_kvHandler.get()
        );
        set_kvHandler.release();

        handler_ptr start_collectionHandler(
            new handler_type(
                collection,
                &CollectionController::start_collection
            )
        );

        router.map(
            controllerName,
            "start_collection",
            start_collectionHandler.get()
        );
        start_collectionHandler.release();

        handler_ptr stop_collectionHandler(
            new handler_type(
                collection,
                &CollectionController::stop_collection
            )
        );

        router.map(
            controllerName,
            "stop_collection",
            stop_collectionHandler.get()
        );
        stop_collectionHandler.release();
    }

}

} // namespace sf1r

