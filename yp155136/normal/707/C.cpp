#include <iostream>
#include <stdio.h>
using namespace std;

typedef long long LL;

int main () {
	LL n;
	while (scanf("%I64d",&n) != EOF) {
		if (n<=2) puts("-1");
		else if (n==4) puts("3 5");
		else if (n%2==0) {
			LL tmp=n/2;
			printf("%I64d %I64d\n",(tmp*tmp-1),(tmp*tmp+1));
		}
		else {
			printf("%I64d %I64d\n",(n*n-1)/2,(n*n+1)/2);
		}
	}
}