#pragma once
#include <string>

namespace testing::interfaces {

class IStrategy {
public:
    virtual ~IStrategy() = default;
    virtual void Init(const std::string& input) = 0;
    virtual std::string Request() = 0;
    virtual void Receive(const std::string& observation) = 0;
};

}  // testing
