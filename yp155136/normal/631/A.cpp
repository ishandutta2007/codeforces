#include <iostream>
#include <stdio.h>
using namespace std;
int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		long long sum=0;
		long long sum0=0,sum1=0;
		int i;
		for (int x=0;n>x;x++) {
			scanf("%d",&i);
			sum0 = sum0 | i;
		}
		for (int x=0;n>x;x++) {
			scanf("%d",&i);
			sum1 = sum1 | i;
		}
		printf("%I64d\n",sum0+sum1);
	}
}