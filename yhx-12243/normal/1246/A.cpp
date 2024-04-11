#include <bits/stdc++.h>
#define popc __builtin_popcountll

typedef long long ll;

int n, p;

inline bool get(ll v, int x) {
	return popc(v) <= x && x <= v;
}

int main() {
	int i;
	scanf("%d%d", &n, &p);
	for (i = 1; i < 60; ++i)
		if (get(n - (ll)i * p, i))
			return printf("%d\n", i), 0;
	puts("-1");
	return 0;
}