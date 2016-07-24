#include <iostream>
#include "Stack.cpp"
using namespace std;
void sortStack(Stack<int> & s1){
	if(s1.isEmpty())
		return;
	int tmp = s1.pop();
	if(s1.top() == NULL){ // Has 1 Node
		s1.push(tmp);
		return;
	}
	Stack<int> s2;
	s2.push(tmp);
	while(s1.top() != NULL){
		if(s1.top() >= s2.top()){
			s2.push(s1.pop());
		}
		else{ //(s1.top() < s2.top()){
			// s2.push(tmp);
			tmp = s1.pop();
			int count = 0;
			while(s2.top() != NULL && s2.top() > tmp){
				count++;
				s1.push(s2.pop());
			}
			s2.push(tmp);
			while(count--) // Move them back
				s2.push(s1.pop());
			// if(s1.top() != NULL)
			// 	tmp = s1.pop();
		}

	}
	while(s2.top() != NULL)
		s1.push(s2.pop());
}
int main(){
	Stack<int> s1;
	s1.push(8);
	s1.push(2);
	s1.push(21);
	s1.push(16);
	s1.push(19);
	s1.push(12);
	s1.push(5);
	s1.push(3);
	s1.push(39);
	s1.push(1);
	// s1.push(11);
	// s1.push(9);
	// s1.push(2);
	// s1.push(6);
	// s1.push(8);
	s1.print();
	sortStack(s1);
	s1.print();


}