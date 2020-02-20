#include <spdlog/spdlog.h>
#include <spdlog/async.h>

#include <memory>

class IO {
public:
    IO () {
        thread_pool = std::make_shared<spdlog::details::thread_pool>(128, 1);
    }

private:
        std::shared_ptr<spdlog::details::thread_pool> thread_pool;
};

class Env {
public:
    static Env* instance() {
        static Env env {};
        return &env;
    }
private:
    Env::Env() {
        io = std::make_unique<IO>();
    }
private:
    std::unique_ptr<IO> io;
};

int main(int argc, char** argv) {
    auto env = Env::instance();

    return 0;
}
