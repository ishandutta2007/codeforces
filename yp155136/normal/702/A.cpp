#include <iostream>
#include <stdio.h>
using namespace std;

const int MAX_N = 1e5+6;
int a[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int x=0;n>x;x++) scanf("%d",&a[x]);
		int ans=0;
		int tmp=1;
		for (int x=1;n>x;x++) {
			if (a[x]>a[x-1]) {
				tmp++;
			}
			else {
				ans=max(tmp,ans);
				tmp=1;
			}
		}
		printf("%d\n",max(ans,tmp));
	}
}