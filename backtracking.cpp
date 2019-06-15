#include <iostream>

using namespace std;

int R = 4;
int C = 3;
enum direction
{
	DOWN,
	RIGHT
};


int matrix[4][3] = {{1, 1, 1}, {1,0,1}, {1,0,1}, {1,1,1}}; 
void move(enum direction dir) {
	if(dir == DOWN) {
		cout << "Move down" << endl;
	}
	else {
		cout << "Move right" << endl;
	}
}
void undo(int op, int r, int c) {
	if(op == 1) {
		cout << "Move back up" << endl;
	}
	else {
		cout << "Move back left" << endl;
	}
}
bool decide(int r, int c) {
	if(r == R-1 && c == C-1) {
		return true;
	}
	int op = -1;
	if(matrix[r+1][c]){
		move(DOWN);
		op = 1;
		if(decide(r+1, c))
			return true;
		else
			undo(op, r, c);
	}
	if(matrix[r][c+1]) {
		move(RIGHT);
		op = 2;
		if(decide(r, c+1))
			return true;
		else
			undo(op, r, c);
	}
	return false;
}
int main() {
	if(decide(0, 0))
		cout << "Found solution" << endl;
	else
		cout << "No solution found" << endl;
}