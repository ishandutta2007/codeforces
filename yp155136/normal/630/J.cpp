#include <iostream>
#include <stdio.h>
using namespace std;
int main () {
	long long n;
	while (scanf("%I64d",&n) != EOF) {
		printf("%I64d\n",n/2520);
	}
}