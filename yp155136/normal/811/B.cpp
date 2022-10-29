#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 1e4 + 6;

int pos[MAX_N];
int p[MAX_N];

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%d",&p[i]);
		}
		while (m--) {
			int l,r,x;
			scanf("%d %d %d",&l,&r,&x);
			int cnt=0;
			for (int i=l;r>=i;i++) {
				if (p[i]<p[x]) cnt++;
			}
			if (cnt+l==x) puts("Yes");
			else puts("No");
		}
	}
}