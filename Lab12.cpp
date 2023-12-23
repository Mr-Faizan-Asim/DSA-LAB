#include<iostream> 
using namespace std;

class Node
{
public:
	int key;
	Node* left;
	Node* right;
	int height;
};

int height(Node* N)
{
	if (N == nullptr)
		return 0;
	return N->height;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

Node* newNode(int key)
{
	Node* node = new Node();
	node->key = key;
	node->left = nullptr;
	node->right = nullptr;
	node->height = 1; // new node is initially 
	// added at leaf 
	return(node);
}

Node* rightRotate(Node* y)
{
	Node* x = y->left;
	Node* T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(height(y->left),
		height(y->right)) + 1;
	x->height = max(height(x->left),
		height(x->right)) + 1;

	return x;
}

Node* leftRotate(Node* x)
{
	Node* y = x->right;
	Node* T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(height(x->left),
		height(x->right)) + 1;
	y->height = max(height(y->left),
		height(y->right)) + 1;

	return y;
}

int getBalance(Node* N)
{
	if (N == nullptr)
		return 0;
	return height(N->left) - height(N->right);
}

Node* insert(Node* node, int key)
{
	if (node == nullptr)
		return(newNode(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else 
		return node;

	node->height = 1 + max(height(node->left),
		height(node->right));

	int balance = getBalance(node);

	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	if (balance > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

void print(Node* root)
{
	if (root != nullptr)
	{
		cout << root->key << " ";
		print(root->left);
		print(root->right);
	}
}

int main()
{
	Node* root = nullptr;

	root = insert(root, 1);
	root = insert(root, 2);
	root = insert(root, 3);
	root = insert(root, 4);
	root = insert(root, 5);
	root = insert(root, 125);
	print(root);

}



/// quesrtion number 1
class Solution {
	void inorderarray(TreeNode*& root, vector<int>& inorder) {
		if (root == NULL)
			return;
		inorderarray(root->left, inorder);
		inorder.push_back(root->val);
		inorderarray(root->right, inorder);
	}
	TreeNode* buildtree(vector<int>& inorder, int s, int e) {
		if (s > e)
			return NULL;
		int mid = s + (e - s) / 2;
		int ele = inorder[mid];
		TreeNode* root = new TreeNode(ele);
		root->left = buildtree(inorder, s, mid - 1);
		root->right = buildtree(inorder, mid + 1, e);
		return root;
	}

public:
	TreeNode* balanceBST(TreeNode* root) {
		vector<int> inorder;
		inorderarray(root, inorder);
		return buildtree(inorder, 0, inorder.size() - 1);
	}
};

class lab12
{
};
