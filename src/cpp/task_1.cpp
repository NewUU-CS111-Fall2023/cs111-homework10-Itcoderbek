#include <iostream>
// Node definition for the linked list
struct Node {
    int val;
    Node* next;
    Node(int value) : val(value), next(nullptr) {}
};
// Function to merge nodes between two consecutive 0's
void mergeNodes(Node* start, Node* end) {
    if (!start || !end || start == end)
        return;
    int sum = 0;
    Node* current = start->next;
    Node* nextNode;
    while (current != end) {
        sum += current->val;
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    start->val = sum;
    start->next = end;
}

// Function to process the linked list
void processLinkedList(Node* head) {
    Node* current = head;
    Node* start = nullptr;

    while (current && current->next) {
        if (current->val == 0 && current->next->val == 0) {
            // Found two consecutive 0's, merge nodes in between
            mergeNodes(start, current->next);
        } else if (current->val == 0 && !start) {
            // Found the start of a new interval between 0's
            start = current;
        }

        current = current->next;
    }

    // Delete any remaining 0 nodes at the end
    Node* temp;
    while (head->val == 0) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Function to free the memory allocated for the linked list
void deleteList(Node* head) {
    Node* current = head;
    Node* temp;
    while (current) {
        temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    // Example usage
    Node* head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(0);
    head->next->next->next->next = new Node(3);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(0);
    head->next->next->next->next->next->next->next = new Node(5);
    
    std::cout << "Original list: ";
    printList(head);

    processLinkedList(head);

    std::cout << "Modified list: ";
    printList(head);

    deleteList(head);

    return 0;
}
