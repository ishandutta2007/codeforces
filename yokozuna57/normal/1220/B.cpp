#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef long double ld;

int main(){
	static int n;
	static int m[1002][1002];
	scanf("%d",&n);
	for(int i = 0 ; i < n ; i ++){
		for(int j = 0 ; j < n ; j ++){
			scanf("%d",&m[i][j]);
		}
	}
	
	static int a[1002];
	ld X = m[0][1];
	ld Y = m[0][2];
	ld Z = m[1][2];
	a[1] = (int)(sqrt(X*Z/Y)+0.5);
	a[0] = m[1][0]/a[1];
	for(int i = 2 ; i < n ; i ++){
		a[i] = m[1][i]/a[1];
	}
	for(int i = 0 ; i < n ; i ++){
		printf("%d%c",a[i],(i==n)?'\n':' ');
	}
}