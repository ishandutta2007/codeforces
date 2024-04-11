#include <bits/stdc++.h>

typedef long long ll;

int main() {
	ll u, v, x; scanf("%lld%lld", &u, &v); x = (v - u) >> 1;
	if(v < u || (v & 1) != (u & 1)) {
		printf("-1\n");
	} else if(u == v && u == 0) {
		printf("0\n");
	} else if(u == v) {
		printf("1\n%lld\n", u);
	} else if((x & u) == 0) {
		printf("2\n%lld %lld\n", u | x, u ^ (u | x));
	} else {
		printf("3\n%lld %lld %lld\n", u, x, x);
	}
	return 0;
}