// Practice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};


class BST {
public:
    Node* root;
    BST()
    {
        root = nullptr;
    }

    void insert(int data)
    {
        root = insert(root, data);
    }
    Node* insert(Node* root,int data)
    {
        if (root == nullptr)
        {
            return new Node(data);
        }
        else if (root->val <= data)
        {
            root->right = insert(root->right, data);
        }
        else
        {
            root->left = insert(root->left, data);
        }
        return root;
    }
    Node* Find(Node* root,int val)
    {
        if (root == nullptr)
            return nullptr;
        if (root->val == val)
        {
            return root;
        }
        else if (root->val <= val)
        {
            Find(root->right, val);
        }
        else
        {
            Find(root->left, val);
        }
        
    }
    Node* FindMin(Node* t)
    {
        Node* temp = t;
        
        while (temp->left != nullptr)
            temp = temp->left;
        return temp;
    }
    Node* FindMax(Node* t)
    {
        Node* temp = t;
        while (temp->right != nullptr)
            temp = temp->right;
        return temp;
    }
    void Delete(int val)
    {
        Node* temp = Find(root, val);
        int x;
        Node* t = nullptr;
        if (temp->right != nullptr)

        {
            t = FindMin(temp->right);
        }
        else if (temp->left != nullptr)
            t = FindMax(temp->left);

        if (t != nullptr)
        {
            int x = t->val;
            dem(t->val,root);
            temp->val = x;
            
        }
        else
            temp = nullptr;
        t = nullptr;
    }
    void dem(int val,Node* &root)
    {
        if (root->val == val && root->left == nullptr && root->right == nullptr)
        {
            root = nullptr;
        }
        else if (root->val <= val)
        {
            dem(val,root->right);
        }
        else
        {
            dem(val,root->left);
        }
    }
    void print()
    {
        print(root);
    }
    // print
    void print(Node* root, int space = 0)
    {
        if (root == nullptr)
            return;
        cout << root->val<<endl;
        print(root->right);
        print(root->left);

    }
};

int main()
{
    BST x;
    x.insert(10);
    x.insert(19);
    x.insert(12);
    x.insert(14);
    x.insert(8);
    x.insert(9);
    x.print();
    cout << endl;
    x.Delete(19);
    x.print();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
