#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main () {
	long long int n;
	long long pow4[31];
	pow4[0]=1;
	for (int x=1;30>=x;x++) pow4[x]=pow4[x-1]*4;
	while (scanf("%I64d",&n) != EOF) {
		if (n==3) puts("24");
		if (n==3) continue;
		printf("%I64d\n",4*(n-3)*9*pow4[n-4] + 4*2*3*pow4[n-3]);
	}
}