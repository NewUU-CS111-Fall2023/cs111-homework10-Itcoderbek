#include <iostream>
#include <vector>

bool canPartition(std::vector<int>& nums) {
    int totalSum = 0;
    
    for (int num : nums) {
        totalSum += num;
    }
    
    // If the total sum is odd, it's not possible to divide the array into two subsets with equal sums
    if (totalSum % 2 != 0) {
        return false;
    }

    int targetSum = totalSum / 2;
    int n = nums.size();
    
    // dp[i][j] is true if there is a subset of elements from nums[0...i] with sum equal to j
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(targetSum + 1, false));

    // Initializing base case
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Filling the dp table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= targetSum; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= nums[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    return dp[n][targetSum];
}

int main() {
    // Example usage:
    std::vector<int> nums = {1, 5, 11, 5};

    if (canPartition(nums)) {
        std::cout << "It is possible to partition the array into two subsets with equal sums." << std::endl;
    } else {
        std::cout << "It is not possible to partition the array into two subsets with equal sums." << std::endl;
    }

    return 0;
}
