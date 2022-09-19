#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define PLL pair <LL, LL>
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define debug2(...) cerr << __VA_ARGS__
#else
#define debug(...)
#define debug2(...)
#endif
bool invert_mode = false;
int n, m;
const int MOD = 32;
VI hmap[MOD];
const int MN = 1e5 + 44;
int a[MN];
int b[MN];
void add(int x) {
	hmap[x % MOD].push_back(x);
}
bool is(int x) {
	for (auto y : hmap[x % MOD])
		if (y == x)
			return true;
	return false;
}
void check(int dist) {
	debug("check %d start = %d\n", dist, a[0]);
	int count = 0;
	for (int wh = a[0]; count <= n && is(wh); wh = (wh + dist) % m, count++) {
		debug("iter 1 in %d\n", wh);
	}
	int start = 0;
	for (start = a[0]; count <= n && is(start); start = (start + m - dist) % m, count++) {
		debug("iter 2 in %d\n", start);
	}
	start = (start + dist) % m;
	debug("reach count = %d\n", count);
	if (count == n + 1) {
		debug("\tans:");
		printf("%lld %d\n", (start + invert_mode * dist * (LL)n) % m, dist);
#ifndef DEB
		exit(0);
#endif
	}
}
int main() {
	scanf("%d%d", &m, &n);
	if (n == m) {
		printf("1 1\n");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	if (m - n < n) {
		invert_mode = true;
		sort(a, a + n);
		memcpy(b, a, sizeof(int) * n);
		for (int i = 0, pa = 0, pb = 0; i < m; ++i) {
			if (b[pb] == i)
				pb++;
			else
				a[pa++] = i;
		}
		n = m - n;
		debug("take complement:\n");
		for (int i = 0; i < n; ++i)
			debug("%d ", a[i]);
		debug("done\n");
	}
	for (int i = 0; i < n; ++i)
		add(a[i]);
	for (int i = 1; i < n; ++i) {
		check(abs(a[i] - a[0]));
	}
	if (n == 1)
		check(1);
	printf("-1\n");
}