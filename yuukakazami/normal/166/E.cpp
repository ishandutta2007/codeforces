/*
 * e.cpp
 *
 *  Created on: 2012-3-27
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
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

typedef vector<Int> vec;
typedef vector<vec> mat;

mat zero(int n) {
	return mat(n, vec(n, 0));
}

mat unit(int n) {
	mat a = zero(n);
	for (int i = 0; i < n; ++i) {
		a[i][i] = 1;
	}
	return a;
}

mat operator*(mat a, mat b) {
	int n = a.size();
	mat c = zero(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return c;
}

mat operator+(mat a, mat b) {
	int n = a.size();
	mat c = zero(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	return c;
}

vec operator*(vec a, mat m) {
	int n = a.size();
	vec c(n, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			c[j] += a[i] * m[i][j];
		}
	}
	return c;
}

mat matPow(mat a, int e) {
	if (!e)
		return unit(a.size());
	return (e & 1) ? matPow(a, e - 1) * a : matPow(a * a, e >> 1);
}

mat matPowSum(mat a, mat&ae, int e) {
	//a^0+a^1+a^2+..a^e
	if (!e) {
		ae = unit(a.size());
		return ae;
	}
	if (e % 2 == 0) {
		mat ret = matPowSum(a, ae, e - 1);
		ae = ae * a;
		return ret + ae;
	} else {
		mat tmp = matPowSum(a * a, ae, e >> 1);
		ae = ae * a;
		mat ret = tmp + a * (tmp);
		return ret;
	}
}

mat matPowSum(mat a, int e) {
	mat ae;
	return matPowSum(a, ae, e);
}

int main() {
	int n;
	cin >> n;
	mat m = zero(4);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			if (i != j)
				m[i][j] = 1;
		}
	}
	mat ret = matPow(m, n);
	cout << ret[0][0].x << endl;
	return 0;
}