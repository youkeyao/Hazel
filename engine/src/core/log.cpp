#include "core/log.h"

namespace hazel {

    std::shared_ptr<spdlog::logger> Log::ms_core_logger;
    std::shared_ptr<spdlog::logger> Log::ms_client_logger;

    void Log::init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%$");
        ms_core_logger = spdlog::stdout_color_mt("HAZEL");
        ms_core_logger->set_level(spdlog::level::trace);
        ms_client_logger = spdlog::stdout_color_mt("APP");
        ms_client_logger->set_level(spdlog::level::trace);
    }

}