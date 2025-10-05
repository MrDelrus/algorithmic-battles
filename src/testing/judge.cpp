#include "judge.h"
#include <string>

namespace testing {

std::pair<bool, int64_t> RunMatch(
    interfaces::IStrategy& strategy,
    interfaces::IInteractor& interactor,
    const std::string& input
)
{
    strategy.Init(input);
    std::string strategyMessage;
    std::string interactorMessage;
    do {
        strategyMessage = strategy.Request();
        interactor.Receive(strategyMessage);
        interactorMessage = interactor.Request();
        strategy.Receive(interactorMessage);
    } while (!interactor.IsFinished());

    auto verdict = interactor.GetVerdict();
    if (verdict == Result::TESTING) {
        throw std::runtime_error("Interactor made a verdict before finishing testing. Implementation error!");
    }
    if (verdict != Result::ACCEPTED) {
        return {false, 0};
    }
    int64_t score = interactor.ComputeScore();
    return {true, score};
}

}  // namespace testing
