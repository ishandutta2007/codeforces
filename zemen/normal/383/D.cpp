#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>
#include <cassert>

using namespace std;

#define INF 1000000001
#define INFL 1000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

#define NAME "d"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

#define mod 1000000007

int a[1001];
int buf_d1[1001][20005];
int buf_d2[1001][20005];
int *d1[1001];
int *d2[1001];
int buf_sum1[20005];
int buf_sum2[20005];
int *sum1 = buf_sum1 + 10001;
int *sum2 = buf_sum2 + 10001;
int res = 0;

inline void add(int &a, int b) {
	a += b;
	if (a >= mod)
		a -= mod;
}

void solve(int l, int r) {
	if (l + 1 == r)
		return;
	//~ cerr << "solve " << l << ' ' << r << '\n';
	int c = (l + r) / 2;
	int bd = 0;
	d1[0][0] = 1;
	int cur = 0;
	int SUM = 0;
	for (int i = c - 1; i >= l; --i)
		SUM += a[i];
	for (int i = -SUM; i <= SUM; ++i)
		sum1[i] = 0;
	for (int i = c - 1; i >= l; --i) {
		int bd2 = bd + a[i];
		for (int j = -bd2; j <= bd2; ++j)
			d1[cur + 1][j] = 0;
		for (int j = -bd; j <= bd; ++j) {
			add(d1[cur + 1][j + a[i]], d1[cur][j]);
			add(d1[cur + 1][j - a[i]], d1[cur][j]);
		}
		bd = bd2;
		++cur;
		for (int j = -bd; j <= bd; ++j)
			add(sum1[j], d1[cur][j]);
	}
	int maxsum = SUM;
	//~ for (int i = -SUM; i <= SUM; ++i)
		//~ cerr << sum1[i] << ' ';
	//~ cerr << '\n';
	
	SUM = 0;
	cur = 0;
	bd = 0;
	d2[0][0] = 1;
	for (int i = c; i < r; ++i)
		SUM += a[i];
	for (int i = -SUM; i <= SUM; ++i)
		sum2[i] = 0;
	for (int i = c; i < r; ++i) {
		int bd2 = bd + a[i];
		for (int j = -bd2; j <= bd2; ++j)
			d2[cur + 1][j] = 0;
		for (int j = -bd; j <= bd; ++j) {
			add(d2[cur + 1][j + a[i]], d2[cur][j]);
			add(d2[cur + 1][j - a[i]], d2[cur][j]);
		}
		bd = bd2;
		++cur;
		for (int j = -bd; j <= bd; ++j)
			add(sum2[j], d2[cur][j]);
	}
	maxsum = min(maxsum, SUM);
	//~ for (int i = -maxsum; i <= maxsum; ++i)
		//~ cerr << sum2[i] << ' ';
	//~ cerr << '\n';
	for (int i = -maxsum; i <= maxsum; ++i)
		add(res, (ll(sum2[i]) * ll(sum1[-i])) % mod);
	solve(l, c);
	solve(c, r);
}

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i <= 1000; ++i) {
		d1[i] = buf_d1[i] + 10001;
		d2[i] = buf_d2[i] + 10001;
	}
	solve(0, n);
	cout << res << '\n';
}