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

pll operator + (pll a, pll b) {
	return pll(a.first + b.first, a.second + b.second);
}
ll A[500050], ta[500050], tb[500050];
ll B[500050];

int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for (i = 1; i <= N; i++) scanf("%lld", &B[i]);

	ll st = -10ll * INF, en = 10ll * INF, mi;

	while (st <= en) {
		mi = (st + en) / 2;
		for (int i = 1; i <= N; i++) ta[i] = A[i] + mi;
		for (int i = 1; i <= N; i++) tb[i] = B[i] + mi;
		priority_queue <ll, vector<ll>, greater<ll> > pq;
		priority_queue <ll> pq2;
		ll sum = 0; int cnt[2] = { 0, 0 };
		for (int i = 1; i <= N; i++) {
			pq.push(ta[i]);
			ll t1 = pq.top();
			ll t2 = pq2.empty() ? -1e18 : pq2.top();
			ll v1 = t1 + tb[i];
			ll v2 = tb[i] - t2;
			if (min(v1, v2) < 0) sum += min(v1, v2);
			if (min(v1, v2) < 0 && v1 < v2) {
				cnt[0]++;
				pq2.push(tb[i]); pq.pop();
			}
			if (min(v1, v2) < 0 && v1 >= v2) {
				pq2.pop();
				pq2.push(tb[i]);
			}
		}

		while (!pq.empty())pq.pop();
		while (!pq2.empty())pq2.pop();

		ll sum2 = 0;

		for (int i = 1; i <= N; i++) {
			pq.push(ta[i]);
			ll t1 = pq.top();
			ll t2 = pq2.empty() ? -1e18 : pq2.top();
			ll v1 = t1 + tb[i];
			ll v2 = tb[i] - t2;
			if (min(v1, v2) <= 0) sum2 += min(v1, v2);
			if (min(v1, v2) <= 0 && v1 <= v2) {
				cnt[1]++;
				pq2.push(tb[i]); pq.pop();
			}
			if (min(v1, v2) <= 0 && v1 > v2) {
				pq2.pop();
				pq2.push(tb[i]);
			}
		}

		if (cnt[0] <= K && cnt[1] >= K) {
			printf("%lld\n", sum - 2LL * K * mi);
			return 0;
		}
		else {
			if (cnt[0] > K) {
				st = mi + 1;
			}
			else en = mi - 1;
		}
	}
	return !printf("ERR\n");
}