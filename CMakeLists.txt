cmake_minimum_required(VERSION 3.15)
project(AlgorithmicBattles LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SRC
    src/games/01_permutation_mastermind/submission/test_basic.cpp
    src/games/01_permutation_mastermind/interactor.cpp
    src/games/01_permutation_mastermind/strategy.cpp
    src/testing/judge.cpp
)

add_executable(test_01_permutation_mastermind ${SRC})
