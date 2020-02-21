#ifndef SPDLOG_ISSUE_973_THREAD_HOLDER_INTERNAL_HPP
#define SPDLOG_ISSUE_973_THREAD_HOLDER_INTERNAL_HPP

#include "thread_holder_export.hpp"

#include "spdlog/spdlog.h"
#include "spdlog/async.h"

#include <memory>

namespace spdlog_issue_973
{

class thread_holder_internal
{
public:

    thread_holder_internal();

    ~thread_holder_internal();

    thread_holder_internal(const thread_holder_internal&) = delete;

    thread_holder_internal(thread_holder_internal&&) = delete;

    thread_holder_internal& operator=(thread_holder_internal&) = delete;

    thread_holder_internal& operator=(thread_holder_internal&&) = delete;

private:

    std::shared_ptr<spdlog::sinks::sink> io_sink;

    std::shared_ptr<spdlog::logger> io_logger;

    std::shared_ptr<spdlog::details::thread_pool> thread_pool;

};

} // namespace spdlog_issue_973

#endif // SPDLOG_ISSUE_973_THREAD_HOLDER_INTERNAL_HPP
