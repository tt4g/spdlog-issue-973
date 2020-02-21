#ifndef SPDLOG_ISSUE_973_THREAD_HOLDER_HPP
#define SPDLOG_ISSUE_973_THREAD_HOLDER_HPP

#include "thread_holder_export.hpp"

#include <memory>

namespace spdlog_issue_973
{

class thread_holder_internal;

class SPDLOG_ISSUE_973_API thread_holder
{
public:

    ~thread_holder();

    thread_holder(const thread_holder&) = delete;

    thread_holder(thread_holder&&) = delete;

    static thread_holder *instance();

    thread_holder& operator=(thread_holder&) = delete;

    thread_holder& operator=(thread_holder&&) = delete;

private:

    thread_holder();

    std::unique_ptr<thread_holder_internal> internal;

};

} // namespace spdlog_issue_973

#endif // SPDLOG_ISSUE_973_THREAD_HOLDER_HPP
