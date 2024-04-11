#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 1006;

int v[MAX_N];

int main () {
	int n,k,a,b,c,d;
	while (scanf("%d%d%d%d%d%d",&n,&k,&a,&b,&c,&d) != EOF) {
		if (n==4) puts("-1");
		else if (k<=n) puts("-1");
		else {
			memset(v,-1,sizeof(v));
			v[a]=v[b]=v[c]=v[d]=1;
			printf("%d %d ",a,c);
			for (int x=1;n>=x;x++) {
				if (v[x]==-1) printf("%d ",x);
			}
			printf("%d %d\n",d,b);
			printf("%d %d ",c,a);
			for (int x=1;n>=x;x++) {
				if (v[x]==-1) printf("%d ",x);
			}
			printf("%d %d\n",b,d);
		}
	}
}