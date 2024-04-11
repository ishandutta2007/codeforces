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
//#include <unordered_map>  
//#include <unordered_set>  
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

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple<int, int, int> t3;
#define rep(i, n) for(int i=0;i<n;i++)

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-12;

vector <int> Vl1;
vector <int> Vl2;
int nxt[1000050];
char in[1000050];

pii dp[1000050][2];
int main() {
	int N, i, j;
	scanf("%d %s", &N, in + 1);
	for (i = 1; i <= N; i++) {
		if (in[i] == '*') Vl2.push_back(i);
		if (in[i] == 'P') Vl1.push_back(i);
	}
	nxt[N + 1] = INF;
	for (i = N; i >= 1; i--) {
		nxt[i] = nxt[i + 1];
		if (in[i] == '*') nxt[i] = i;
	}

	if (Vl1.size() == 1) {
		int ans = 0, t = 0, c = 0, v = INF;
		for (auto it : Vl2) {
			if (it > Vl1[0]) continue;
			c++;
			v = min(v, it);
		}
		v = abs(Vl1[0] - v);
		if (ans < c || (ans == c && t > v)) {
			ans = c;
			t = v;
		}
		c = 0, v = -INF;
		for (auto it : Vl2) {
			if (it < Vl1[0]) continue;
			c++;
			v = max(v, it);
		}
		v = abs(Vl1[0] - v);
		if (ans < c || (ans == c && t > v)) {
			ans = c;
			t = v;
		}
		return !printf("%d %d\n", ans, t);
	}

	int st = 1, en = N, mi, rv = N + 1;
	while (st <= en) {
		mi = (st + en) / 2;

		dp[0][0] = pii(Vl2[0], 0);
		dp[0][1] = pii(Vl2[0], 0);
		for (i = 1; i <= Vl1.size(); i++) {
			int p = Vl1[i - 1];
			dp[i][0] = pii(-INF, -INF);
			for (j = 0; j < 2; j++) {
				int x = dp[i - 1][j].first, y = dp[i - 1][j].second;
				if (x == -INF) continue;
				if (x < p - mi) continue;
				
				pii u;
				u.second = max(y, p);
				u.first = nxt[u.second + 1];
				if (dp[i][0].second < u.second) dp[i][0] = u;
			}
			dp[i][1] = pii(-INF, -INF);
			for (j = 0; j < 2; j++) {
				int x = dp[i - 1][j].first, y = dp[i - 1][j].second;
				if (x == -INF) continue;

				pii u;
				if (x < p) {
					u.first = x;
					u.second = min(N, max(y, p + mi));
				}
				else {
					u.second = min(N, max(y, p + mi));
					u.first = nxt[u.second + 1];
				}
				if (u.first > dp[i][1].first) dp[i][1] = u;
			}
		}
		if (dp[Vl1.size()][0].first == INF || dp[Vl1.size()][1].first == INF) {
			rv = mi;
			en = mi - 1;
		}
		else st = mi + 1;
	}
	return !printf("%d %d\n", (int)Vl2.size(), rv);
}