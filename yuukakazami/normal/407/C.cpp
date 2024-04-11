#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

const int MOD = 1000000007;
const int MAX_N = int(1e5) + 10, MAX_K = 100 + 10;
int n, a[MAX_N], m;
int comb[MAX_N + MAX_K][MAX_K];
vector<pair<int, int> > start[MAX_N], end[MAX_N];

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

Int fact[MAX_N], rfact[MAX_N];

Int Fact(int a, int b) {
	//a*...*b
	if (a <= 0 && b >= 0)
		return 0;
	if (a > 0)
		return fact[b] * rfact[a - 1];
	else {
		int num = b - a + 1;
		Int ret = Fact(-b, -a);
		if (num % 2 == 0)
			return ret;
		else
			return Int(0) - ret;
	}
}

Int binomal(int n, int m) {
	//n*(n-1)*(n-2)*...(n-m+1)
	//divide 1.2.3...m
	return Fact(n - m + 1, n) * rfact[m];
}

Int sum[MAX_K][MAX_N];

int main() {
	fact[0] = 1;
	for (int i = 1; i < MAX_N; ++i) {
		fact[i] = fact[i - 1] * i;
	}
	for (int i = 0; i < MAX_N; ++i) {
		rfact[i] = fact[i].inv();
	}

	for (int i = 0; i < MAX_N + MAX_K; ++i) {
		for (int j = 0; j < MAX_K && j <= i; ++j) {
			if (i == 0 || j == 0)
				comb[i][j] = 1;
			else
				comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
		}
	}
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < m; ++i) {
		int l, r, k;
		cin >> l >> r >> k;
		--l, --r;
		int A = k - l;
		for (int a = 0; a <= k; ++a) {
			Int cof = binomal(A, k - a);
			sum[a][l] += cof;
			sum[a][r + 1] -= cof;
		}
	}

	for (int i = 0; i < MAX_K; ++i) {
		partial_sum(sum[i], sum[i] + n, sum[i]);
	}

	for (int i = 0; i < n; ++i) {
		Int ret = a[i];
		for (int j = 0; j < MAX_K; ++j) {
			ret += binomal(i, j) * sum[j][i];
		}
		printf("%d ", ret.x);
	}
	puts("");
}