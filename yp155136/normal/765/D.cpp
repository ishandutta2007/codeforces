#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 1e5 + 6;

int f[MAX_N];
int g[MAX_N];
int h[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%d",&f[i]);
		}
		bool flag=1;
		int m=0;
		for (int i=1;n>=i;i++) {
			if (f[i] != f[f[i]]) {
				flag=0;
			}
			if (i == f[i]) {
				h[++m] = i;
				g[i] = m;
			}
		}
		if (!flag) {
			puts("-1");
			continue;
		}
		for (int i=1;n>=i;i++) {
			if (i != f[i]) {
				g[i] = g[f[i]]; 
			}
		}
		printf("%d\n",m);
		for (int i=1;n>=i;i++) {
			if (i!=1) printf(" ");
			printf("%d",g[i]);
		}
		puts("");
		for (int i=1;m>=i;i++) {
			if (i!=1) printf(" ");
			printf("%d",h[i]);
		}
		puts("");
	}
}