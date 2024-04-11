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

int N, K;
vector <pii> conn[100050];
vector <pii> son[100050];
map <int, ll> dp[100050];
bool dchk[100050];
ll dis[100050];

vector <pll> Vu;
void DFS1(int n) {
	dchk[n] = true;
	for (auto it : conn[n]) {
		if (dchk[it.second]) continue;
		son[n].push_back(it);
		dis[it.second] = dis[n] + it.first;
		DFS1(it.second);
	}

	for (auto it : son[n]) Vu.emplace_back(it.first + dp[it.second][-1], it.second);
	sort(all(Vu));
	if ((int)Vu.size() <= K - 1) {
		ll s = 0;
		for (auto it : Vu) s += it.first;
		dp[n][-1] = s;
		for (auto it : Vu) dp[n][it.second] = s - it.first;
	}
	else {
		ll s = 0;
		for (int i = (int)Vu.size() - 1; i > (int)Vu.size() - K; i--) s += Vu[i].first;
		dp[n][-1] = s;

		ll v = 0;
		if (Vu.size() >= K) v = Vu[Vu.size() - K].first;

		for (int i = (int)Vu.size() - 1; i > (int)Vu.size() - K; i--) dp[n][Vu[i].second] = s - Vu[i].first + v;
		for (int i = (int)Vu.size() - K; i >= 0; i--) dp[n][Vu[i].second] = s;
	}
	Vu.clear();
}

ll ans = 0;
void DFS2(int n, ll s) {
	ans = max(ans, s + dp[n][-1]);
	for (auto it : son[n]) DFS2(it.second, it.first + dp[n][it.second] + s);
}
int main() {
	scanf("%d %d", &N, &K);
	int i;
	for (i = 1; i < N; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		conn[t1].emplace_back(t3, t2);
		conn[t2].emplace_back(t3, t1);
	}
	DFS1(0);

	DFS2(0, 0);
	return !printf("%lld\n", ans);
}