/*
 * d.cpp
 *
 *  Created on: 2011-8-23
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
typedef vector<vector<int> > mat;
const int MOD = 12345;
int N;

mat zero() {
	return mat(N, vector<int>(N, 0));
}

mat unit() {
	mat a = zero();
	for (int i = 0; i < N; ++i) {
		a[i][i] = 1;
	}
	return a;
}

mat operator*(mat a, mat b) {
	mat c = zero();
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int tmp = 0;
			for (int k = 0; k < N; ++k) {
				tmp += a[i][k] * b[k][j];
				if (k % 10 == 0)
					tmp %= MOD;
			}
			c[i][j] = tmp % MOD;
		}
	}
	return c;
}

typedef long long int64;

mat matPow(mat a, int64 e) {
	if (!e)
		return unit();
	return e & 1 ? matPow(a, e - 1) * a : matPow(a * a, e >> 1);
}
int64 n;
int c;

int w[1000], mod[1000];
bool has[26] = { };

int main() {
	cin >> n >> c;
	N = 1;
	for (int i = 0; i < c; ++i) {
		char a;
		scanf(" ");
		cin >> a;
		w[i] = a - 'A';
		has[w[i]] = true;
		cin >> mod[i];
		N *= mod[i];
	}
	mat m = zero();
	for (int i = 0; i < N; ++i) {
		static int cur[1000];
		int x = i;
		for (int j = 0; j < c; ++j) {
			cur[j] = x % mod[j];
			x /= mod[j];
		}
		for (int nxt = 0; nxt < 26; ++nxt)
			if (has[nxt]) {
				for (int j = 0; j < c; ++j) {
					if (w[j] == nxt) {
						++cur[j];
						if (cur[j] >= mod[j])
							cur[j] = 0;
					}
				}
				int ni = 0;
				for (int j = c - 1; j >= 0; --j) {
					ni = ni * mod[j] + cur[j];
				}
				m[i][ni]++;
				if (m[i][ni] >= MOD)
					m[i][ni] -= MOD;
				for (int j = 0; j < c; ++j) {
					if (w[j] == nxt) {
						--cur[j];
						if (cur[j] < 0)
							cur[j] += mod[j];
					}
				}
			}
	}
	mat r = matPow(m, n);
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int x = i;
		bool ok[26] = { };
		for (int j = 0; j < c; ++j) {
			int cur = x % mod[j];
			x /= mod[j];
			if (cur == 0) {
				ok[w[j]] = true;
			}
		}
		bool check = true;
		for (int i = 0; i < 26; ++i) {
			if (has[i] && !ok[i]) {
				check = false;
				break;
			}
		}
		if (check) {
			(ans += r[0][i]) %= MOD;
		}
	}
	cout << ans << endl;
	return 0;
}