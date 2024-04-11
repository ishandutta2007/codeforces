#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int n,m,k;
	while (scanf("%d %d %d",&n,&m,&k) != EOF) {
		char c;
		if (k%2==1) c='L';
		else c='R';
		k/=2;
		if (c=='R')k--;
		printf("%d %d %c\n",k/m+1,k%m+1,c);
	}
}