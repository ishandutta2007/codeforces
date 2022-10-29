#include <iostream>
#include <stdio.h>
using namespace std;
long long int pow2[57];
int main () {
	pow2[0]=1;
	for (int x=1;57>=x;x++) pow2[x]=pow2[x-1]*2;
	int n;
	while (scanf("%d",&n) != EOF) {
		printf("%I64d\n",pow2[n+1]-2);
	}
}