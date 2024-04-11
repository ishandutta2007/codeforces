#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;
const int MAX_N = 2e5 + 6;
const LL INF = 1e15 + 6;

LL d[MAX_N],c[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%I64d %I64d",&c[i],&d[i]);
		}
		LL L=-INF,R=INF;
		LL delta=0;
		for (int i=1;n>=i;i++) {
			if (d[i] == 1) {
				L = max(1900-delta ,L);
			}
			else {
				R = min(R,1899 - delta);
			}
			//cout<<L<<" ~ "<<R<<endl;
			delta += c[i];
		}
		if (L>R) puts("Impossible");
		else if (R==INF) puts("Infinity");
		else printf("%I64d\n",R + delta);
	}
}