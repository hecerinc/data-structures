#include "Node.h"
#include <iostream>
template<typename T>
class Stack {
public:
	Stack(){
		head = NULL;
		length = 0;
	}
	~Stack(){
		makeEmpty();
	}
	void push(const T data){
		Node<T>* p = new Node<T>(data);
		p->next = head;
		head = p;
		length++;
	}
	T pop(){
		if(head == NULL)
			return NULL;
		Node<T>* p = head;
		T data = p->data;
		head = head->next;
		delete p;
		length--;
		return data;
	}
	T top(){
		if(head == NULL)
			return NULL;
		return head->data;
	}
	void makeEmpty(){
		Node<T>* p = head;
		Node<T>* q = head;

		while(p != NULL){
			p = p->next;
			delete q;
			q = p;
		}

		head = NULL;
	}
	bool isEmpty(){return head == NULL;}
	void print(){
		Node<T>* it = head;
		while(it != NULL){
			std::cout << it->data << " ";
			it = it->next;
		}
		std::cout << std::endl;
	}
private:
	Node<T>* head;
	int length;
};