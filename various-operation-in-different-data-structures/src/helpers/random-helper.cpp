#include "random-helper.h"
#include "random"
#include "vector"
#include "algorithm"

std::vector<int> RandomHelper::get_n_unique_random_numbers(int n) {
    std::vector<int> numbers;
    numbers.reserve(n);

    for (int i = 0; i < n; i++) {
        numbers.push_back(i);
    }

    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::shuffle(numbers.begin(), numbers.end(), generator);

    return numbers;
}