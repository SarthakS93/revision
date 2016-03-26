#include <iostream>
#include "Node.h"
using namespace std;

template <typename T>
class stack_using_node {
	Node<T>* head;
	int numNodes;
	
	public:
	stack_using_node() {
		head = NULL;
		numNodes = 0;
	}

	int size() {
		return numNodes;
	}

	bool isEmpty() {
		if (size() == 0)
			return true;
		return false;
	}

	T top() {
		if (head == NULL)
			return -1;
		return head->data;
	}

	T pop() {
		if (head == NULL)
			return -1;
		
		T toBeReturned = head->data;
		Node<T>* temp = head->next;
		delete head;
		head = temp;
		numNodes--;
		return toBeReturned;
	}

	void push(T newData) {
		Node<T>* newNode = new Node<T>(newData);
		newNode->next = head;
		head = newNode;
		numNodes++;
	}

};
