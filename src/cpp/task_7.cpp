#include <iostream>
#include <vector>
#include <unordered_map>

int minRabbits(std::vector<int>& answers) {
    std::unordered_map<int, int> count; // Count of rabbits with a particular color
    int result = 0;

    for (int ans : answers) {
        // If we haven't seen this color before or the count exceeds the answer,
        // consider a new clique for this color
        if (count[ans] == 0) {
            result += ans + 1; // Size of the new clique
            count[ans] = ans;
        } else {
            count[ans]--; // Decrease the count within the current clique
        }
    }

    return result;
}

int main() {
    // Example usage:
    std::vector<int> answers = {1, 1, 2};
    int result = minRabbits(answers);

    std::cout << "Minimum number of rabbits in the forest: " << result << std::endl;

    return 0;
}
