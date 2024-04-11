#include <iostream>
#include <stdio.h>
using namespace std;
int main () {
	long long n;
	while (scanf("%I64d",&n) != EOF) {
		long long sum = n*(n-1)*(n-2)*(n-3)*(n-4)/120 + n*(n-1)*(n-2)*(n-3)*(n-4)*(n-5)/720;
		sum+=n/1*(n-1)/2*(n-2)/3*(n-3)/4*(n-4)/5*(n-5)/6*(n-6)/7;
		printf("%I64d\n",sum);
	}
}