#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long LL;
int main () {
	long long n;
	while (scanf("%I64d",&n) != EOF) {
		
		LL C1=n;
		LL C2=C1*(n-1)/2;
		LL C3=C2*(n-2)/3;
		LL C4=C3*(n-3)/4;
		LL C5=C4*(n-4)/5;
		printf("%I64d\n",(C1+2*C2+C3)*(C1+4*C2+6*C3+4*C4+C5));
	}
}