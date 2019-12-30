#include <bits/stdc++.h>

using namespace std;

struct BST
{
    int m_data;
    BST *left;
    BST *right;
    BST(int data) : m_data(data), left(nullptr), right(nullptr) {}
};

bool contains(BST *root, int data)
{
    if (root == nullptr)
        return false;
    if (root->m_data == data)
        return true;
    else if (data < root->m_data)
        return contains(root->left, data);
    else if (data > root->m_data)
        return contains(root->right, data);
}

BST *find_max(BST *root)
{
    if (root == nullptr)
        return nullptr;
    return root->right == nullptr ? root : find_max(root->right);
}

BST *find_min(BST *root)
{
    if (root == nullptr)
        return nullptr;
    return root->left == nullptr ? root : find_min(root->left);
}

BST *insert(BST *root, int data)
{
    if (root == nullptr)
    {
        BST *new_node = new BST(data);
        return new_node;
    }

    if (data < root->m_data)
        root->left = insert(root->left, data);
    else if (data > root->m_data)
        root->right = insert(root->right, data);
}

BST *remove(BST *root, int data)
{
    if (root == nullptr)
        return nullptr;
    if (data < root->m_data)
        root->left = remove(root->left, data);
    else if (data > root->m_data)
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
            BST *temp = root;
            root = root->left;
            delete temp;
            return root;
        }
        // Has Right Child
        else if (root->left == nullptr)
        {
            BST *temp = root;
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
            BST *temp = find_max(root->left);
            root->m_data = temp->m_data;
            root->left = remove(root->left, temp->m_data);
            return root;
        }
    }
}

int height(BST *root)
{
    if (root == nullptr)
        return -1;
    int l = height(root->left);
    int r = height(root->right);

    if (l > r)
        return l + 1;
    else
        return r + 1;
}

void print(BST *root)
{
    if (root == nullptr)
        return;
    print(root->left);
    cout << root->m_data << "\n";
    print(root->right);
}

void print_level_order(BST *root)
{
    if (root == NULL)
        return;
    deque<BST *> deq;
    deq.push_back(root);
    while (!deq.empty())
    {
        cout << deq.front()->m_data << " ";

        if (deq.front()->left != NULL)
            deq.push_back(deq.front()->left);
        if (deq.front()->right != NULL)
            deq.push_back(deq.front()->right);
        deq.pop_front();
    }

    cout << "\n";
}

void clear(BST *root)
{
    if (root == nullptr)
        return;
    clear(root->left);
    clear(root->right);
    delete root;
}

int main()
{
    BST *root = nullptr;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 5);
    root = insert(root, 7);
    root = insert(root, 8);
    root = insert(root, 9);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 20);
    root = insert(root, 18);
    root = insert(root, 30);
    print(root);

    cout << "--------------------\n";
    cout << "contains 7 ?: " << boolalpha << contains(root, 7) << "\n";
    cout << "contains 21 ?: " << boolalpha << contains(root, 21) << noboolalpha << "\n";

    cout << "--------------------\n";
    BST *temp = find_max(root);
    if (temp != nullptr)
        cout << "max number is :" << temp->m_data << "\n";
    else
        cout << "max can not calculate, tree is empty!\n";

    temp = find_min(root);
    if (temp != nullptr)
        cout << "min number is :" << temp->m_data << "\n";
    else
        cout << "min can not calculate, tree is empty!\n";

    cout << "--------------------\n";
    cout << "Height : " << height(root) << "\n";

    cout << "--------------------\n";
    print_level_order(root);

    cout << "--------------------\n";
    root = remove(root, 15);
    print(root);

    clear(root);
    return 0;
}