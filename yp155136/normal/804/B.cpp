#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

typedef long long LL;
const LL mod = 1e9 +7;
const int MAX_N = 1e6 + 6;

char c[MAX_N];

int main () {
	scanf("%s",c);
	int n=strlen(c);
	LL b_count=0;
	LL ans=0;
	for (int i=n-1;i>=0;i--) {
		if (c[i]=='b') b_count++;
		else {
			ans += b_count;
			b_count *= 2;
			b_count %= mod;
			ans %= mod;
		}
	}
	printf("%lld\n",ans);
}