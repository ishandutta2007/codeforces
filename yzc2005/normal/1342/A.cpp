#include <bits/stdc++.h>
using namespace std;

int t;
long long a, b, x, y;

int main() {
	for(scanf("%d", &t); t; --t) {
		scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
		if(2 * a <= b) printf("%lld\n", (x + y) * a);
		else printf("%lld\n", min(x, y) * b + abs(x - y) * a);
	}
	return 0;
}