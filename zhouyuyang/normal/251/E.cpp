#include <map>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long i64;
typedef pair<int,int> PII;


const int N = 300030;
const int mod = 1e9 + 7;

typedef int arr32[N];

int n, en;
arr32 dep, eq, sz, k1, k2, kz, son, dp, de;
map<PII,int> MPP;

struct edge {
	int to, nx;
} ee[N * 2];

void inc(int& a, int b) {
	if (a += b, a >= mod) a -= mod;
}
void link(int u, int v) {
	ee[++en] = (edge) {v, eq[u]}, eq[u] = en;
	++de[v];
}
int count_2(int u, int v) {
	for (; ; ) {
		if (!u && !v) return 1;
		if (!u || !v) return dp[u | v];
		if (son[u] == 2 || son[v] == 2) return 0;
		u = k1[u], v = k1[v];
	}
}
bool isline(int u, int l) {
	return (!kz[u] && sz[u] == l);
}
int query(int u, int v) {
	if (u > v) swap(u, v);
	if (!u) return dp[v];
	PII cp = make_pair(u, v);
	if (MPP.find(cp) == MPP.end()) MPP[cp] = count_2(u, v);
	return MPP[cp];
}
int get_dp(int o) {
	if (sz[o] % 2 != 0) return 0;
	int ret = 0;
	if (son[o] == 2) {
		int x = k1[o], y = k2[o];
		if (son[x] != 2) inc(ret, count_2(k1[x], y));
		if (son[y] != 2) inc(ret, count_2(k1[y], x));
		return ret;
	}
	int p = kz[o];
	if (!p) return sz[o] / 2;
	int ds = dep[p] - dep[o];

	if (ds >= 2) inc(ret, dp[k1[k1[o]]]);

	int x = k1[p], y = k2[p];
	if (isline(x, ds - 1)) inc(ret, dp[y]);
	if (isline(y, ds - 1)) inc(ret, dp[x]);

	for (int foo = 0; foo < 2; ++foo) {
		swap(x, y);
		if (isline(k1[x], ds)) inc(ret, query(k2[x], y));
		if (isline(k2[x], ds)) inc(ret, query(k1[x], y));
	}
	return ret;
}
void makeroot(int o, int pr) {
	sz[o] = 1;
	for (int j = eq[o], v; v = ee[j].to, j; j = ee[j].nx)
		if (v != pr) {
			dep[v] = dep[o] + 1;
			makeroot(v, o);
			son[o]++;
			if (son[o] == 1) k1[o] = v;
			if (son[o] == 2) k2[o] = v;
			sz[o] += sz[v];
		}
	kz[o] = (son[o] < 2)? kz[k1[o]]: o;
	dp[o] = get_dp(o);
}
int solve(int o) {
	int ans = 0;
	makeroot(o, 0);

	int s[3] = {0}, st = 0;
	for (int j = eq[o]; j; j = ee[j].nx) s[st++] = ee[j].to;
	sort(s, s + 3);
	do {
		int _s[2] = {0}, _st = 0;
		for (int j = eq[s[1]]; j; j = ee[j].nx) if (ee[j].to != o) _s[_st++] = ee[j].to;
		sort(_s, _s + 2);
		do {
			int lsz = sz[s[0]] + sz[_s[0]];
			if (lsz % 2 == 0) {
				inc(ans, (i64)count_2(s[0], _s[0]) * count_2(s[2], _s[1]) % mod);
			}
		} while (next_permutation(_s, _s + 2));
	} while (next_permutation(s, s + 3));
	
	return ans;
}
int main() {
	scanf("%d", &n), n *= 2;
	for (int i = 1; i < n; ++i) {
		int u, v;
		scanf("%d %d", &u, &v);
		link(u, v), link(v, u);
	}

	int o = 0;
	for (int i = 1; i <= n; ++i) {
		if (de[i] > 3) {printf("0\n");return 0;}
		if (de[i] == 3) o = i;
	}
	if (!o) {
		n /= 2;
		int ans = ((i64)(n - 2) * (n - 1) + n * 2) * 2 % mod;
		if (n == 1) ans = 2;
		printf("%d\n", ans);
		return 0;
	}

	printf("%d\n", solve(o) * 2 % mod);
}