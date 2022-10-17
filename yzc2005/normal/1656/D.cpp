#include <bits/stdc++.h>
using namespace std;
void solve() {
	long long n;
	scanf("%lld", &n);
	if (n & 1) {
		puts("2");
	} else {
		long long x = 1;
		while (n % (x * 2) == 0) 
			x *= 2;
		long long y = n / x;
		if (y == 1) 
			puts("-1");
		else if (__int128(y) * __int128(y + 1) / 2 <= n) 
			printf("%lld\n", y);
		else
			printf("%lld\n", x * 2);
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}