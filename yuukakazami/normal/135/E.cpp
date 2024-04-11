/*
 * cd.cpp
 *
 *  Created on: 2012-3-13
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

int k, w;
const int MAX_N = int(1e6) + 10;

Int powerSum(Int a, int e, Int&pw) {
	//a^0 + a^1 + ... + a^e
	//pw = a^e
	if (!e) {
		pw = 1;
		return 1;
	}
	if (e % 2 == 1) {
		//a^0 + a^2 + ... + a^2k
		//a^1 + a^3 + ... + a^2k+1
		Int ret = powerSum(a * a, e / 2, pw);
		pw *= a;
		return ret * (a + 1);
	} else {
		Int ret = powerSum(a, e - 1, pw);
		pw *= a;
		return ret + pw;
	}
}

Int powerSum(Int a, int e) {
	Int pw;
	return powerSum(a, e, pw);
}

Int fact[MAX_N], rfact[MAX_N];

Int comb(int n, int m) {
	if (m > n)
		return 0;
	return fact[n] * rfact[n - m] * rfact[m];
}

Int calc(int k, int w) { // <w
	// length < w
	//k^0 + k^1 + ... k^(w-1)
	Int ret = powerSum(k, w - 1);
	for (int len = w; len <= w + k; ++len) {
		int uni = len - (w - 1);
		//first uni and last uni should be unique
		if (uni * 2 <= len) {
			Int tmp = Int(k).power(len - uni * 2);
			Int a = comb(k, uni) * fact[uni];
			ret += tmp * a * a;
		} else {
			Int tmp = comb(k, uni) * fact[uni];
			int cant = uni * 2 - len;
			tmp *= comb(k - cant, uni - cant) * fact[uni - cant];
			ret += tmp;
		}
	}
	return ret;
}

int main() {
	cin >> k >> w;
	fact[0] = 1;
	for (int i = 1; i < MAX_N; ++i) {
		fact[i] = fact[i - 1] * i;
	}
	rfact[MAX_N - 1] = fact[MAX_N - 1].inv();
	for (int i = MAX_N - 2; i >= 0; --i) {
		rfact[i] = rfact[i + 1] * (i + 1);
	}
	Int ans = calc(k, w + 1) - calc(k, w);
	cout << ans.x << endl;
	return 0;
}