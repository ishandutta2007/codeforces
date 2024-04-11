#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MOD = int(1e9) + 7;
typedef long long int64;
struct Int {
	int64 x;
	Int() :
			x(0) {
	}
	Int(int64 _x) {
		x = _x % MOD;
		if (x < 0)
			x += MOD;
	}
	static Int get(int64 x) {
		Int a;
		a.x = x;
		return a;
	}

	Int operator+(const Int&o) const {
		int64 t = x + o.x;
		if (t >= MOD)
			t -= MOD;
		return get(t);
	}
	Int operator*(const Int&o) const {
		return get(1LL * x * o.x % MOD);
	}
	Int operator-(const Int&o) const {
		int64 t = x - o.x;
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
	bool operator==(const Int&o) const {
		return x == o.x;
	}
	bool operator!=(const Int&o) const {
		return x != o.x;
	}
};

const int MAX_N = 200000 + 10;
int h, w, n;

Int fact[MAX_N], rfact[MAX_N];

void prepare_fact() {
	fact[0] = 1;
	for (int i = 1; i < MAX_N; ++i) {
		fact[i] = fact[i - 1] * i;
	}
	rfact[MAX_N - 1] = fact[MAX_N - 1].inv();
	for (int i = MAX_N - 2; i >= 0; --i) {
		rfact[i] = rfact[i + 1] * (i + 1);
	}
}

Int comb(int n, int m) {
	return fact[n] * rfact[m] * rfact[n - m];
}

Int way(pair<int, int> a, pair<int, int> b) {
	int x = b.first - a.first;
	int y = b.second - a.second;
	if (x < 0 || y < 0)
		return 0;
	return comb(x + y, x);
}

int main() {
	cin >> h >> w >> n;
	vector<pair<int, int> > cells;
	cells.push_back(make_pair(0, 0));
	cells.push_back(make_pair(h - 1, w - 1));
	for (int i = 0; i < n; ++i) {
		int r, c;
		cin >> r >> c;
		--r, --c;
		cells.push_back(make_pair(r, c));
	}
	sort(cells.begin(), cells.end());
	prepare_fact();
	vector<Int> dp(cells.size());
	dp[0] = 1;
	for (int i = 1; i < cells.size(); ++i) {
		dp[i] = way(cells[0], cells[i]);
		for (int p = 1; p < i; ++p) {
			dp[i] -= dp[p] * way(cells[p], cells[i]);
		}
	}
	cout << dp.back().x << endl;
}