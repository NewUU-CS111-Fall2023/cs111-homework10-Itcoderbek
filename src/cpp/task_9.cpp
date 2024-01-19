#include <iostream>
#include <vector>
#include <unordered_set>

bool isSatisfied(const std::vector<std::vector<int>>& formula, const std::unordered_set<int>& truthAssignment) {
    for (const auto& clause : formula) {
        bool clauseSatisfied = false;

        for (int literal : clause) {
            int variable = abs(literal);
            bool isNegated = literal < 0;

            if (truthAssignment.count(variable) == 1) {
                // Variable is assigned a truth value
                if ((truthAssignment.find(variable)->second && !isNegated) ||
                    (!truthAssignment.find(variable)->second && isNegated)) {
                    clauseSatisfied = true;
                    break;
                }
            }
        }

        if (!clauseSatisfied) {
            return false;  // At least one clause is not satisfied
        }
    }

    return true;  // All clauses are satisfied
}

int main() {
    // Example usage:
    std::vector<std::vector<int>> formula = {{1, 2, -3}, {-1, -2, 3}, {4, 5, -6}};
    std::unordered_set<int> truthAssignment = {{1, true}, {2, false}, {3, false}, {4, true}, {5, false}, {6, true}};

    if (isSatisfied(formula, truthAssignment)) {
        std::cout << "The formula is satisfied by the truth assignment." << std::endl;
    } else {
        std::cout << "The formula is not satisfied by the truth assignment." << std::endl;
    }

    return 0;
}
