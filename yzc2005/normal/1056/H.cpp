#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5, B = 500;
int n, q, cnt, pos[N];
vector<int> v[N], e[N];
vector<pair<int, int>> occ[N];
int mark[N];
void solve() {
	scanf("%d%d", &n, &q);
	cnt = 0;
	for (int i = 1; i <= n; ++i)
		occ[i].clear(), e[i].clear();
	for (int i = 1; i <= q; ++i) {
		int k;
		scanf("%d", &k);
		v[i].resize(k);
		for (auto &x : v[i])
			scanf("%d", &x);
	}
	bool valid = true;
	for (int i = 1; i <= q && valid; ++i) {
		int k = v[i].size();
		if (k <= B) {
			for (int j = 0; j < k; ++j)
				occ[v[i][j]].emplace_back(i, j);
		} else {
			for (int j = 0; j < k; ++j)
				pos[v[i][j]] = j;
			for (int j = 1; j <= q && valid; ++j) {
				int mx = 0, lst = 0;
				int k = v[j].size();
				for (int l = k - 1; ~l && valid; --l) {
					int cur = pos[v[j][l]];
					if (cur > mx) {
						mx = cur;
					} else if (cur) {
						if (cur + 1 != lst) {
							valid = false;
							break;
						}
					}
					lst = cur;
				}
			}
			for (int j = 0; j < k; ++j)
				pos[v[i][j]] = 0;
		}
	}
	for (int u = 1; u <= n && valid; ++u) {
		for (auto it : occ[u]) {
			int i, j, k;
			tie(i, j) = it;
			k = v[i].size();
			for (int l = j + 1; l < k; ++l) {
				if (mark[v[i][l]]) {
					if (mark[v[i][l]] != v[i][l - 1]) {
						valid = false;
						break;
					}
				} else {
					mark[v[i][l]] = v[i][l - 1];
				}
			}
		}
		for (auto it : occ[u]) {
			int i, j, k;
			tie(i, j) = it;
			k = v[i].size();
			for (int l = j + 1; l < k; ++l) 
				mark[v[i][l]] = 0;
		}
	}
	puts(valid ? "Robot" : "Human");
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}