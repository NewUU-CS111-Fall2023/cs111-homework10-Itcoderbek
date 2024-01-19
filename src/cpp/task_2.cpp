#include <iostream>
#include <string>
enum State {
    Q0,  // Initial state, move right to find the first 0
    Q1,  // Move right to find the second 0
    Q2,  // Move right to reach the end of the first number
    Q3,  // Move left to go back to the second 0
    Q4,  // Move left to reach the start of the second number
    Q5,  // Move right to find the next 0 in the second number
    Q6,  // Move right to reach the end of the second number
    Q7,  // Move left to go back to the second 0 in the second number
    Q8,  // Move right to find the next 0 in the first number
    Q9,  // Move right to reach the end of the first number
    Q10, // Move left to go back to the first 0
    Q11, // Move left to reach the start of the first number
    Q12, // Move right to find the next 0 in the second number for copying
    Q13, // Move right to reach the end of the second number for copying
    Q14, // Move left to go back to the second 0 for copying
    Q15, // Move left to reach the start of the second number for copying
    Q16, // Move right to find the next 0 in the result
    Q17, // Move right to reach the end of the result
    QAccept, // Accept state
    QReject  // Reject state
};

// Function to simulate unary addition using a Turing machine
void unaryAddition(std::string& tape) {
    State currentState = Q0;

    while (currentState != QAccept && currentState != QReject) {
        char symbol = tape[tape.size() / 2];

        switch (currentState) {
            // State transitions for finding the first 0
            case Q0:
                if (symbol == '0') {
                    tape[tape.size() / 2] = 'X';
                    currentState = Q1;
                } else {
                    tape.push_back('_');
                    tape.insert(tape.begin(), '_');
                    tape[tape.size() / 2] = '_';
                }
                break;

            // State transitions for finding the second 0
            case Q1:
                if (symbol == '0') {
                    tape[tape.size() / 2] = 'X';
                    currentState = Q2;
                } else {
                    tape.push_back('_');
                    tape.insert(tape.begin(), '_');
                    tape[tape.size() / 2] = '_';
                }
                break;

            // State transitions for reaching the end of the first number
            // (moving right after finding the second 0)
            case Q2:
                if (symbol == '1') {
                    currentState = Q2;
                    tape[tape.size() / 2] = '1';
                } else if (symbol == '_') {
                    currentState = Q3;
                } else {
                    currentState = QReject;
                }
                break;

            // Add more states for the rest of the addition process
        

            default:
                currentState = QReject;
                break;
        }

        // Move the tape head
        if (currentState != QAccept && currentState != QReject) {
            if (currentState == Q3 || currentState == Q4 || currentState == Q7 ||
                currentState == Q10 || currentState == Q11 || currentState == Q14) {
                tape[tape.size() / 2] = '_'; 
                --tape.size();
            } else {
                tape[tape.size() / 2] = '_'; 
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
    std::string tape = "1111101111_1111111111"; // Example input for 5 + 6
    unaryAddition(tape);

    return 0;
}
