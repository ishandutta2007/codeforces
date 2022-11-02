#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <cmath>
using namespace std;
//V=abc minimize !ab+ac+bc=a(b+c)+V/a
const int MAX_FACTORS = 50;
typedef long long int64;
int64 p[MAX_FACTORS];
int64 pws[MAX_FACTORS][100];
int a[MAX_FACTORS], n;
vector<int64> divisors;

void rec(int i, int64 x) {
	if (i == n) {
		divisors.push_back(x);
		return;
	}
	for (int it = 0; it <= a[i]; ++it) {
		rec(i + 1, x);
		x *= p[i];
	}
}

int64 ans;
int pw[MAX_FACTORS];
int64 nxt[MAX_FACTORS];

int64 mxb;
int64 sqrtR;

void rec2(int i, int64 b) {
	if (b > sqrtR)
		return;
	if (nxt[i] * b <= sqrtR) {
		mxb = max(mxb, b * nxt[i]);
		return;
	}
	for (int j = 0; j <= pw[i]; ++j) {
		rec2(i + 1, b);
		b *= p[i];
	}
}

int main() {
	int nT;
	cin >> nT;
	while (nT--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> p[i] >> a[i];
			pws[i][0] = 1;
			for (int j = 1; j <= a[i]; ++j) {
				pws[i][j] = pws[i][j - 1] * p[i];
			}
		}
		divisors.clear();
		rec(0, 1);
		int64 V = divisors.back();
		int64 vCbrt = cbrt(V) + 1;
		ans = LONG_LONG_MAX;
		int64 ansv[3];
		for (int i = divisors.size() - 1; i >= 0; --i) {
			int64 a = divisors[i];
			if (a > vCbrt)
				continue;
			double x = sqrt(V / a);
			double est = a * x * 2 + V / a;
			if (est > ans)
				continue;
			int64 rem = V / a;
			for (int j = 0; j < n; ++j) {
				nxt[j] = rem;
				pw[j] = 0;
				while (rem % p[j] == 0)
					++pw[j], rem /= p[j];
			}
			nxt[n] = 1;
			mxb = 0;
			sqrtR = sqrt(V / a) + 1;
			rec2(0, 1);
//			cout << V / a << " " << mxb << endl;
			int64 b = mxb, c = V / b / a, tmp = (a * b + b * c + c * a);
			int64 tmpv[] = { a, b, c };
			if (tmp < ans) {
				ans = tmp;
				memcpy(ansv, tmpv, sizeof ansv);
			}
		}
		cout << 2 * ans << " " << ansv[0] << " " << ansv[1] << " " << ansv[2] << endl;
	}
	return 0;
}