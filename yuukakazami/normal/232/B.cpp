/*
 * cd.cpp
 *
 *  Created on: 2012-10-12
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MOD = 1000000007;

typedef long long int64;

struct Int {
	int x;
	Int() :
			x(0) {
	}
	Int(int _x) :
			x(_x) {
		x %= MOD;
		if (x < 0)
			x += MOD;
	}
	Int(int64 _x) {
		x = _x % MOD;
		if (x < 0)
			x += MOD;
	}
	static Int get(int x) {
		Int a;
		a.x = x;
		return a;
	}

	Int operator+(const Int&o) const {
		int t = x + o.x;
		if (t >= MOD)
			t -= MOD;
		return get(t);
	}
	Int operator*(const Int&o) const {
		return get(1LL * x * o.x % MOD);
	}
	Int operator-(const Int&o) const {
		int t = x - o.x;
		if (t < 0)
			t += MOD;
		return get(t);
	}
	Int operator/(const Int&o) const {
		return (*this) * o.inv();
	}
	Int&operator+=(const Int&o) {
		return (*this) = *this + o;
	}
	Int&operator-=(const Int&o) {
		return (*this) = *this - o;
	}
	Int&operator*=(const Int&o) {
		return (*this) = *this * o;
	}
	Int&operator/=(const Int&o) {
		return (*this) = *this / o;
	}

	Int power(int64 n) const {
		if (!n)
			return get(1);
		const Int&a = *this;
		if (n & 1)
			return power(n - 1) * a;
		else
			return (a * a).power(n >> 1);
	}

	Int inv() const {
		return power(MOD - 2);
	}
};
typedef long long int64;
int n;
int64 m;
int k;
const int MAX_N = 100 + 1;
int64 cnt[MAX_N];
Int comb[MAX_N][MAX_N];
Int dp[MAX_N][MAX_N * MAX_N];
Int way[MAX_N][MAX_N];

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			comb[i][j] = (i == 0 || j == 0) ? 1 : comb[i - 1][j] + comb[i - 1][j - 1];
		}
	}
	for (int i = 0; i < n; ++i) {
		cnt[i] = (m / n);
	}
	for (int i = 0; i < m % n; ++i) {
		++cnt[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= n; ++j) {
			way[i][j] = comb[n][j].power(cnt[i]);
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= k; ++j) {
			Int c = dp[i][j];
			if (!c.x)
				continue;
			for (int u = 0; u <= n && u + j <= k; ++u) {
				dp[i + 1][u + j] += c * way[i][u];
			}
		}
	}
	cout << dp[n][k].x << endl;
	return 0;
}