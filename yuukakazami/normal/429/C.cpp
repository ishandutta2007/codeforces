#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <numeric>
using namespace std;

int ans, n;

void dfs(int u, int pick, int sum, int need, vector<int>&cnt, vector<int>&tot,
		set<vector<int> >&nam) {
	if (u > n) {
		if (sum != need)
			return;
		if (pick < 2)
			return;
		vector<int> cur = tot;
		for (int i = 0; i <= n; ++i) {
			cur[i] -= cnt[i];
		}
		cur[sum + 1]++;
		nam.insert(cur);
		return;
	}
	for (int x = 0; x * u + sum <= need && x <= tot[u]; ++x) {
		cnt[u] = x;
		dfs(u + 1, pick + x, sum + x * u, need, cnt, tot, nam);
	}
}

int main() {
	cin >> n;
	vector<int> c(n);

	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	sort(c.begin(), c.end());

	set<vector<int> > am, nam;
//	possible[vector<int>()] = true;
	am.insert(vector<int>(n + 1, 0));

	for (int i = 0; i < n; ++i) {
		nam.clear();
		if (c[i] == 1) {
			for (set<vector<int> >::iterator it = am.begin(); it != am.end();
					++it) {
				vector<int> arr = *it;
				arr[1]++;
				nam.insert(arr);
			}
		} else {
			//pick at least two to get sum c[i]-1
			for (set<vector<int> >::iterator it = am.begin(); it != am.end();
					++it) {
				vector<int> arr = *it;
				vector<int> cnt(n + 1, 0);
				dfs(1, 0, 0, c[i] - 1, cnt, arr, nam);
			}
		}
		am = nam;
	}
	for (set<vector<int> >::iterator it = am.begin(); it != am.end(); ++it) {
		vector<int> cnt = *it;
		if (accumulate(cnt.begin(), cnt.end(), 0) == 1 && cnt[n] == 1) {
			puts("YES");
			return 0;
		}
	}

	puts("NO");
	return 0;
}