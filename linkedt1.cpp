#include <iostream>

class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize data and next pointer
    Node(int value) : data(value), next(nullptr) {}

    // Function to insert a new node after a given node
    void insertNode(int value) {
        Node* newNode = new Node(value);
        newNode->next = this->next;
        this->next = newNode;
    }

    // Function to find a node with a given value
    Node* findNode(int value) {
        Node* current = this;
        while (current != nullptr) {
            if (current->data == value)
                return current;
            current = current->next;
        }
        return nullptr; // Node with given value not found
    }

    // Function to remove the next node after this node
    void removeNode() {
        if (this->next == nullptr)
            return; // Nothing to remove
        Node* temp = this->next;
        this->next = temp->next;
        delete temp;
    }

    // Function to print the list starting from this node
    void printList() {
        Node* current = this;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Create 5 nodes with data values
    Node* head = new Node(1);
    head->insertNode(2);
    head->insertNode(3);
    head->insertNode(4);
    head->insertNode(5);

    // Print the initial list
    std::cout << "Initial list: ";
    head->printList(); // Output: 1 2 3 4 5

    // Insert a new node after the 2nd node
    Node* secondNode = head->findNode(2);
    if (secondNode != nullptr)
        secondNode->insertNode(6);

    // Print the updated list
    std::cout << "Updated list after insertion: ";
    head->printList(); // Output: 1 2 6 3 4 5

    // Remove the last node on the list
    Node* fourthNode = head->findNode(4);
    if (fourthNode != nullptr)
        fourthNode->removeNode();

    // Print the updated list
    std::cout << "Updated list after removal: ";
    head->printList(); // Output: 1 2 6 3 4

    // Try to find the last element that was removed
    Node* removedNode = fourthNode->findNode(5);
    if (removedNode == nullptr)
        std::cout << "The last removed node was not found." << std::endl;

    // Find the 4th element using its value
    Node* foundNode = head->findNode(4);
    if (foundNode != nullptr)
        std::cout << "The 4th element is found." << std::endl;
    else
        std::cout << "The 4th element is not found." << std::endl;

    // Clean up memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
