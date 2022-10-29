//gcd !!!!!!!!
#include <iostream>
#include <stdio.h>
using namespace std;

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		int max=-1;
		int ans=-1;
		for (int x=0;n>x;x++) {
			int t;
			scanf("%d",&t);
			if (ans==-1) ans=t;
			else {
				int y=ans;
				int z=t;
				while (y%z && z%y) {
					(y>z?y%=z:z%=y);
				}
				ans = min(y,z);
			}
			if (t>max) max=t;
		}
		printf("%s\n",((max/ans-n)%2==0?"Bob":"Alice"));
	}
}