#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;




struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

void dfs(int now, const vector<vector<int>>&edges, vector<int>&comes, vector<pair<int, int>>&answers) {

	for (auto e : edges[now]) {
		if (comes[e])continue;
		else {
			comes[e] = true;
			answers.emplace_back(now, e);
			dfs(e, edges, comes, answers);
		}
	}
}
signed main() {
	int N, M; cin >> N >> M;
	UnionFind uf(N);
	vector<vector<int>>edges(N);
	for (int i = 0; i < M; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	pair<int,int>p(-1,-1);
	for (int i = 0; i < N; ++i) {
		p=max(p,make_pair(int(edges[i].size()),i));
	}
	{
		int tt=p.second;
		vector<int>comes(N);
		comes[tt]=true;
		vector<pair<int, int>>answers;

		for (auto e : edges[tt]) {
			answers.emplace_back(tt,e);
			comes[e]=true;
		}
		for (auto e : edges[tt]) {
			dfs(e,edges,comes,answers);
		}
		
		assert(answers.size() == N - 1);
		for (int i = 0; i < answers.size(); ++i) {
			printf("%d %d\n", 1 + answers[i].first, 1 + answers[i].second);
		}
	}
	return 0;
}