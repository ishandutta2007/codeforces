#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main () {
	long long n;
	while (scanf("%I64d",&n) != EOF) {
		long long ans=1;
		for (int x=2;sqrt(n)>=x;x++) {
			if (n%x==0) {
				ans*=x;
				while (n%x==0) n/=x;
			}
		}
		ans*=n;
		printf("%I64d\n",ans);
	}
}