#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 4013
int N, N1, N2, M;
unordered_map<int, int> cap[MAXN];
map<pair<int, int>, vector<int> > to_idx;
int deg[MAXN];
vector<int> ans[MAXN];
bool vis[MAXN];

bool dfs(int n) {
	if (n == N - 1)
		return true;
	if (vis[n])
		return false;
	vis[n] = true;

	for (auto p : cap[n]) if (p.second) {
		int v = p.first;
		if (dfs(v)) {
			--cap[n][v];
			++cap[v][n];
			return true;
		}
	}
	return false;
}

bool augment() {
	memset(vis, 0, sizeof vis);
	return dfs(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N1 >> N2 >> M;
	N = N1 + N2 + 2;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		b += N1;
		to_idx[{a, b}].push_back(i + 1);
		cap[a][b] += 1;
		++deg[a], ++deg[b];
	}

	int minDeg = M;
	for (int i = 1; i < N - 1; i++)
		minDeg = min(minDeg, deg[i]);

	for (int i = 1; i <= N1; i++)
		cap[0][i] = deg[i] - minDeg;
	for (int i = N1 + 1; i <= N1 + N2; i++)
		cap[i][N - 1] = deg[i] - minDeg;

	for (int k = minDeg; k >= 0; k--) {
		while (augment());

		for (int i = 1; i <= N1; i++) {
			for (auto p : cap[i]) {
				if (p.first != 0)
					for (int j = 0; j < p.second; j++)
						ans[k].push_back(to_idx[{i, p.first}][j]);
			}
		}

		for (int i = 1; i <= N1; i++)
			++cap[0][i];
		for (int i = N1 + 1; i <= N1 + N2; i++)
			++cap[i][N - 1];
	}

	for (int k = 0; k <= minDeg; k++) {
		cout << ans[k].size();
		for (int x : ans[k])
			cout << ' ' << x;
		cout << '\n';
	}
}