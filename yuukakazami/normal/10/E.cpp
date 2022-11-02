#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = INT_MAX;
	for (int i = 1; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			int tmp = a[i - 1] - 1;
			int am = 0, w = 0;
			for (int k = 0; k <= j; ++k) {
				int cnt = tmp / a[k];
				tmp %= a[k], am += cnt, w += a[k] * cnt;
			}
			w += a[j], ++am;
			int gd = 0, x = w;
			for (int k = 0; k < n; ++k) {
				gd += x / a[k];
				x %= a[k];
			}
			if (am < gd) {
				ans = min(ans, w);
			}
		}
	}
	cout << (ans == INT_MAX ? -1 : ans) << endl;
	return 0;
}