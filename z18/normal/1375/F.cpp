#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
using namespace std;

typedef long long ll;
ll a[5], c[5]; int b[5], d[5];

bool comp(int x, int y) {
	return a[x] > a[y];
}

void go(ll y) {
	printf("%lld\n", y);
	fflush(stdout);
	int x; scanf("%d", &x);
	if (x == 0) exit(0);
	a[x] += y;
	sort(b + 1, b + 4, comp);
	rep(i, 1, 3) c[i] = a[b[i]], d[b[i]] = i;
}

int main() {
	scanf("%lld %lld %lld", &a[1], &a[2], &a[3]);
	rep(i, 1, 3) b[i] = i;
	puts("First"), go(1e9);
	go(c[1] * 2 - c[2] - c[3]);
	go(c[1] - c[2]);
	return 0;
}