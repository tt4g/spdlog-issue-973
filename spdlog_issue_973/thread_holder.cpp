#include "thread_holder.hpp"

#include "thread_holder_internal.hpp"

namespace spdlog_issue_973
{

thread_holder::thread_holder()
{
    this->internal = std::make_unique<thread_holder_internal>();
}

thread_holder::~thread_holder()
{

}

thread_holder *thread_holder::instance()
{
    static thread_holder holder{};
	return &holder;
}

} // namespace spdlog_issue_973
