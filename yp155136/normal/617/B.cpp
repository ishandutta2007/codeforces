#include <iostream>

#include <stdio.h>
using namespace std;
int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		int a[n];
		for (int x=0;n>x;x++) scanf("%d",&a[x]);
		long long ans=1;
		int tmp=0;
		bool ch1=false;
		for (int x=0;n>x;x++) {
			if (a[x]==0) {
				tmp++;
			}
			else if (a[x]==1 && ch1==false) {
				ch1=true;
				tmp=0;
			}
			else if (a[x]==1) {
				ans*=(tmp+1);
				tmp=0;
			}
		}
		if (ch1==false) ans=0;
		printf("%I64d",ans);
	}
}