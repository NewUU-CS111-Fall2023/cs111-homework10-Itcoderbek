#include <iostream>
#include <string>

// Define the states of the Turing machine
enum State {
    Q0,  // Initial state, move right to find the first 0 in the first number
    Q1,  // Move right to find the second 0 in the first number
    Q2,  // Move right to reach the end of the first number
    Q3,  // Move left to go back to the second 0 in the first number
    Q4,  // Move left to reach the start of the first number
    Q5,  // Move right to find the first 0 in the second number
    Q6,  // Move right to find the second 0 in the second number
    Q7,  // Move right to reach the end of the second number
    Q8,  // Move left to go back to the second 0 in the second number
    Q9,  // Move left to reach the start of the second number
    Q10, // Move right to find the next 0 in the result
    Q11, // Move right to reach the end of the result (output)
    QAccept, // Accept state
    QReject  // Reject state
};

// Function to simulate unary comparison using a Turing machine
void unaryComparison(std::string& tape) {
    State currentState = Q0;

    while (currentState != QAccept && currentState != QReject) {
        char symbol = tape[tape.size() / 2];

        switch (currentState) {
            // State transitions for finding the first 0 in the first number
            case Q0:
                if (symbol == '0') {
                    currentState = Q1;
                } else {
                    tape[tape.size() / 2] = '_';
                    ++tape.size();
                }
                break;

            // State transitions for finding the second 0 in the first number
            case Q1:
                if (symbol == '0') {
                    currentState = Q2;
                } else {
                    tape[tape.size() / 2] = '_';
                    ++tape.size();
                }
                break;

            // Add more states for the rest of the comparison process
          
            default:
                currentState = QReject;
                break;
        }

        // Move the tape head
        if (currentState != QAccept && currentState != QReject) {
            if (currentState == Q3 || currentState == Q4 || currentState == Q8) {
                tape[tape.size() / 2] = '_'; // Move left
                --tape.size();
            } else {
                tape[tape.size() / 2] = '_'; // Move right
                ++tape.size();
            }
        }
    }

    // Print the result
    if (currentState == QAccept) {
        std::cout << "Output: " << tape << std::endl;
    } else {
        std::cout << "Rejected!" << std::endl;
    }
}

int main() {
    // Example input: "1110_1111_1111" (7 vs 6 in unary)
    std::string tape = "111011111111";
    unaryComparison(tape);

    return 0;
}
