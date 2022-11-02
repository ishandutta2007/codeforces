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

int n, q, t;
const int MAX_T = int(1e5) + 10;
const int MAX_N = 300 + 10;
int a[MAX_N];

int prev[MAX_N], nxt[MAX_N];

Int am[MAX_T], nam[MAX_T];

void update(vector<int> v) {
	for (int i = 0; i < (int) v.size(); ++i) {
		memset(nam, 0, sizeof nam);
		int dt = 0;
		for (int j = i; j < (int) v.size(); ++j) {
			dt += v[j];
		}
		if (i > 0) {
			for (int i = 0; i <= t; ++i) {
				if (i >= dt) {
					nam[i] = am[i - dt] + nam[i - dt];
				}
			}
		} else {
			for (int i = 0; i <= t; ++i) {
				nam[i] = am[i];
				if (i >= dt) {
					nam[i] += nam[i - dt];
				}
			}
		}
		memcpy(am, nam, sizeof am);
	}
}

int main() {
	cin >> n >> q >> t;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	memset(prev, -1, sizeof prev);
	memset(nxt, -1, sizeof nxt);
	for (int i = 0; i < q; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		nxt[a] = b;
		prev[b] = a;
	}

	int tot = 0;
	am[0] = 1;
	for (int i = 0; i < n; ++i)
		if (nxt[i] == -1) { //start
			vector<int> v;
			int x = i;
			while (x != -1) {
				v.push_back(a[x]);
				x = prev[x];
				++tot;
			}
			update(v);
		}

	if (tot < n) {
		cout << 0 << endl;
		return 0;
	}
	cout << am[t].x << endl;
	return 0;
}