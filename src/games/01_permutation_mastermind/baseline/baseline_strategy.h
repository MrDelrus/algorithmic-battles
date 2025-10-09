#include "../../../testing/interfaces/strategy.h"
#include <vector>
#include <random>
#include <sstream>

class PermutationMastermindBaselineStrategy : public testing::interfaces::IStrategy {
public:
    void Init(const std::string& input) override;
    std::string Request() override;
    void Receive(const std::string& observation) override;
private:
    int64_t permutationLength;
    std::vector<int64_t> permutation;
    std::vector<bool> isMatched;
    std::random_device rnd;
    int64_t indexFirst;
    int64_t indexSecond;
    int64_t previousMatchedCount;
};
