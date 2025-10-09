#include "baseline_strategy.h"

void PermutationMastermindBaselineStrategy::Init(const std::string& input) {
    std::istringstream istr(input);
    istr >> permutationLength;
    permutation.resize(permutationLength);
    std::iota(permutation.begin(), permutation.end(), 0);
    isMatched.assign(permutationLength, false);
    previousMatchedCount = -3;
}

std::string PermutationMastermindBaselineStrategy::Request() {
    std::ostringstream out;

    std::vector<int64_t> indices;
    for (int64_t index = 0; index < permutationLength; ++index) {
        if (!isMatched[index]) indices.push_back(index);
    }
    if (indices.empty()) {
        out << '!';
    } else {
        out << '?';
        std::uniform_int_distribution<size_t> da(0, indices.size() - 1);
        indexFirst = da(rnd);
        std::uniform_int_distribution<size_t> db(1, indices.size() - 1);
        indexSecond = (indexFirst + db(rnd)) % indices.size();
        std::swap(permutation[indices[indexFirst]], permutation[indices[indexSecond]]);
        indexFirst = indices[indexFirst];
        indexSecond = indices[indexSecond];
    }
    for (auto number : permutation) {
        out << ' ' << number;
    }
    return out.str();
}

void PermutationMastermindBaselineStrategy::Receive(const std::string& observation) {
    int64_t matchedCount = std::stoll(observation);
    if (matchedCount == permutationLength) {
        for (size_t index = 0; index < permutationLength; ++index) {
            isMatched[index] = true;
        }
        return;
    }
    if (matchedCount < previousMatchedCount) {
        std::swap(permutation[indexFirst], permutation[indexSecond]);
    }
    if (abs(matchedCount - previousMatchedCount) == 2) {
        isMatched[indexFirst] = true;
        isMatched[indexSecond] = true;
    }
    previousMatchedCount = std::max(matchedCount, previousMatchedCount);
}
