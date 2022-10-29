#include <iostream>
#include <stdio.h>
using namespace std;
int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		long long ans=1;
		for (int x=0;n>x;x++) {
			ans*=2;
			if (ans == 8192) ans=8092;
		}
		printf("%I64d\n",ans);
	}
}