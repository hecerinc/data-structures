#include <iostream>
#include "PriorityQueue.h"
using namespace std;
int main(){
	PriorityQueue<int> a(10);
	a.Enqueue(10);
	a.Enqueue(7);
	a.Enqueue(25);
	a.Enqueue(12);
	a.Enqueue(8);
	a.Enqueue(4);
	int b;
	a.Dequeue(b);
	cout << b << endl;
	int c;
	a.Dequeue(c);
	cout << c << endl;
}
