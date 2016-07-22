#include <iostream>
#include "NodeTree.h"
#include "BinaryTree.h"
using namespace std;
int main(){
	BinaryTree<int> a;
	a.insert(21);
	a.insert(13);
	a.insert(33);
	a.insert(10);
	a.insert(18);
	a.insert(25);
	a.insert(40);
	a.print();
	cout << a.length() << endl;
	a.remove(21);
	a.print();
	cout << a.length() << endl;
}
