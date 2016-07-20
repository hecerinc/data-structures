#include <iostream>
#include "LinkedList.cpp"
using namespace std;
int main(){
	LinkedList<int> a;
	a.push_back(2);
	a.push_back(3);
	a.push_back(5);
	a.push_back(7);
	a.push_back(11);
	a.print();
	cout << endl;
	Node<int>* first = NULL;
	Node<int>* back = NULL;

	LinkedList<int>::FrontBackSplit(a.head, &first, &back);
	
	Node<int>* tmp = first;
	while(first != NULL){
		cout << first->data << " ";
		first = first->next;
	}
	cout << endl;
	first = tmp;
	tmp = back;
	while(back != NULL){
		cout << back->data << " ";
		back = back->next;
	}
	cout << endl << endl;
	back = tmp;
	a.print();
}