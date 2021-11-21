#pragma once

#include <chrono>
#include <iostream>
#include <string>

class LogDuration {
public:
    explicit LogDuration(const std::string& msg = "")
        : message(msg + ": ")
        //, start(steady_clock::now())
        , start(std::chrono::high_resolution_clock::now())
    {
    }

    ~LogDuration() {
        //auto finish = steady_clock::now();
        auto finish = std::chrono::high_resolution_clock::now();
        auto dur = finish - start;
        std::cerr << message
            << std::chrono::duration_cast<std::chrono::milliseconds>(dur).count()
            << "ms" << std::endl;
    }
private:
    std::string message;
    std::chrono::high_resolution_clock::time_point start;
};

#define UNIQ_ID_IMPL(lineno) _a_local_var_##lineno
#define UNIQ_ID(lineno) UNIQ_ID_IMPL(lineno)

#define LOG_DURATION(message) \
  LogDuration UNIQ_ID(__LINE__){message};

