#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

int main() {
	int n, m, k;
	int a[12][101], b[12][101], c[12][101];
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		string name;
		cin >> name;
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j] >> b[i][j] >> c[i][j];
		}
	}

	int ans = 0;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			if (i != j) {
				vector<int> v;
				for (int k = 0; k < m; ++k) {
					if (b[j][k] > a[i][k]) {
						for (int l = 0; l < c[i][k]; ++l) {
							v.push_back(b[j][k] - a[i][k]);
						}
					}
				}
				sort(v.rbegin(), v.rend());
				int cur = 0;
				for (int l = 0; l < k && l < v.size(); ++l) {
					cur += v[l];
				}
				ans = max(ans, cur);
			}
	}

	cout << ans << endl;
	return 0;
}