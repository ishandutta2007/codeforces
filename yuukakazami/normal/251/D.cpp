#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <bitset>
using namespace std;
const int MAX_N = int(1e5) + 10;
typedef long long int64;
int n;
int64 a[MAX_N];

struct GAUSS2 {
	vector<bitset<MAX_N> > B;
	vector<int> W, control;
	int n;

	GAUSS2(int n) :
			n(n) {
	}

	bool addConstraint(bitset<MAX_N> b, int w) {
		int nB = B.size();
		for (int i = 0; i < nB; ++i) {
			if (b[control[i]]) {
				b ^= B[i];
				w ^= W[i];
			}
		}
		if (b.none()) {
			return w == 0;
		}
		B.push_back(b), W.push_back(w);
		int con;
		for (int i = 0; i < n; ++i) {
			if (b[i]) {
				con = i;
				break;
			}
		}
		control.push_back(con);
		for (int i = 0; i < nB; ++i) {
			if (B[i][con])
				B[i] ^= b, W[i] ^= w;
		}
		return true;
	}

	vector<int> construct() {
		vector<int> how(n, 0);
		for (int i = 0; i < (int) B.size(); ++i) {
			how[control[i]] = W[i];
		}
		return how;
	}
};

int cnt[64];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 0; j < 64; ++j) {
			cnt[j] += (a[i] >> j & 1);
		}
	}
	GAUSS2 sol(n);
	static bitset<MAX_N> b;
	for (int i = 63; i >= 0; --i) {
		if (cnt[i] == 0)
			continue;
		if (cnt[i] % 2 == 0) {
			b.reset();
			for (int j = 0; j < n; ++j) {
				b[j] = a[j] >> i & 1;
			}
			sol.addConstraint(b, 1);
		}
	}
	for (int i = 63; i >= 0; --i) {
		if (cnt[i] % 2 == 1) {
			b.reset();
			for (int j = 0; j < n; ++j) {
				b[j] = a[j] >> i & 1;
			}
			sol.addConstraint(b, 0);
		}
	}

	vector<int> how = sol.construct();
	for (int i = 0; i < n; ++i) {
		printf("%d ", 2 - how[i]);
	}
	puts("");

	return 0;
}