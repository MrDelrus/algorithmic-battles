#include "interactor.h"

PermutationMastermindInteractor::PermutationMastermindInteractor(int64_t size)
    : roundsCounter(0)
    , verdict(testing::Result::TESTING)
    , permutation(size)
{
    std::iota(permutation.begin(), permutation.end(), 0);
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(permutation.begin(), permutation.end(), rng);
}

std::string PermutationMastermindInteractor::Request() {
    return std::to_string(matchedCount);
}

void PermutationMastermindInteractor::Receive(const std::string& observation) {
    ++roundsCounter;
    if (roundsCounter > permutation.size() * permutation.size() * permutation.size()) {
        verdict = testing::Result::QUERY_LIMIT;
    }
    response = observation;
    std::istringstream istr(response);
    std::string type;
    if (!(istr >> type) || type != "!" && type != "?") {
        verdict = testing::Result::PRESENTATION_ERROR;
        return;
    }
    std::vector<int64_t> guess(permutation.size());
    std::vector<bool> used(permutation.size(), false);
    matchedCount = 0;
    for (size_t index = 0; index < permutation.size(); ++index) {
        int64_t input;
        if (istr >> input) {
            if (input >= permutation.size() || input < 0 || used[input]) {
                verdict = testing::Result::PRESENTATION_ERROR;
                return;
            }
            if (input == permutation[index]) {
                ++matchedCount;
            }
            used[input] = true;
        } else {
            verdict = testing::Result::PRESENTATION_ERROR;
            return;
        }
        guess[index] = input;
    }
    std::string leftover;
    if (istr >> leftover) {
        verdict = testing::Result::PRESENTATION_ERROR;
        return;
    }
    if (type == "!") {
        if (matchedCount == permutation.size()) {
            verdict = testing::Result::ACCEPTED;
        } else {
            verdict = testing::Result::WRONG_ANSWER;
        }
    }
}

bool PermutationMastermindInteractor::IsFinished() const {
    return verdict != testing::Result::TESTING;
}

testing::Result PermutationMastermindInteractor::GetVerdict() const {
    return verdict;
}


int64_t PermutationMastermindInteractor::ComputeScore() const {
    return roundsCounter;
}
