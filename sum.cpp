#include<iostream>
using namespace std;
int sum(int a, int b){
	int x, y, z, bm, r;
	int bits = 8*sizeof(int);
	bm = 1; r = 0;
	for(int i = 0; i < bits; i++){
		bm = bm << i;
		x = a & bm;
		y = b & bm;
		bm = 1;


		z = x^y;
		if(x & y){
			z |= 1 << (i+1);	
		}	

		
		x = i;
	
		while((r&(1<<x)) & (z&(1<<x))){
			x++;
			r ^= z;	
			r = r | (1<<x);
		}
		if(x == i)
			r |= z;
	}

	return r;
}
int main(){
	int a, b;
	while(cin >> a >> b){
		cout << sum(a,b) << endl;
	}	
}
