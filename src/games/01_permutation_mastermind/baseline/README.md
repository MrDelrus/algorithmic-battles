# Baseline Strategy Description

We start with the permutation [0, 1, 2, ..., n - 1]. The main idea is to perform random transpositions until we guess the entire permutation correctly.

This approach performs very poorly on its own, so we add an improvement: if the number of matches changes by exactly two, we know the positions of those elements. We can then fix them permanently and no longer include them in random transpositions.

The implementation of this strategy is provided in the file [baseline_strategy.cpp](baseline_strategy.cpp).
