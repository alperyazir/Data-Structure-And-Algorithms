#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;
    Node(int d) : data(d), height(1), left(nullptr), right(nullptr) {}
};

Node *root = NULL;

Node *find_max(Node *root)
{
    if (root == nullptr)
        return root;
    return root->right == nullptr ? root : find_max(root->right);
}

Node *find_min(Node *root)
{
    if (root == nullptr)
        return root;
    return root->left == nullptr ? root : find_min(root->left);
}

int height_of_node(Node *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}

int get_balanced_factor(Node *node)
{
    return height_of_node(node->left) - height_of_node(node->right);
}

Node *ll_rotation(Node *node)
{
    Node *node_left = node->left;
    Node *node_left_right = node_left->right;

    node_left->right = node;
    node->left = node_left_right;

    node->height = 1 + max(height_of_node(node->left), height_of_node(node->right));
    node_left->height = 1 + max(height_of_node(node_left->left), height_of_node(node_left->right));

    if (root == node)
        root = node_left;
    return node_left;
}

Node *lr_rotation(Node *node)
{
    Node *node_left = node->left;
    Node *node_left_right = node_left->right;

    node_left->right = node_left_right->left;
    node->left = node_left_right->right;
    node_left_right->left = node_left;
    node_left_right->right = node;

    node->height = 1 + max(height_of_node(node->left), height_of_node(node->right));
    node_left->height = 1 + max(height_of_node(node_left->left), height_of_node(node_left->right));
    node_left_right->height = 1 + max(height_of_node(node_left_right->left), height_of_node(node_left_right->right));

    if (root == node)
        root = node_left_right;

    return node_left_right;
}
Node *rr_rotation(Node *node)
{
    Node *node_right = node->right;
    Node *node_right_left = node_right->left;

    node_right->left = node;
    node->right = node_right_left;

    node->height = 1 + max(height_of_node(node->left), height_of_node(node->right));
    node_right->height = 1 + max(height_of_node(node_right->left), height_of_node(node_right->right));

    if (root == node)
        root = node_right;
    return node_right;
}
Node *rl_rotation(Node *node)
{
    Node *node_right = node->right;
    Node *node_right_left = node_right->left;

    node_right->left = node_right_left->right;
    node->right = node_right_left->left;
    node_right_left->right = node_right;
    node_right_left->left = node;

    node->height = 1 + max(height_of_node(node->left), height_of_node(node->right));
    node_right->height = 1 + max(height_of_node(node_right->left), height_of_node(node_right->right));
    node_right_left->height = 1 + max(height_of_node(node_right_left->left), height_of_node(node_right_left->right));

    if (root == node)
        root = node_right_left;

    return node_right_left;
}
void balance(Node *n)
{
}
Node *insert(Node *root, int data)
{
    if (root == nullptr)
    {
        Node *new_node = new Node(data);
        return new_node;
    }

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    root->height = 1 + max(height_of_node(root->left), height_of_node(root->right));

    if (get_balanced_factor(root) > 1 && get_balanced_factor(root->left) >= 0)
        return ll_rotation(root);
    else if (get_balanced_factor(root) > 1 && get_balanced_factor(root->left) < 0)
        return lr_rotation(root);
    else if (get_balanced_factor(root) < -1 && get_balanced_factor(root->right) <= 0)
        return rr_rotation(root);
    else if (get_balanced_factor(root) < -1 && get_balanced_factor(root->right) > 0)
        return rl_rotation(root);

    return root;
}

Node *remove(Node *root, int data)
{
    if (root == nullptr)
        return nullptr;
    if (data < root->data)
        root->left = remove(root->left, data);
    else if (data > root->data)
        root->right = remove(root->right, data);
    else // Founded Node
    {
        // Leaf Node
        if (root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
            return root;
        }
        // Has Left Child
        else if (root->right == nullptr)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
            return root;
        }
        // Has Right Child
        else if (root->left == nullptr)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
            return root;
        }
        // Has Left and Right Child
        /*
            Find min of the right or max of right
        */
        else
        {
            // Find Min of Right Sub Tree
            // BST *temp = find_min(root->right);
            // root->m_data = temp->m_data;
            // root->right = remove(root->right, temp->m_data);
            // return root;

            // Find Min of Left Sub Tree
            Node *temp = find_max(root->left);
            root->data = temp->data;
            root->left = remove(root->left, temp->data);
            return root;
        }
    }
    root->height = 1 + max(height_of_node(root->left), height_of_node(root->right));

    if (get_balanced_factor(root) > 1 && get_balanced_factor(root->left) >= 0)
        return ll_rotation(root);
    else if (get_balanced_factor(root) > 1 && get_balanced_factor(root->left) < 0)
        return lr_rotation(root);
    else if (get_balanced_factor(root) < -1 && get_balanced_factor(root->right) <= 0)
        return rr_rotation(root);
    else if (get_balanced_factor(root) < -1 && get_balanced_factor(root->right) > 0)
        return rl_rotation(root);

    return root;
}
void print_level_order()
{
    if (root == NULL)
        return;
    deque<Node *> deq;
    deq.push_back(root);
    while (!deq.empty())
    {
        cout << deq.front()->data << " ";

        if (deq.front()->left != NULL)
            deq.push_back(deq.front()->left);
        if (deq.front()->right != NULL)
            deq.push_back(deq.front()->right);
        deq.pop_front();
    }

    cout << "\n";
}
int main()
{
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);

    remove(root, 10);
    print_level_order();
    return 0;
}