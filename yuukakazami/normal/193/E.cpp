#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

typedef long long int64;
int64 MOD;

int64 mul(int64 a, int64 b) {
	if (a < 1024)
		return a * b % MOD;
	return ((mul(a >> 10, b) << 10) + (a & 1023) * b) % MOD;
}

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
		return get(mul(x, o.x));
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

mat matPow(mat a, int64 e) {
	if (!e)
		return unit(a.size());
	return (e & 1) ? matPow(a, e - 1) * a : matPow(a * a, e >> 1);
}
Int fib(int64 n) {
	mat t = zero(2);
	t[1][0] = t[0][1] = t[1][1] = 1;
	return matPow(t, n)[1][0];
}

int main() {
	int64 f;
	cin >> f;
	vector<int64> id;
	int64 cyc = 1;
	id.push_back(0);
	MOD = 1;
	//f[i+cyc]=f[i]
//	cout << fib(1536).x << " " << fib(1537).x << endl;
	for (int it = 0; it < 26; ++it) {
		int x = it < 13 ? 2 : 5;
		//get new cyclen
		MOD *= x;
		int64 ncyc = cyc;
//		cout << MOD << endl;
		while (fib(ncyc) != 0 || fib(ncyc + 1) != 1) {
//			cout << fib(ncyc).x << " " << fib(ncyc + 1).x << endl;
			ncyc += cyc;
		}
		int64 period = ncyc / cyc;
		vector<int64> nid;
		for (vector<int64>::iterator e = id.begin(); e != id.end(); ++e) {
			for (int i = 0; i < period; ++i) {
				if (fib(*e + i * cyc) == f)
					nid.push_back(*e + i * cyc);
			}
		}
		id = nid;
		cyc = ncyc;
	}
	if (id.empty()) {
		puts("-1");
	} else {
		cout << *min_element(id.begin(), id.end()) << endl;
	}
	return 0;
}