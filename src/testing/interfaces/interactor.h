#pragma once
#include <string>
#include "../verdicts.h"

namespace testing::interfaces {

class IInteractor {
public:
    virtual ~IInteractor() = default;
    virtual std::string Request() = 0;
    virtual void Receive(const std::string& observation) = 0;
    virtual bool IsFinished() const = 0;
    virtual Result GetVerdict() const = 0;
    virtual int64_t ComputeScore() const = 0;
};

}  // testing
