#include <iostream>
#include <stdio.h>
using namespace std;
int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		int t[n];
		for (int x=0;n>x;x++) scanf("%d",&t[x]);
		int s=0;
		for (int x=0;n>x;x++) {
			if (s+15<t[x]) {
				s+=15;
				break;
			}
			else if (x!=n-1) s=t[x];
			else if (t[x]+15>90) s=90;
			else s=t[x]+15;
		}
		printf("%d\n",s);
	}
}