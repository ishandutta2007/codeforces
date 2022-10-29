#include <iostream>
#include <stdio.h>
using namespace std;
int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		int a[n+1];
		int p[n+1];
		for (int x=1;n>=x;x++){
			scanf("%d",&a[x]);
			p[a[x]]=x;
		} 
		if (n==2) {
			puts("1");
		}
		else {
			if (true) {
				int t=max(p[n]-1,n-p[n]);
				int s=max(p[1]-1,n-p[1]);
				printf("%d\n",max(t,s));
			}
		}
	}
}