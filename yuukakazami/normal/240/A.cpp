#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
int m, k;
bool favo[1000] = { };
int mi[101], mx[101];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> m >> k;
	for (int i = 0; i < k; ++i) {
		int x;
		cin >> x;
		favo[x] = true;
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int d;
		cin >> d;
		int unKnown = 0;
		int f = 0, nf = 0;
		for (int j = 0; j < d; ++j) {
			int t;
			cin >> t;
			if (t == 0) {
				++unKnown;
			} else {
				if (favo[t])
					++f;
				else
					++nf;
			}
		}
		int rf = k - f, rnf = m - k - nf;
		//min
		if (unKnown <= rnf)
			mi[i] = f;
		else
			mi[i] = unKnown - rnf + f;
		//max
		if (unKnown <= rf)
			mx[i] = f + unKnown;
		else
			mx[i] = f + rf;
	}

	for (int i = 0; i < n; ++i) {
		//check 0
		bool ok = true;
		for (int j = 0; j < n; ++j)
			if (j != i) {
				if (mx[j] > mi[i]) {
					ok = false;
					break;
				}
			}

		if (ok) {
			puts("0");
			continue;
		}
		ok = false;
		for (int j = 0; j < n; ++j) {
			if (j != i) {
				if (mx[i] < mi[j]) {
					ok = true;
					break;
				}
			}
		}
		if (ok) {
			puts("1");
			continue;
		}
		puts("2");
	}
	return 0;
}