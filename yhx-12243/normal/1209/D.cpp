#include <bits/stdc++.h>

const int N = 100054;

int n, K;
int p[N];

int ancestor(int x) {return p[x]==x?x:(p[x]=ancestor(p[x]));}

inline bool test(int x, int y) {
	if ((x=ancestor(x)) == (y=ancestor(y))) return true;
	return p[x]=y,false;
}

int main() {
	int i, u, v, ans = 0;
	scanf("%d%d", &n, &K);
	for (i = 1; i <= n; ++i) p[i] = i;
	for (i = 0; i < K; ++i)
		scanf("%d%d", &u, &v), ans += test(u, v);
	printf("%d\n", ans);
	return 0;
}