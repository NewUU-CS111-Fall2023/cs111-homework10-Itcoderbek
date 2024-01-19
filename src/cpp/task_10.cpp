#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

std::vector<std::vector<int>> generate3SATFormula(int numVariables, int numClauses) {
    std::vector<std::vector<int>> formula;

    srand(static_cast<unsigned>(time(0))); // Seed the random number generator

    for (int i = 0; i < numClauses; ++i) {
        std::vector<int> clause;
        for (int j = 0; j < 3; ++j) {
            int variable = rand() % numVariables + 1; // Random variable between 1 and numVariables
            int negation = rand() % 2; // Randomly choose whether to negate the variable

            if (negation == 1) {
                variable *= -1; // Negate the variable
            }

            clause.push_back(variable);
        }

        formula.push_back(clause);
    }

    return formula;
}

int main() {
    // Example usage:
    int numVariables = 5;
    int numClauses = 10;

    std::vector<std::vector<int>> formula = generate3SATFormula(numVariables, numClauses);

    // Display the generated 3-SAT formula
    std::cout << "Generated 3-SAT formula:" << std::endl;
    for (const auto& clause : formula) {
        for (int literal : clause) {
            std::cout << literal << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
