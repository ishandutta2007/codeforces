#include <iostream>
#include <stdio.h>
using namespace std;
int main () {
	long long n;
	while(scanf("%I64d",&n) != EOF) {
		if (n%2==0) puts("2");
		else puts("1");
	}
}