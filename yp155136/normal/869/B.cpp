#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;

int main () {
	LL a,b;
	cin >> a >>b;
	if ((b-a) >= 100) puts("0");
	else if (a==b) puts("1");
	else {
		LL now=(a+1)%10;
		for (LL i=a+2;b>=i;i++) {
			now *= (i%10);
			now%=10;
		}
		printf("%lld\n",now);
	}
}