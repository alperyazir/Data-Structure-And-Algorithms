#include <bits/stdc++.h>
using namespace std;

enum Color
{
	BLACK,
	RED
};
struct Node
{
	Node *parent;
	Node *left;
	Node *right;
	int data;
	Color color;

	Node(int data) : data(data), left(nullptr), right(nullptr), parent(nullptr), color(RED) {}
};

Node *ROOT;

Node *insert(Node *root, Node *new_node)
{
	if (root == nullptr)
	{
		return new_node;
	}

	if (new_node->data < root->data)
	{
		root->left = insert(root->left, new_node);
		root->left->parent = root;
	}
	else if (new_node->data > root->data)
	{
		root->right = insert(root->right, new_node);
		root->right->parent = root;
	}
	return root;
}

void ll_rotation(Node *node)
{
	Node *node_left = node->left;
	Node *node_left_right = node_left->right;

	node_left->right = node;
	node->left = node_left_right;
	node->parent = node_left;
	node_left->parent = node->parent;
	if (node == ROOT)
	{
		ROOT = node_left;
		ROOT->parent = nullptr;
	}
}

void lr_rotation(Node *node)
{
	Node *node_left = node->left;
	Node *node_left_right = node_left->right;

	node_left->right = node_left_right->left;
	node->left = node_left_right->right;
	node_left_right->left = node_left;
	node_left_right->right = node;

	node_left_right->parent == node->parent;
	node->parent = node_left_right;
	node_left->parent = node_left_right;
	node_left_right->left->parent = node_left;
	node_left_right->right->parent = node;

	if (node == ROOT)
	{
		ROOT = node_left_right;
		ROOT->parent = nullptr;
	}
}
Node *rr_rotation(Node *node)
{
	Node *node_right = node->right;
	Node *node_right_left = node_right->left;

	node_right->left = node;
	node->right = node_right_left;
	node->parent = node_right;

	if (node == ROOT)
	{
		ROOT = node_right;
		ROOT->parent = nullptr;
	}
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

	node_right_left->parent = node->parent;
	node->parent = node_right_left;
	node_right->parent = node_right_left;
	node_right_left->left->parent = node;
	node_right_left->right->parent = node_right;

	if (node == ROOT)
	{
		ROOT = node_right_left;
		ROOT->parent = nullptr;
	}

	return node_right_left;
}
void fix_vilolation(Node *root, Node *new_node)
{
	Node *grandparent = nullptr;
	Node *parent = nullptr;
	while (new_node != root && new_node->parent->color == RED)
	{
		parent = new_node->parent;
		grandparent = parent->parent;
		if (parent == grandparent->left)
		{
			Node *uncle = grandparent->right;
			if (uncle != nullptr && uncle->color == RED) // if uncle is not nullptr and RED -> Recoloring
			{
				grandparent->color = RED;
				uncle->color = BLACK;
				parent->color = BLACK;
			}
			else // if uncle is nullptr or Black -> Rotation
			{
				if (new_node == parent->left)
				{
					ll_rotation(grandparent);
				}
				else
				{
					lr_rotation(grandparent);
				}

				swap(parent->color, grandparent->color);
			}
		}
		else
		{
			Node *uncle = grandparent->left;
			if (uncle != nullptr && uncle->color == RED) // if uncle is not nullptr and RED -> Recoloring
			{
				grandparent->color = RED;
				uncle->color = BLACK;
				parent->color = BLACK;
			}
			else // if uncle is nullptr or Black -> Rotation
			{
				if (new_node == parent->right)
				{
					rr_rotation(grandparent);
				}
				else
				{
					grandparent = rl_rotation(grandparent);
					
				}
				swap(parent->color, grandparent->color);
				grandparent->parent->right = new_node;
			}
		}
	}
	ROOT->color = BLACK;
}
void insert_a_node(int val)
{
	Node *new_node = new Node(val);
	ROOT = insert(ROOT, new_node);
	fix_vilolation(ROOT, new_node);
}

void print_level_order()
{
	if (ROOT == NULL)
		return;
	deque<Node *> deq;
	deq.push_back(ROOT);
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

	insert_a_node(10);
	insert_a_node(5);
	insert_a_node(3);
	insert_a_node(30);
	insert_a_node(13);
	insert_a_node(23);
	insert_a_node(14);
	insert_a_node(18);
	insert_a_node(1);
	insert_a_node(9);

	print_level_order();
	return 0;
}
