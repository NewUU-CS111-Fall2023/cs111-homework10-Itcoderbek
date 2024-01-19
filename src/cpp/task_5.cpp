#include <iostream>
#include <vector>
#include <algorithm>

bool hasZeroSumTriplet(const std::vector<int>& nums) {
    int n = nums.size();

    // Sort the array to use the two-pointer approach
    std::vector<int> sortedNums = nums;
    std::sort(sortedNums.begin(), sortedNums.end());

    for (int i = 0; i < n - 2; ++i) {
        // Fix the first element as nums[i]
        int target = -sortedNums[i];
        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int currentSum = sortedNums[left] + sortedNums[right];

            if (currentSum == target) {
                // Triplet found
                return true;
            } else if (currentSum < target) {
                // Move the left pointer to increase the sum
                ++left;
            } else {
                // Move the right pointer to decrease the sum
                --right;
            }
        }
    }

    // No distinct triplet with sum zero found
    return false;
}

int main() {
    std::vector<int> numbers = {1, -2, 1, 0, 5, -1};

    if (hasZeroSumTriplet(numbers)) {
        std::cout << "The set contains a distinct triplet whose sum equals zero.\n";
    } else {
        std::cout << "No distinct triplet with sum zero found in the set.\n";
    }

    return 0;
}
