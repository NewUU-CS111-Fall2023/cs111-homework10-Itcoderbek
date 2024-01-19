#include <iostream>
#include <vector>

// Function to check if a truth assignment satisfies the CNF formula
bool isSatisfied(const std::vector<std::vector<int>>& cnf_formula, const std::vector<bool>& assignment) {
    for (const auto& clause : cnf_formula) {
        bool clauseSatisfied = false;

        for (int literal : clause) {
            int variable = abs(literal);
            bool isNegated = literal < 0;

            // Check if the literal is satisfied based on the assignment
            if ((assignment[variable - 1] && !isNegated) || (!assignment[variable - 1] && isNegated)) {
                clauseSatisfied = true;
                break;
            }
        }

        if (!clauseSatisfied) {
            return false;  // At least one clause is not satisfied
        }
    }

    return true;  // All clauses are satisfied
}

// Function to generate all possible truth assignments for a given number of variables
std::vector<std::vector<bool>> generateAllAssignments(int numVariables) {
    std::vector<std::vector<bool>> allAssignments;

    for (int i = 0; i < (1 << numVariables); ++i) {
        std::vector<bool> assignment;

        for (int j = 0; j < numVariables; ++j) {
            assignment.push_back((i & (1 << j)) != 0);
        }

        allAssignments.push_back(assignment);
    }

    return allAssignments;
}

// Function to solve SAT problems using brute force
bool solveSATBruteForce(const std::vector<std::vector<int>>& cnf_formula) {
    int numVariables = 0;

    // Find the maximum variable in the CNF formula
    for (const auto& clause : cnf_formula) {
        for (int literal : clause) {
            int variable = abs(literal);
            numVariables = std::max(numVariables, variable);
        }
    }

    // Generate all possible truth assignments for the variables
    std::vector<std::vector<bool>> allAssignments = generateAllAssignments(numVariables);

    // Check each truth assignment
    for (const auto& assignment : allAssignments) {
        if (isSatisfied(cnf_formula, assignment)) {
            return true;  // Found a satisfying assignment
        }
    }

    return false;  // No satisfying assignment found
}

int main() {
    // Example usage:
    std::vector<std::vector<int>> cnf_formula = {{1, 2, -3}, {-1, -2, 3}, {2, -3}};

    if (solveSATBruteForce(cnf_formula)) {
        std::cout << "The CNF formula is satisfiable." << std::endl;
    } else {
        std::cout << "The CNF formula is not satisfiable." << std::endl;
    }

    return 0;
}
