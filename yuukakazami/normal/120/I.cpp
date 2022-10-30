#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <string>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <bitset>
using namespace std;

const int MAX_N = int(2e5) + 10;
int L, n;
int ds[MAX_N];

int mark[10] = { 119, 18, 93, 91, 58, 107, 111, 82, 127, 123 };
int c[10][10];
int maxC[10];
int maxCC;

struct TA {
	int a[MAX_N];
	int n;
	void init(int _n) {
		n = _n;
		memset(a, 0, sizeof a);
	}
	void add(int p, int x) {
		for (p++; p <= n; p += p & -p)
			a[p - 1] += x;
	}
	int sum(int r) { //r)
		int ret = 0;
		for (; r > 0; r -= r & -r)
			ret += a[r - 1];
		return ret;
	}
	int sum(int l, int r) { //[l,r)
		return sum(r) - sum(l);
	}
} ps, mcs;

void changeDigit(int i, int d, bool rm = true) {
	int pi = i >= n ? i - n : i + n;
	if (rm) {
		int od = maxC[ds[i]];
		mcs.add(i, -od);
		od = c[ds[i]][ds[pi]];
		ps.add(min(i, pi), -od);
	}
	ds[i] = d;
	mcs.add(i, maxC[ds[i]]);
	ps.add(min(i, pi), c[ds[i]][ds[pi]]);
}

int evalMax(int pre) {
	int ret = 0;
	if (pre <= n) {
		return mcs.sum(pre) + (n - pre) * maxCC;
	} else {
		int nHave = pre - n;
		ret += ps.sum(nHave);
		ret += mcs.sum(nHave, n);
		return ret;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			int com = mark[i] & mark[j];
			int cnt = 0;
			for (int k = 0; k < 10; ++k) {
				if (com >> k & 1)
					++cnt;
			}
			c[i][j] = cnt;
		}
	}
	for (int i = 0; i < 10; ++i) {
		maxC[i] = 0;
		for (int j = 0; j < 10; ++j) {
			maxC[i] = max(maxC[i], c[i][j]);
		}
	}
	maxCC = *max_element(maxC, maxC + 10);
	string ip;
	cin >> ip;
	L = ip.size();
	for (int i = 0; i < L; ++i) {
		ds[i] = ip[i] - '0';
	}
	int my = 0;
	n = L / 2;
	for (int i = 0; i < n; ++i) {
		my += c[ds[i]][ds[i + n]];
	}
	mcs.init(L);
	ps.init(L);
	for (int i = 0; i < L; ++i) {
		mcs.add(i, maxC[ds[i]]);
		if (i + n < L)
			ps.add(i, c[ds[i]][ds[i + n]]);
	}

	for (int sameLength = L - 1; sameLength >= 0; --sameLength) {
		for (int thisDigit = ds[sameLength] + 1; thisDigit < 10; ++thisDigit) {
			int tmp = ds[sameLength];
			changeDigit(sameLength, thisDigit);
			if (evalMax(sameLength + 1) > my) {
				//then build the answer
				for (int i = sameLength + 1; i < L; ++i) {
					for (int d = 0; d < 10; ++d) {
						int tmp = ds[i];
						changeDigit(i, d);
						if (evalMax(i + 1) > my) {
							break;
						}
						changeDigit(i, tmp);
					}
				}
				for (int i = 0; i < L; ++i) {
					printf("%d", ds[i]);
				}
				cout << endl;
				return 0;
			}
			changeDigit(sameLength, tmp);
		}
	}

	cout << -1 << endl;
}