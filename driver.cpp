#include <iostream>
#include "LinkedList.cpp"
int main(){
	LinkedList<int> a;
	for (int i = 1; i <= 90; i++)
		a.push_back(i);
	a.print();
}