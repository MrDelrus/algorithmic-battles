#include <iostream>
#include "../interactor.h"
#include "../strategy.h"
#include "../../../testing/judge.h"

int main() {
    int64_t permutationLength = 3;
    PermutationMastermindStrategy strategy;
    PermutationMastermindInteractor interactor(permutationLength);
    if (auto [result, score] = testing::RunMatch(strategy, interactor, std::to_string(permutationLength)); result) {
        std::cout << "Guessed after " << score << " rounds!\n";
    } else {
        std::cout << "Failed! Try again.\n";
    }
}
