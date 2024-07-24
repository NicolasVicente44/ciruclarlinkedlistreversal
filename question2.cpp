// Lakehead University Lab 4
// Question 2
// Nicolas Vicente
// Student ID: 1271740

#include <iostream>

// circular linked list definition
class CircularLinkedList
{
private:
    // node definition
    struct Node
    {
        int data;
        Node *next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node *listData;

    // print reverse function

    void PrintReverse(Node *node) const
    {
        if (node->next != listData)
        {
            PrintReverse(node->next);
        }
        std::cout << node->data << " ";
    }

    // normal order list printing function
    void PrintList() const
    {
        if (listData)
        {
            Node *current = listData;
            do
            {
                std::cout << current->data << " ";
                current = current->next;
            } while (current != listData);
            std::cout << std::endl;
        }
    }

public:
    // constructor
    CircularLinkedList() : listData(nullptr) {}

    // destructor
    ~CircularLinkedList()
    {
        if (listData)
        {
            Node *current = listData;
            Node *nextNode;
            do
            {
                nextNode = current->next;
                delete current;
                current = nextNode;
            } while (current != listData);
        }
    }

    // Print Reverse function
    void PrintReverse() const
    {
        if (listData)
        {
            PrintReverse(listData);
            std::cout << std::endl;
        }
    }

    // append to the list to test the function
    void Append(int value)
    {
        Node *newNode = new Node(value);
        if (!listData)
        {
            listData = newNode;
            newNode->next = listData;
        }
        else
        {
            Node *current = listData;
            while (current->next != listData)
            {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = listData;
        }
    }

    void DisplayList() const
    {
        PrintList();
    }
};

// main class and testing the print reversse funciton
int main()
{
    CircularLinkedList list;

    list.Append(1);
    list.Append(2);
    list.Append(3);
    list.Append(4);
    list.Append(5);

    std::cout << "List in normal order: ";
    list.DisplayList();

    std::cout << "List in reverse order after calling PrintReverse(): ";
    list.PrintReverse();

    return 0;
}
