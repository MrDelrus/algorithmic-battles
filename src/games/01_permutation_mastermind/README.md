# Permutation Mastermind

Welcome to the first game of our cycle!

This game is pretty simple and is supposed to set-up the environment.

## Rules:

`Interactor` secretly chose a permutation `p`, which you need to guess. You can choose any permutation `q` and make one of two following queries: 

- `? q(0) q(1) q(2) ... q(n - 1)`

`Interactor` will compute the number of positions where `p` and `q` match and return this value.

- `! q(0) q(1) q(2) ... q(n - 1)`

`Interactor` will compare given permutation to `p`. If you guessed correctly, you won! But be careful - you have only one attempt to send such query.

## API:

You must implement three methods (C++-syntax is used).

- `void Init(const std::string& permutationLength)` - receives length of unknown permutation
- `std::string Request()` - returns your request
- `void Receive(const std::string& observation)` - receives response from the `Interactor`

In each match `Init` is called exactly once in the beginning, then `Request` and `Receive` are called alternatingly until match finishes.

Possible outcomes:

- Accepted
- WrongAnswer
- PresentationError
- QueryLimit

You can see `Interactor` [implementation](interactor.cpp) to get the details of these errors. As you can notice, this game is not infinite - you have a limit of `n^3` queries.

Example of the correct interaction:

- `p = [0, 2, 1]` is chosen
- Call `Init("3")`
- Call `Request()`, strategy returns `"? 2 0 1"`
- Call `Receive("1")`.
- Call `Request()`, strategy returns `"? 2 1 0"`
- Call `Receive("0")`.
- Call `Request()`, strategy returns `"? 0 2 1"`
- Call `Receive("3")`.
- Call `Request()`, strategy returns `"! 0 2 1"`

Guess is correct, match is over. Final score (number of rounds): 4.

## Submission format

Implement both `strategy.*` files and send them. You can test it locally using [test_basic.cpp](submission/test_basic.cpp). This game is chosen to set up environment for the future, so feel free to ask the questions.

## Project structure

- `baseline/` - baseline strategy, will be pushed in the middle of the competition
- `submission/` - contains example of local testing before submission
- `interactor.*` - interactor implementation for local testing 
- `strategy.h` - interface for your strategy class
- `strategy.cpp` - template for your implementation

## Evaluation

Random 100 permutations of length 100 are chosen.

Each strategy will be tested on these permutations (permutations are the same for all the strategies). If strategy fails more than 10 times, it's not included in final leaderboard.

For each permutation we calculate number of rounds, guess is included. We exclude 10 best and 10 worst attempts. Final score - RMSE of 80 other attempts.

## Local testing

The easiest way to test this is to use `CMakeLists.txt`. Get back to the project folder and run the following sequence:

```
rm -rf build
mkdir build && cd build
cmake ..
make -j
./test_01_permutation_mastermind 
```

## Acknowledgements

Special thanks to [Alexander](https://github.com/GregTag) for testing assistance and valuable feedback.
