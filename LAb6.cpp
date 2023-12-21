#pragma once
#include<iostream>;
using namespace std;

template <typename T>
class Node {
public:
	Node<T>* next;
	Node<T>* prev;
	T data;
	Node(T data){
		this->data = data;
		this->next = nullptr;
		this->prev = nullptr;
	}
};

template <typename T>
class lab6
{
public:
	Node<T>* root;
	Node<T>* rootEnd;
	int countSize;

	lab6()
	{
		this->root = nullptr;
		this->rootEnd = nullptr;
		countSize = 0;
	}
	bool isEmpty()
	{
		// this is teneary Operator
		return this->root == nullptr ?  true :  false;
	}
	void ifEmpty(T data)
	{
		Node<T>* newNode = new Node<T>(data);
		this->root = newNode;
		this->rootEnd = newNode;
	}
	void insertAtFront(T data)
	{
		if (isEmpty())
		{
			ifEmpty(data);
		}
		else
		{
			Node<T>* newNode = new Node<T>(data);
			root->prev = newNode;
			newNode->next = root;
			root = newNode;
		}
		countSize++;
	}
	void insertAtEnd(T data)
	{
		if (isEmpty())
		{
			ifEmpty(data);
		}
		else
		{
			Node<T>* newNode = new Node<T>(data);
			rootEnd->next = newNode;
			newNode->prev = rootEnd;
			rootEnd = newNode;
		}

		countSize++;
	}
	void insertAtMid(T data)
	{
		if (isEmpty())
		{
			ifEmpty(data);
		}
		else
		{
			T mid = countSize / 2;
			Node<T>* newNode = new Node<T>(data);
			Node<T>* temp = Search(mid);
			if (temp->next != nullptr)
				temp->next->prev = newNode;
			newNode->prev = temp;
			newNode->next = temp->next;
			temp->next = newNode;

		}
		countSize++;
	}
	Node<T>* Search(int Key)
	{
		Search(this->root, Key);
	}
	Node<T>* Search(Node<T>* root,T Key)
	{
		if (root == nullptr)
			return nullptr;
		else if (root->data == Key)
			return root;
		else
			return Search(root->next, Key);
	}
	Node<T>* SearchByIndex(int index)
	{
		Node<T>* temp = root;
		int x = 0;
		while (temp != nullptr)
		{
			if (x == index)
			{
				return temp;
			}
			x++;
		}
		return nullptr;
	}
	void insertAfter(data,key)
	{
		countSize++;
		if (isEmpty())
		{
			ifEmpty(data);
		}
		else
		{
			Node<T>* newNode = new Node<T>(data);
			Node<T>* temp = Search(key);
			if (temp->next != nullptr)
				temp->next->prev = newNode;
			newNode->prev = temp;
			newNode->next = temp->next;
			temp->next = newNode;
			if (key == countSize)
				rootEnd = newNode;

		}
	}
	void insertBefore(data, key)
	{
		if (isEmpty())
		{
			ifEmpty(data);
		}
		else
		{
			Node<T>* newNode = new Node<T>(data);
			Node<T>* temp = Search(key);
			newNode->prev = temp->prev;
			temp->prev->next = newNode;
			temp->prev = newNode;
			newNode->next = temp;

		}
		countSize++;
	}
	T GetFront()
	{
		if(!isEmpty())
			return root->data;
		return nullptr;
	}
	T GetTail()
	{
		if (!isEmpty())
			return rootEnd->data;
		return nullptr;
	}
	void RemoveFront()
	{
		if (!isEmpty())
		{
			root = root->next;
		}
		return nullptr;
	}
	void RemoveTail()
	{
		if (!isEmpty())
		{
			rootEnd = rootEnd->prev;
		}
		return nullptr;
	}
};


// Question 2
class Stack {
	lab6<int>  S;
public:
	Stack()
	{

	}
	void push(int val)
	{
		S.insertAtFront(val);
	}
	int pop()
	{
		S.RemoveTail();
	}
	bool isEmpty()
	{
		return S.isEmpty();
	}
};

class Queue {
	lab6<int> S;
public:
	Queue()
	{

	}
	void Enqueue(int val)
	{
		S.insertAtFront(val);
	}
	int Dequeue()
	{
		S.RemoveFront();
	}
	bool isEmpty()
	{
		return S.isEmpty();
	}
};

// Question 3

class Question3 {
	lab6<int>* s;
public:
	Question3()
	{
		
	}
	 // a
	void PrintRecursively()
	{
		Node<int>* temp = s->rootEnd;
		while (temp != nullptr)
		{

			cout << temp->data;
			temp = temp->prev;

		}
	}
	// b
	int FindMiddle()
	{
		return s->SearchByIndex(s->countSize / 2)->data;
	}
	// c
	bool isCircular()
	{
		if (s->root->prev == s->rootEnd && s->rootEnd->next == s->root->prev)
		{
			return true;
		}
		return false;
	}
	// d
	void ReverseLinkList()
	{
		lab6<int>* T;
		Node<int>* temp = s->rootEnd;
		while (temp != nullptr)
		{
			T->insertAtFront(temp->data);
			temp = temp->prev;
		}
		s = T;
	}

	

};


