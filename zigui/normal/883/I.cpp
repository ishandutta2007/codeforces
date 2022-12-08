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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-12;

int indt[1100000];
void update(int p, int v) {
	p += IT_MAX;
	indt[p] = v;
	for (p /= 2; p; p /= 2) indt[p] = indt[2 * p] + indt[2 * p + 1];
}
int getsum(int p1, int p2) {
	p1 += IT_MAX;
	p2 += IT_MAX;
	int rv = 0;
	for (; p1 <= p2; p1 /= 2, p2 /= 2) {
		if (p1 % 2 == 1) rv = rv + indt[p1++];
		if (p2 % 2 == 0) rv = rv + indt[p2--];
	}
	return rv;
}

int in[300050];
int dp[300050];
int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) scanf("%lld", &in[i]);
	sort(in + 1, in + N + 1);

	int st = 0, en = INF, mi, rv = en + 1;
	while (st <= en) {
		mi = (st + en) / 2;
		dp[0] = 1;
		for (i = 1; i < K; i++) dp[i] = 0;
		update(0, 1);
		for (i = K; i <= N; i++) {
			int s = lower_bound(in + 1, in + N + 1, in[i] - mi) - (in + 1);
			int e = i - K;
			dp[i] = !!getsum(s, e);
			update(i, dp[i]);
		}
		for (i = 1; i < 2 * IT_MAX; i++) indt[i] = 0;
		if (dp[N]) {
			rv = mi;
			en = mi - 1;
		}
		else st = mi + 1;
	}
	return !printf("%d\n", rv);
}