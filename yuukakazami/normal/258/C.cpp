#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
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

int n;
const int MAX_N = int(1e5) + 10;
int a[MAX_N];
int cnt[MAX_N];
vector<int> ds[MAX_N];
int mx;

int get(int l, int r) {
	return cnt[r] - (l ? cnt[l - 1] : 0);
}

Int eval(vector<int>&v) {
	Int ret = 1;
	v.push_back(mx + 1);
	for (int j = 0; j + 1 < v.size(); ++j) {
		int cnt = get(v[j], v[j + 1] - 1);
		ret *= Int(j + 1).power(cnt);
	}
	v.pop_back();
	return ret;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		++cnt[x];
		mx = max(mx, x);
	}
	partial_sum(cnt, cnt + mx + 1, cnt);
	for (int i = 1; i <= mx; ++i) {
		for (int j = i; j <= mx; j += i)
			ds[j].push_back(i);
	}

	Int ans = 0;
	for (int i = 1; i <= mx; ++i) {
		vector<int>&v = ds[i];
		ans += eval(v);
		if (i > 1) {
			v.pop_back();
			ans -= eval(v);
		}
	}

	cout << ans.x << endl;
}