#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5 + 6;
const LL mod = 10007;

LL a[MAX_N];
LL b[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int x=0;n>x;x++) {
			scanf("%I64d",&a[x]);
			b[x]=a[x];
		}
		sort(a,a+n);
		sort(b,b+n);
		reverse(a,a+n);
		LL ans=0;
		for (int x=0;n>x;x++) {
			ans += a[x]*b[x];
			ans%=mod;
		}
		printf("%I64d\n",ans);
	}
}