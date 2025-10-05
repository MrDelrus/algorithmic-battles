#pragma once
#include <vector>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <random>
#include "../../testing/interfaces/interactor.h"

class PermutationMastermindInteractor : public testing::interfaces::IInteractor {
public:
    PermutationMastermindInteractor(int64_t size);
    std::string Request() override;
    void Receive(const std::string& observation) override;
    bool IsFinished() const override;
    testing::Result GetVerdict() const override;
    int64_t ComputeScore() const override;
private:
    int64_t roundsCounter_;
    testing::Result verdict_;
    std::vector<int64_t> permutation_;
    std::string response_;
    int64_t matches_;
};
