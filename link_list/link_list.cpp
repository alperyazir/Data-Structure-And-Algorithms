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
/* if index is greater than size of the ll, it adds end of the list */
Node *insert_a_node_to_index(Node *head, int index, int data)
{
    Node *new_node = new Node(data);
    if (head == nullptr)
    {
        head = new_node;
        return head;
    }

    if (index == 0)
    {
        return insert_a_node_to_head(head, data);
    }

    Node *iter = head;
    int counter = 0;
    while (iter->next != nullptr && ++counter != index)
        iter = iter->next;

    if (iter->next == nullptr)
    {
        return insert_a_node_to_tail(head, data);
    }

    new_node->next = iter->next;
    iter->next = new_node;
    return head;
}
Node *delete_a_node_to_index(Node *head, int index)
{
    // if (head == nullptr)
    //     return head;
    // Node *temp = head;
    // if (index == 0)
    // {
    //     head = head->next;
    //     delete temp;
    //     return head;
    // }
    // int counter{0};

    // while (temp->next != nullptr)
    // {
    //     if (++counter == index)
    //     {
    //         break;
    //     }
    //     temp = temp->next;
    // }

    // Node *temp1 = temp->next;
    // temp->next = temp->next->next;
    // delete temp1;
    // return head;
}

Node *reverse_linkedlist_with_recursive(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *remainder = reverse_linkedlist_with_recursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return remainder;
}

Node *reverse_linkedlist_with_iterative(Node *head)
{
    if (head == nullptr)
        return head;

    Node *prev = nullptr, *current = head, *next;

    while (current != nullptr)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node *reverse_linkedlist_with_stack(Node *head)
{
    if (head == nullptr)
        return head;

    stack<Node *> m_stack;
    Node *iter = head;
    while (iter->next != nullptr)
    {
        m_stack.push(iter);
        iter = iter->next;
    }
    head = iter;
    while (!m_stack.empty())
    {
        iter->next = m_stack.top();
        iter = iter->next;
        m_stack.pop();
    }
    iter->next = nullptr;
    return head;
}

void print_ll(Node *head)
{

    if (head == nullptr)
        return;

    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

void free_list(Node *head)
{
    if (head == nullptr)
        return;
    Node *iter = head;
    while (iter != nullptr)
    {
        iter = iter->next;
        delete head;
        head = iter;
    }
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
    head = insert_a_node_to_index(head, 0, 66);
    head = insert_a_node_to_index(head, 5, 66);
    head = insert_a_node_to_index(head, 12, 66);
    print_ll(head);
    cout << "----------------------------\n";

    head = reverse_linkedlist_with_stack(head);
    print_ll(head);
    cout << "----------------------------\n";
    //free_list(head);

    return 0;
}