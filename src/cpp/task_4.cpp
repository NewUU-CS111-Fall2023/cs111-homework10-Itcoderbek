#include <iostream>
#include <string>

// Define the states of the Turing machine
enum State {
    Q0,  // Initial state, move right to find the first separator (c)
    Q1,  // Move right to reach the end of the first number
    Q2,  // Move left to go back to the separator (c)
    Q3,  // Move right to find the first 1 in the second number
    Q4,  // Move right to reach the end of the second number
    Q5,  // Move left to go back to the first 1 in the second number
    Q6,  // Move right to find the separator (c) after the second number
    Q7,  // Move right to reach the end of the tape
    Q8,  // Move left to go back to the separator (c)
    Q9,  // Move left to reach the start of the second number
    Q10, // Move left to find the separator (c) before the first number
    Q11, // Move left to reach the start of the first number
    Q12, // Move right to find the next 1 in the second number for copying
    Q13, // Move right to reach the end of the second number for copying
    Q14, // Move left to go back to the second 1 for copying
    Q15, // Move left to reach the start of the second number for copying
    Q16, // Move right to find the next 1 in the result
    Q17, // Move right to reach the end of the result
    Q18, // Move left to go back to the next 1 in the result
    Q19, // Move left to reach the start of the result
    QAccept, // Accept state
    QReject  // Reject state
};

// Function to simulate unary multiplication using a Turing machine
void unaryMultiplication(std::string& tape) {
    State currentState = Q0;

    while (currentState != QAccept && currentState != QReject) {
        char symbol = tape[tape.size() / 2];

        switch (currentState) {
            // State transitions for finding the first separator (c)
            case Q0:
                if (symbol == 'c') {
                    currentState = Q1;
                } else {
                    tape[tape.size() / 2] = '_';
                    ++tape.size();
                }
                break;

            // State transitions for reaching the end of the first number
            case Q1:
                if (symbol == '1') {
                    currentState = Q1;
                    tape[tape.size() / 2] = '1';
                } else if (symbol == '_') {
                    currentState = Q2;
                } else {
                    currentState = QReject;
                }
                break;

            

            default:
                currentState = QReject;
                break;
        }

        // Move the tape head
        if (currentState != QAccept && currentState != QReject) {
            if (currentState == Q3 || currentState == Q5 || currentState == Q9 ||
                currentState == Q11 || currentState == Q14 || currentState == Q19) {
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
        std::cout << "Result: " << tape << std::endl;
    } else {
        std::cout << "Rejected!" << std::endl;
    }
}

int main() {
    // Example input: "c111c11" (3 * 2 in unary)
    std::string tape = "c111c11";
    unaryMultiplication(tape);

    return 0;
}
