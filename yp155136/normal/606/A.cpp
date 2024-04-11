#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
int main () {
	int a[3];
	int x[3];
	while (scanf("%d %d %d",&a[0],&a[1],&a[2]) != EOF) {
		scanf("%d %d %d",&x[0],&x[1],&x[2]);
		for (int i=0;3>i;i++) {
			a[i] -= x[i];
		}
		int n=0;
		for (int i=0;3>i;i++) {
			if (a[i] > 0) {
				n+=(a[i]/2);
				a[i]=0;
			}
		}
		for (int i=0;3>i;i++) {
			n+=a[i];
		}
		if (n<0) puts("No");
		else puts("Yes");
	}
}