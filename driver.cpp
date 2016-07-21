#include <iostream>
#include "LinkedList.cpp"
using namespace std;
int main(){
	LinkedList<int> a;
	// LinkedList<int> b;
	a.push_back(2);
	a.push_back(1);
	a.push_back(3);
	a.push_back(4);
	a.push_back(6);
	a.push_back(5);

	a.print();
	LinkedList<int>::MergeSort(&a.head);
	cout << endl << endl;

	// while(p != NULL){
	// 	cout << p -> data << " -> ";
	// 	p = p->next;
	// }
	// cout << "|| " << endl << endl; 
	a.print();
	// b.print();	
}
