// Lakehead University Lab 4
// Question 1
// Nicolas Vicente
// Student ID: 1271740

#include <iostream>

// node definition
class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

//circular linked list definition
class CircularLinkedList
{
private:
    Node *head;

public:
    // circular linked list constructor
    CircularLinkedList() : head(nullptr) {}

    // circular linked list destructor
    ~CircularLinkedList()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *current = head->next;
        Node *next;

        while (current != head)
        {
            next = current->next;
            delete current;
            current = next;
        }

        delete head;
        head = nullptr;
    }
};

int main()
{
    CircularLinkedList list;

    std::cout << "Hello, circular linked list!" << std::endl;

    return 0;
}
