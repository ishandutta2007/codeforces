#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		int mn = n+1;
		for (int x=0;m>x;x++) {
			int i,j;
			scanf("%d %d",&i,&j);
			mn = min(mn,j-i+1);
		}
		printf("%d\n",mn);
		for (int x=0;n>x;x++) {
			if (x!=0) printf(" ");
			printf("%d",x%mn);
		}
		puts("");
	}
}