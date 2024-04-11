#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX_N = 100003;

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		int ans=0,i,j;
		int Min=101;
		for (int x=0;n>x;x++) {
			scanf("%d %d",&i,&j);
			j=min(Min,j);
			Min=min(Min,j);
			ans+=i*j;
		}
		printf("%d\n",ans);
	}
}