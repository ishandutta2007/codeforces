#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

int main() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);
	}

	vector<int> ans[2];

	int i = 0, j = 0;
	while (i < n && j < m) {
		if (a[i] - x <= b[j] && b[j] <= a[i] + y) {
			ans[0].push_back(++i);
			ans[1].push_back(++j);
			continue;
		}
		if (a[i] - x > b[j])
			++j;
		else
			++i;
	}

	cout << ans[0].size() << endl;
	for (int i = 0; i < ans[0].size(); ++i) {
		printf("%d %d\n", ans[0][i], ans[1][i]);
	}
	return 0;
}