#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
ull m, k;
ull n;
const int MK = 67;
ull comb[MK][MK] = {};

//ull dp[MK][MK];
ull calc(ull a, ull b) {
	if (a == -1) {
		if (b) {
			return 0;
		} else {
			return 1;
		}
	}
	if (b == 0) {
		return 1;
	}
	if (n & (1LL<<a)) {
		return comb[a][b] + calc(a-1, b-1);
	} else {
		return calc(a-1, b);
	}
	return 0;
}

ull solve(ull i) {
	n = 2*i;
	ull a = calc(63, k);
	n = i;
	ull b = calc(63, k);
	return a-b;
}

int main() {
	comb[0][0] = 1;
	for (int i = 1; i < MK; i++) {
		comb[i][0] = 1;
		for (int j = 1; j < MK; j++) {
			comb[i][j] = comb[i-1][j]+comb[i-1][j-1];
		}
	}
	cin >> m >> k;
	ull l = 0, r = 1e18+100;
	while (r - l > 1) {
		ull md = (r+l)/2;
		ull res = solve(md);
		if (res == m) {
			cout << md << endl;
			break;
		}
		if (res < m) {
			l = md;
		} else {
			r = md;
		}
	}
}