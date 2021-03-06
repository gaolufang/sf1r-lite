#ifndef SF1R_CORRECTION_ENGINE_WRAPPER_H
#define SF1R_CORRECTION_ENGINE_WRAPPER_H

#include "CorrectionEngine.h"

namespace sf1r
{
class CorrectionEngineWrapper : public boost::noncopyable
{
public:
    CorrectionEngineWrapper();
    ~CorrectionEngineWrapper();
    static CorrectionEngineWrapper& getInstance();

public:
    bool correct(const std::string& userQuery, std::string& results, double& freq );
    void evaluate(std::string& stream);
    void rebuild();
public:
    static std::string system_resource_path_;
    static std::string system_working_path_;

private:
    Recommend::CorrectionEngine* engine_;
    boost::shared_mutex mtx_;
};
}

#endif
