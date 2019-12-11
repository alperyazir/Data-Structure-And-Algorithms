#include <iostream>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int _data)
    {
        data = _data;
        next = nullptr;
    }
};

Node *insert_a_node_to_tail(Node *head, int data)
{
    Node *new_node = new Node(data);
    if (head == nullptr)
    {
        head = new_node;
        return head;
    }
    Node *iter = head;
    while (iter->next != nullptr)
    {
        iter = iter->next;
    }
    iter->next = new_node;
    return head;
}

Node *insert_a_node_to_head(Node *head, int data)
{
    Node *new_node = new Node(data);
    new_node->next = head;
    return new_node;
}

Node *insert_a_node_to_index(Node *head, int index, int data)
{
    Node *new_node = new Node(data);
    if (head == nullptr)
    {
        head = new_node;
        return head;
    }

    Node *iter = head;
    int counter = 0;
    while (++counter != index)
        iter = iter->next;

    new_node->next = iter->next;
    iter->next = new_node;
    return head;
}

void print_ll(Node *head)
{

    if (head == nullptr)
        return;

    Node *iter = head;
    while (iter != nullptr)
    {
        cout << iter->data << " ";
        iter = iter->next;
    }
    cout << "\n";
}

int main()
{
    Node *head = nullptr;

    // Adding nodes to Tail
    head = insert_a_node_to_tail(head, 1);
    head = insert_a_node_to_tail(head, 2);
    head = insert_a_node_to_tail(head, 3);
    head = insert_a_node_to_tail(head, 4);
    head = insert_a_node_to_tail(head, 5);
    print_ll(head);

    cout << "----------------------------\n";

    // Adding nodes to HEad
    head = insert_a_node_to_head(head, 6);
    head = insert_a_node_to_head(head, 7);
    head = insert_a_node_to_head(head, 8);
    head = insert_a_node_to_head(head, 9);
    head = insert_a_node_to_head(head, 10);
    print_ll(head);

    cout << "----------------------------\n";
    // Adding nodes to index( assumed: index starts from 0)
    head = insert_a_node_to_index(head, 3, 66);
    print_ll(head);

    return 0;
}