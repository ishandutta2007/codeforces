#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

typedef long long int64;
vector<int64> lucky;
void rec(int n, int64 cur) {
	if (cur)
		lucky.push_back(cur);
	if (n > 0) {
		rec(n - 1, cur * 10 + 4);
		rec(n - 1, cur * 10 + 7);
	}
}

struct BigInt {
	static const int LEN = 4;
	static const int MOD = int(1e8);
	int64 a[LEN];

	BigInt(int64 x = 0) {
		for (int i = 0; i < LEN; ++i) {
			a[i] = x % MOD;
			x /= MOD;
		}
	}

	BigInt&operator+=(const BigInt&o) {
		int64 carry = 0;
		for (int i = 0; i < LEN; ++i) {
			carry += a[i] + o.a[i];
			a[i] = carry % MOD;
			carry /= MOD;
		}
		return *this;
	}

	BigInt operator+(const BigInt&o) const {
		BigInt c = *this;
		return c += o;
	}

	BigInt&operator=(const BigInt&o) {
		memcpy(a, o.a, sizeof a);
		return *this;
	}

	BigInt&operator-=(const BigInt&o) {
		bool borrow = false;
		for (int i = 0; i < LEN; ++i) {
			if (borrow) {
				--a[i];
				borrow = false;
			}
			if (a[i] < o.a[i]) {
				a[i] += MOD;
				borrow = true;
			}
			a[i] -= o.a[i];
		}
		return *this;
	}

	BigInt operator-(const BigInt&o) const {
		BigInt c = *this;
		return c -= o;
	}

	BigInt operator*(const BigInt&o) const {
		BigInt c;
		for (int i = 0; i < LEN; ++i) {
			for (int j = 0; i + j < LEN; ++j) {
				c.a[i + j] += a[i] * o.a[j];
			}
		}
		for (int i = 0; i < LEN; ++i) {
			if (c.a[i] >= MOD) {
				c.a[i + 1] += c.a[i] / MOD;
				c.a[i] %= MOD;
			}
		}
		return c;
	}

	bool operator<=(const BigInt&o) const {
		for (int i = LEN - 1; i >= 0; --i) {
			if (a[i] < o.a[i])
				return true;
			if (a[i] > o.a[i])
				return false;
		}
		return true;
	}
};

int main() {
	rec(18, 0);
	sort(lucky.begin(), lucky.end());
	int n;
	int64 k;
	cin >> n >> k;
	vector<int64> l(n), r(n);
	int64 minl = LONG_LONG_MAX;
	for (int i = 0; i < n; ++i) {
		cin >> l[i] >> r[i];
		minl = min(minl, r[i] - l[i]);
	}
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	int nL = lucky.size();
	vector<BigInt> lc(nL), rc(nL);
	int cur = l.size(), c = 0;
	BigInt s = 0;
	for (int i = nL - 1; i >= 0; --i) {
		while (cur > 0 && l[cur - 1] >= lucky[i]) {
			--cur;
			++c;
			s += l[cur];
		}
		lc[i] = s - BigInt(c) * lucky[i];
	}

	s = c = 0;
	cur = -1;
	for (int i = 0; i < nL; ++i) {
		while (cur + 1 < r.size() && r[cur + 1] <= lucky[i]) {
			++cur;
			++c;
			s += r[cur];
		}
		rc[i] = BigInt(c) * lucky[i] - s;
	}

	int j = -1, ans = 0;
	for (int i = 0; i < nL; ++i) {
		while (j + 1 < nL && lucky[j + 1] - lucky[i] <= minl && lc[i] + rc[j + 1] <= k)
			++j;
		if (lucky[j] - lucky[i] <= minl && lc[i] + rc[j] <= k)
			ans = max(ans, j - i + 1);
	}
	cout << ans << endl;
	return 0;
}