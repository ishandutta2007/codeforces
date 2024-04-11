#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX_N = 1e5 +6;

int a[MAX_N];

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
		}
		int add=0;
		for (int i=1;m>=i;i++) {
			int t;
			scanf("%d",&t);
			if (t==1) {
				int v,x;
				scanf("%d %d",&v,&x);
				a[v] = x-add;
			}
			else if (t==2) {
				int v;
				scanf("%d",&v);
				add += v;
			}
			else {
				int x;
				scanf("%d",&x);
				printf("%d\n",a[x] + add);
			}
		}
	}
}