#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

bool check(int n, int m, int x) {
	int rem = n;
	long long need = 0, comb = 1;
	for (int i = 0; i <= x; ++i) {
		if (i > 0) {
			comb *= x - i + 1;
			comb /= i;
		}
		if (comb >= rem) {
			need += 1LL * i * rem;
			rem = 0;
			break;
		} else {
			need += i * comb;
			rem -= comb;
		}
	}
	if (rem > 0)
		return false;
	return 1LL * m * x >= need;
}

int main() {
	int nT;
	cin >> nT;
	for (int i = 0; i < nT; ++i) {
		int n, m;
		cin >> n >> m;
		m = min(n / 2, m);
		int l = -1, r = n;
		while (l + 1 < r) {
			int x = l + r >> 1;
			if (check(n, m, x))
				r = x;
			else
				l = x;
		}
		cout << r << endl;
	}
	return 0;
}