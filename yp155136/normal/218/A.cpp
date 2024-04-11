#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 206;

int a[MAX_N];

int main () {
	int n,k;
	while (scanf("%d %d",&n,&k) != EOF) {
		int mx=-1;
		n = 2*n+1;
		for (int i=1;n>=i;i++) {
			scanf("%d",&a[i]);
			mx = max(mx,a[i]);
		}
		for (int i=1;n>=i;i++) {
			if (i!=1) printf(" ");
			if (i&1) printf("%d",a[i]);
			else {
				if (!k) printf("%d",a[i]);
				else if (a[i]-1>a[i-1] && a[i]-1>a[i+1]) {
					printf("%d",a[i]-1);
					k--;
				}
				else {
					printf("%d",a[i]);
				}
			}
		}
		puts("");
	}
}