#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
int n, m;
const int MAX_N = 100 + 10;
int map[MAX_N][MAX_N];
bool ur[MAX_N], uc[MAX_N];
int sumr[MAX_N], sumc[MAX_N];
void rev(int r, int c) {
	int x = map[r][c];
	sumr[r] -= x * 2;
	sumc[c] -= x * 2;
	map[r][c] *= -1;
}
void revr(int r) {
	ur[r] ^= 1;
	for (int c = 0; c < m; ++c) {
		rev(r, c);
	}
}
void revc(int c) {
	uc[c] ^= 1;
	for (int r = 0; r < n; ++r) {
		rev(r, c);
	}
}

int main() {
	cin >> n >> m;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			cin >> map[r][c];
			sumr[r] += map[r][c];
			sumc[c] += map[r][c];
		}
	}
	for (;;) {
		int mR = min_element(sumr, sumr + n) - sumr;
		int mC = min_element(sumc, sumc + m) - sumc;
		if (sumr[mR] < sumc[mC]) {
			if (sumr[mR] < 0) {
				revr(mR);
			} else {
				break;
			}
		} else {
			if (sumc[mC] < 0) {
				revc(mC);
			} else {
				break;
			}
		}
	}
	cout << count(ur, ur + n, true);
	for (int i = 0; i < n; ++i) {
		if (ur[i])
			cout << " " << i + 1;
	}
	cout << endl;
	cout << count(uc, uc + m, true);
	for (int i = 0; i < m; ++i) {
		if (uc[i])
			cout << " " << i + 1;
	}
	cout << endl;
	return 0;
}