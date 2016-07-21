#include <iostream>
#include "LinkedList.cpp"
using namespace std;
int main(){
	LinkedList<int> a;
	LinkedList<int> b;
	a.push_back(1);
	a.push_back(2);
	a.push_back(2);

	b.push_back(2);
	b.push_back(3);
	b.push_back(4);
	b.push_back(5);
	a.print();
	b.print();
	Node<int>* p = LinkedList<int>::SortedMerge(a.head, b.head);
	b.head = NULL;
	a.head = NULL;
	cout << endl << endl;

	while(p != NULL){
		cout << p -> data << " -> ";
		p = p->next;
	}
	cout << "|| " << endl << endl; 
	a.print();
	b.print();	
}