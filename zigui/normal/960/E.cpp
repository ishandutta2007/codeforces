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

const int MX = 200005;
const int MM = 1000000007;

int N;
vector<int> G[MX];
ll V[MX];
ll ans = 0;
pll cnt[MX];
int lev[MX], P[MX];

pll dfs(int x, int p){
	P[x] = p; lev[x] = lev[p] + 1;
	cnt[x] = pll(1, 0);
	for(int c : G[x]){
		if(c == p) continue;
		pll t = dfs(c, x);
		cnt[x].first += t.second;
		cnt[x].second += t.first;
	}
	return cnt[x];
}

ll sq(ll x){ return x*x % MM; }

int main()
{
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		scanf("%lld", V+i);
		V[i] = (V[i] + MM) % MM;
	}
	for(int i = 1; i < N; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		G[a].push_back(b);
		G[b].push_back(a);
	}
	pll r = dfs(1, 0);
	for(int i = 1; i <= N; i++){
		ll p1 = 0, p2 = 0, q1 = 1, q2 = 0;
		pll cur = r;
		if(lev[i]%2 == 0) swap(cur.first, cur.second);
		cur.first--;
		for(int c : G[i]){
			if(c == P[i]) continue;
			p1 += cnt[c].first; p2 += (ll)sq(cnt[c].first);
			q1 += cnt[c].second; q2 += (ll)sq(cnt[c].second);
			cur.first -= cnt[c].second;
			cur.second -= cnt[c].first;
		}
		swap(cur.first, cur.second);
		p1 += cur.first; p2 += sq(cur.first);
		q1 += cur.second; q2 += sq(cur.second);
		p1 %= MM; p2 %= MM; q1 %= MM; q2 %= MM;

		ans += ((sq(q1) - q2) - (sq(p1) - p2)) * V[i] % MM;
	}
	ans = (ans%MM + MM) % MM;
	printf("%lld\n", ans);
}