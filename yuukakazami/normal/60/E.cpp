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

typedef long long int64;

typedef vector<int64> vec;
typedef vector<vec> mat;
int64 p;

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

int MOD;

mat operator*(mat a, mat b) {
	int n = a.size();
	mat c = zero(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				(c[i][j] += a[i][k] * b[k][j]) %= MOD;
			}
		}
	}
	return c;
}

vec operator*(vec a, mat m) {
	int n = a.size();
	vec c(n, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			(c[j] += m[i][j] * a[i]) %= MOD;
		}
	}
	return c;
}

mat matPow(mat a, int64 e) {
	if (!e)
		return unit(a.size());
	return (e & 1) ? matPow(a, e - 1) * a : matPow(a * a, e >> 1);
}

int64 myPow(int64 a, int64 e, int64 mod) {
	if (!e)
		return 1LL;
	return (e & 1) ? myPow(a, e - 1, mod) * a % mod : myPow(a * a % mod, e >> 1, mod);
}

int64 calc(int64 sum, int64 min, int64 max, int64 x) {
	int64 A = (myPow(3, x, p * 2) + 1) / 2;
	int64 ret = sum * (2 * A) - min * A - max * A - (sum - min - max);
	ret %= p;
	if (ret < 0)
		ret += p;
	return ret;
}

int main() {
	int n;
	int64 x, y;
	cin >> n >> x >> y >> p;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	if (n == 1) {
		cout << a[0] % p << endl;
		return 0;
	}
	int64 sum = accumulate(a.begin(), a.end(), 0LL) % p;
	int64 afterSum = calc(sum, a.front(), a.back(), x);
	int64 min = a.front();
	int64 max;
	MOD = p;
	{
		mat m = zero(2);
		m[0][1] = m[1][1] = 1;
		m[1][0] = 1;
		vec v;
		v.push_back(a[n - 2]);
		v.push_back(a[n - 1]);
		v = v * matPow(m, x);
		max = v[1] % p;
	}
	cout << calc(afterSum, min, max, y) << endl;
	return 0;
}