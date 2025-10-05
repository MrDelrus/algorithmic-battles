#include "interactor.h"

PermutationMastermindInteractor::PermutationMastermindInteractor(int64_t size)
    : roundsCounter_(0)
    , verdict_(testing::Result::Testing)
    , permutation_(size)
{
    std::iota(permutation_.begin(), permutation_.end(), 0);
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(permutation_.begin(), permutation_.end(), rng);
}

std::string PermutationMastermindInteractor::Request() {
    return std::to_string(matches_);
}

void PermutationMastermindInteractor::Receive(const std::string& observation) {
    ++roundsCounter_;
    if (roundsCounter_ > permutation_.size() * permutation_.size() * permutation_.size()) {
        verdict_ = testing::Result::QueryLimit;
    }
    response_ = observation;
    std::istringstream istr(response_);
    std::string type;
    if (!(istr >> type) || type != "!" && type != "?") {
        verdict_ = testing::Result::PresentationError;
        return;
    }
    std::vector<int64_t> guess(permutation_.size());
    std::vector<bool> used(permutation_.size(), false);
    matches_ = 0;
    for (size_t index = 0; index < permutation_.size(); ++index) {
        int64_t input;
        if (istr >> input) {
            if (input >= permutation_.size() || input < 0 || used[input]) {
                verdict_ = testing::Result::PresentationError;
                return;
            }
            if (input == permutation_[index]) {
                ++matches_;
            }
            used[input] = true;
        } else {
            verdict_ = testing::Result::PresentationError;
            return;
        }
        guess[index] = input;
    }
    std::string leftover;
    if (istr >> leftover) {
        verdict_ = testing::Result::PresentationError;
        return;
    }
    if (type == "!") {
        if (matches_ == permutation_.size()) {
            verdict_ = testing::Result::Accepted;
        } else {
            verdict_ = testing::Result::WrongAnswer;
        }
    }
}

bool PermutationMastermindInteractor::IsFinished() const {
    return verdict_ != testing::Result::Testing;
}

testing::Result PermutationMastermindInteractor::GetVerdict() const {
    return verdict_;
}


int64_t PermutationMastermindInteractor::ComputeScore() const {
    return roundsCounter_;
}
