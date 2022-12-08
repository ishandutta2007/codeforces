#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

int IT_MAX = 1 << 18;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;

vector <int> son[200050];
vector <pii> son2[200050];
int par[200050][20];
int lr[200050][2];
int dep[200050];
bool dchk[200050];
int tus;
void DFS(int n) {
	dchk[n] = true;
	lr[n][0] = ++tus;
	for (auto it : son[n]) {
		dep[it] = dep[n] + 1;
		par[it][0] = n;
		for (int i = 1; i < 20; i++) par[it][i] = par[par[it][i - 1]][i - 1];
		DFS(it);
	}
	lr[n][1] = tus;
}
int lca(int a, int b) {
	if (dep[a] > dep[b]) swap(a, b);
	int c = dep[b] - dep[a];
	for (int i = 0; i < 20; i++) if (c & (1 << i)) b = par[b][i];
	if (a == b) return a;

	for (int i = 19; i >= 0; i--) {
		if (par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}

vector <pair<pii, int>> Vin[200050];
int u[200050];

ll bit[300000];
void update(int p, int v) {
	for (; p <= IT_MAX; p += p & (-p)) bit[p] += v;
}
ll getsum(int p) {
	ll rv = 0;
	for (; p; p -= p & (-p)) rv += bit[p];
	return rv;
}

ll dp[300000];
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 2; i <= N; i++) {
		int t;
		scanf("%d", &t);
		son[t].push_back(i);
	}
	DFS(1);
	while (M--) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		Vin[lca(t1, t2)].emplace_back(pii(t1, t2), t3);
	}

	for (i = 1; i <= N; i++) u[lr[i][0]] = i;
	for (i = N; i >= 1; i--) {
		int n = u[i];

		ll ov = 0;
		for (auto it : son[n]) ov += dp[it];
		dp[n] = ov;

		for (auto it : Vin[n]) {
			int t1 = it.first.first, t2 = it.first.second, t3 = it.second;
			ll v = ov - getsum(lr[t1][0]) - getsum(lr[t2][0]) + t3;
			dp[n] = max(dp[n], v);
		}
		update(lr[n][0], dp[n] - ov);
		update(lr[n][1] + 1, ov - dp[n]);
	}
	return !printf("%lld\n", dp[lr[1][0]]);
}