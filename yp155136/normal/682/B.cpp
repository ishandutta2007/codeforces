#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

const int MAX_N = 100003;
int a[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int x=0;n>x;x++) scanf("%d",&a[x]);
		sort(a,a+n);
		int id=0;
		for (int x=1;n+1>=x;x++,id++) {
			if (x==n+1) {
				printf("%d\n",n+1);
				break;
			}
			else if (a[id]>=x) ;
			else if (a[id]<x) {
				while (id<n && a[id]<x) id++;
				if (a[id]<x) {
					printf("%d\n",x);
					break;
				}
			}
		}
	}
}