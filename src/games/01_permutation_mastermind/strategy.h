#pragma once
#include <string>
#include <stdexcept>
#include "../../testing/interfaces/strategy.h"

class PermutationMastermindStrategy : public testing::interfaces::IStrategy {
public:
    void Init(const std::string& input) override;
    std::string Request() override;
    void Receive(const std::string& observation) override;
};
