#include "spdlog_issue_973/thread_holder.hpp"

int main(int argc, char** argv) {
    auto holder = spdlog_issue_973::thread_holder::instance();

    return 0;
}
