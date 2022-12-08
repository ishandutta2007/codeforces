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
#define rep(i, n) for(int i=0;i<n;i++)  
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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1E-11;

ll mul_inv(ll a, ll b = MOD) {
	ll t1 = a, t2 = b, t3;
	ll v1 = 1, v2 = 0, v3;
	while (t2 != 1) {
		ll x = t1 / t2;
		t3 = t1 - x * t2;
		v3 = v1 - x * v2;
		t1 = t2, t2 = t3;
		v1 = v2, v2 = v3;
	}
	return (v2 + b) % b;
}
ll minv[100050];

bool dchk[100050];
int par[100050];
vector <pll> conn[100050];
vector <pll> son[100050];
vector <pair<ll, pll>> Ve;
map <ll, ll> dp[100050];
map <ll, ll> dp2[100050];
void DFS1(int n) {
	dchk[n] = true;
	for (auto it : conn[n]) {
		if (dchk[it.second]) continue;
		par[it.second] = n;
		son[n].push_back(it);
		DFS1(it.second);

		if (son[it.second].empty()) {
			dp[n][it.second] = 0;
			continue;
		}

		ll s = 0;
		for (auto it2 : dp[it.second]) s += it2.second;
		s = (s * minv[dp[it.second].size()]) % MOD;

		int x = conn[it.second].size();

		ll v1 = minv[x];
		ll v2 = (1 - (1 - minv[x]) * s);
		v2 = (v2 % MOD + MOD) % MOD;
		dp[n][it.second] = v1 * mul_inv(v2) % MOD;
	}
}
void DFS2(int n) {
	ll s = 0;
	for (auto it : dp[n]) s += it.second;
	for (auto it : dp[n]) {
		ll ts = (s - it.second + MOD) % MOD;
		int t = (int)conn[n].size() - 1;
		dp2[n][it.first] = ts * minv[t] % MOD;
	}

	for (auto it : son[n]) {
		if (son[it.second].empty()) continue;

		int x = conn[n].size();

		ll v1 = minv[x];
		ll v2 = 1 - (1 - minv[x]) * dp2[n][it.second];
		v2 = (v2 % MOD + MOD) % MOD;
		dp[it.second][n] = v1 * mul_inv(v2) % MOD;
		DFS2(it.second);
	}
}

ll P[100050];
void DFS3(int n) {
	for (auto it : son[n]) {
		int x = (int)conn[n].size();
		ll v1 = P[n] * minv[x] % MOD;
		ll v2 = 1 - (1 - minv[x]) * dp2[n][it.second];
		v2 = (v2 % MOD + MOD) % MOD;
		P[it.second] = v1 * mul_inv(v2) % MOD;
		DFS3(it.second);
	}
}
int main() {
	int N, i;
	scanf("%d", &N);
	for (i = 1; i <= 100000; i++) minv[i] = mul_inv(i);
	for (i = 1; i < N; i++) {
		ll t1, t2, t3;
		scanf("%lld %lld %lld", &t1, &t2, &t3);
		t1++, t2++;
		conn[t1].emplace_back(t3, t2);
		conn[t2].emplace_back(t3, t1);
		Ve.emplace_back(t3, pll(t1, t2));
	}
	DFS1(1);
	DFS2(1);

	P[1] = 1;
	DFS3(1);

	ll ans = 0;
	for (auto it : Ve) {
		ll d = it.first, x = it.second.first, y = it.second.second;
		if (par[x] == y) swap(x, y);

		ll p1, p2, p3, p4, p5, p6;
		if (son[y].size() == 0) {
			p1 = minv[conn[x].size()];
			p2 = 0;
			p3 = (1 - p1) * dp2[x][y];
			p3 = (p3 % MOD + MOD) % MOD;
			p4 = (1 - p1 - p3 + 2 * MOD) % MOD;
			p5 = 0;
			p6 = 1;
		}
		else {
			p1 = minv[conn[x].size()];
			p2 = minv[conn[y].size()];
			p3 = (1 - p1) * dp2[x][y];
			p3 = (p3 % MOD + MOD) % MOD;
			p4 = (1 - p1 - p3 + 2 * MOD) % MOD;
			p5 = (1 - p2) * dp2[y][x];
			p5 = (p5 % MOD + MOD) % MOD;
			p6 = (1 - p2 - p5 + 2 * MOD) % MOD;
		}

		ll a1 = (1 - p3 + MOD) % MOD;
		ll b1 = (-p1 + MOD) % MOD;
		ll c1 = p1;
		ll a2 = (-p2 + MOD) % MOD;
		ll b2 = (1 - p5 + MOD) % MOD;
		ll c2 = p2;

		ll v1 = c1*b2 - c2*b1;
		ll v2 = a1*b2 - a2*b1;
		v1 = (v1%MOD + MOD) % MOD;
		v2 = (v2%MOD + MOD) % MOD;

		ll p = v1 * mul_inv(v2) % MOD;
		p = (p * P[x]) % MOD;

		//printf("%lld %lld %lld: %lld\n", x, y, d, p);
		ans = (ans + p * d) % MOD;
	}
	return !printf("%lld\n", ans);
}