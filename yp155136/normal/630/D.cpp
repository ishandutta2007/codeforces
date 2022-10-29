#include <iostream>
#include <stdio.h>
using namespace std;
int main () {
	long long n;
	while (scanf("%I64d",&n) != EOF) {
		if (n==0) {
			puts("1");
		}
		else {
			n++;
			printf("%I64d\n",-3*n+3*n*n+1);
		}
	}
}