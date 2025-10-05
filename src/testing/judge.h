#pragma once
#include <string>
#include <stdexcept>
#include "interfaces/strategy.h"
#include "interfaces/interactor.h"

namespace testing {

std::pair<bool, int64_t> RunMatch(
    interfaces::IStrategy& strategy,
    interfaces::IInteractor& interactor,
    const std::string& input
);

}  // namespace testing
