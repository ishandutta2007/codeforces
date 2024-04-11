#include <iostream>
#include <stdio.h>
using namespace std;

long long int id[200004];
int f(int a,int b) {
	if (b>a) return b-a;
	else return a-b;
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int x=0;n>x;x++) {
			int t;
			scanf("%d",&t);
			id[t] = x;
		}
		long long ans=0;
		for (int x=1;n>x;x++) ans += f(id[x],id[x+1]);
		printf("%I64d\n",ans);
	}
}