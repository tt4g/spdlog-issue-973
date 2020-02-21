#include "thread_holder_internal.hpp"

#include "spdlog/sinks/null_sink.h"

namespace spdlog_issue_973
{

thread_holder_internal::thread_holder_internal()
{
    this->io_sink = std::make_shared<spdlog::sinks::null_sink_mt>();
    this->thread_pool = std::make_shared<spdlog::details::thread_pool>(128, 1);
    this->io_logger =
            std::make_shared<spdlog::async_logger>("sg_global",
                                                   this->io_sink,
                                                   this->thread_pool,
                                                   spdlog::async_overflow_policy::block);
}

thread_holder_internal::~thread_holder_internal()
{
    this->io_logger->flush();
}

} // namespace spdlog_issue_973
