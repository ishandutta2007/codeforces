#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
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

const int MAX_N = 2000 + 10;
Int dp[MAX_N][MAX_N]; //h,w
Int sum1[MAX_N], sum2[MAX_N];
Int comb[MAX_N][MAX_N];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 2; i <= m; ++i) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; ++i) {
		for (int j = 2; j <= m; ++j) {
			sum1[j] = sum1[j - 1] + dp[i - 1][j];
			sum2[j] = sum2[j - 1] + dp[i - 1][j] * j;
		}
		for (int j = 2; j <= m; ++j) {
//			for (int k = 2; k <= j; ++k) {
//				dp[i][j] += dp[i - 1][k] * (j - k + 1);
//			}
			dp[i][j] = sum1[j] * (j + 1) - sum2[j];
		}
	}

//	cout << dp[2][3].x << endl;

	Int ans = 0;

	for (int w = 2; w <= m; ++w) {
		static Int ca[MAX_N], cb[MAX_N];
		for (int i = 1; i + 1 <= n; ++i) {
			ca[i] = dp[i][w];
			cb[i] = (dp[i + 1][w] - dp[i][w]);
		}
		Int tmp = 0;
		for (int a = 1; a <= n; ++a) {
//			for (int b = 1; a + b <= n; ++b) {
//				tmp += ca[a] * cb[b] * (n - (a + b) + 1);
//			}

			ans += dp[a][w] * (m - w + 1) * (n - a + 1);
		}

		Int sumb[MAX_N], sumbb[MAX_N];
		for (int i = 1; i + 1 <= n; ++i) {
			sumb[i] = sumb[i - 1] + cb[i];
			sumbb[i] = sumbb[i - 1] + cb[i] * i;
		}

		for (int a = 1; a + 1 <= n; ++a) {
			tmp += ca[a] * sumb[n - a] * (n + 1);
			tmp -= ca[a] * a * sumb[n - a];
			tmp -= ca[a] * sumbb[n - a];
		}

		ans += tmp * (m - w + 1);
	}

	cout << ans.x << endl;
	return 0;
}