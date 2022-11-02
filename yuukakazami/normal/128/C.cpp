#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <cctype>
#include <sstream>
using namespace std;
typedef long long int64;

typedef long long int64;

const int MOD = 1000000007;

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
	Int(int64 _x) :
			x(_x) {
		x %= MOD;
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

Int dp[1002][1002];

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int MAX = 1000;
	for (int i = 1; i <= MAX; ++i) {
		dp[0][i] = 1;
	}
	for (int i = 1; i <= MAX; ++i) {
		Int*p = dp[i - 1];
		Int s1[1002], s2[1002];
		s1[0] = p[0];
		s2[0] = p[0] * (0 + 1);
		for (int j = 1; j <= MAX; ++j) {
			s1[j] = s1[j - 1] + p[j];
			s2[j] = s2[j - 1] + p[j] * (j + 1);
		}
		Int*cur = dp[i];
		for (int j = 1; j <= MAX; ++j) {
			if (j < 2) {
				cur[j] = 0;
			} else {
				cur[j] = s1[j - 2] * j - s2[j - 2];
			}
		}
	}
	Int ans = dp[k][n] * dp[k][m];
	cout << ans.x << endl;
	return 0;
}