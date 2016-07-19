#include <iostream>
#include "Stack.cpp"
int main(){
	Stack<int> a;
	for (int i = 1; i <= 90; i++)
		a.push(i);
	a.pop();
	a.print();
}