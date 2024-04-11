#include <bits/stdc++.h>
using namespace std;

int n, m;

void print(int n){
	for(int i = 0; i < 6; i++){
		if(n & (1 << i))cout << 1;
		else cout << 0;
	}
	cout << endl;
}
int main(){
	scanf("%d", &n);
	
	int m = 0;
	
	if(n & 1)m |= 16;
	if(n & 2)m |= 2;
	if(n & 4)m |= 8;
	if(n & 8)m |= 4;
	if(n & 16)m |= 1;
	if(n & 32)m |= 32;
	
	printf("%d\n", m);
	
	
	
	return 0;
}