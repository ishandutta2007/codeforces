#include <iostream>
#include <stdio.h>
#include <assert.h>
using namespace std;
int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		long long ans=1;
		for (long long int x=n-4;n>=x;x++) ans*=x;
		printf("%I64d\n",ans/120*ans);
	}
}