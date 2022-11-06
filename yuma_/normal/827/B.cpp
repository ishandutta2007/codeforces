#include "bits/stdc++.h"
using namespace std;
using ld = long double;
const ld eps = 1e-9;

void dfs(const int now, const vector<vector<int>>&edges, vector<int>&memo, int depth) {
	memo[now] = depth;
	for (auto e : edges[now]) {
		if (memo[e] == -1) {
			dfs(e, edges, memo, depth + 1);
		}
	}
}

int dia(const vector<vector<int>>&edges) {
	vector<int>memo(edges.size(), -1);
	{
		memo[0] = 0;
		dfs(0, edges, memo, 0);
	}
	auto it = max_element(memo.begin(), memo.end());
	{
		int start = it - memo.begin();
		vector<int>nmemo(edges.size(), -1);
		nmemo[start] = 0;
		dfs(start, edges, nmemo, 0);
		return *max_element(nmemo.begin(), nmemo.end());
	}
}

void out(vector<pair<int, int>>&p) {
	for (int i = 0; i < p.size(); ++i) {
		cout << 1+p[i].first << " " << 1+p[i].second << endl;
	}
}
int main() {
	int N, S; cin >> N >> S;
	int C = N - S;
	const int c0 = 0;
	const int s0 = C;
	vector<pair<int, int>>g;
	int ans = 0;
	if (C == 1) {
		ans = 2;
		for (int i = 0; i < S; ++i) {
			g.emplace_back(c0, s0 + i);
		}
	}
	else if (C == 2) {
		ans = 3;
		for (int i = 0; i < 1; ++i) {
			g.emplace_back(c0, s0 + i);
		}
		for (int i = 1; i < S; ++i) {
			g.emplace_back(c0 + 1, s0 + i);
		}
		g.emplace_back(c0, c0 + 1);
	}
	else {
		if (C <= S) {
			for (int i = 1; i < C; ++i) {
				g.emplace_back(c0, c0 + i);
			}
			for (int i = 1; i < C; ++i) {
				g.emplace_back(c0 + i, s0 + i - 1);
			}
			for (int i = C; i <= S; ++i) {
				g.emplace_back(c0 + (C - 1), s0 + i - 1);
			}
		}
		else {
			assert(C > S);

			vector<int>v(S, -1);
			for (int i = 0; i < S; ++i) {
				g.emplace_back(c0, c0 + i + 1);
				v[i] = c0 + i + 1;
			}
			for (int k = 0; k < S; ++k) {
				int need = (C - S - 1 + (S - k - 1)) / S;
				for (int t = 0; t < need; ++t) {
					g.emplace_back(c0 + t*S + k + 1, c0 + (t + 1)*S + k + 1);

					v[k] = c0 + (t + 1)*S + k + 1;
				}
			}
			for (int i = 0; i < S; ++i) {
				g.emplace_back(v[i], s0 + i);
			}
		}
	}
	assert(g.size() == N - 1);
	vector<vector<int>>edges(N);
	for (auto p : g) {
		edges[p.first].push_back(p.second);
		edges[p.second].push_back(p.first);
	}
	cout << dia(edges) << endl;
	out(g);
	return 0;
}