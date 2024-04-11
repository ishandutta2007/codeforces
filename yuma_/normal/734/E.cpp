#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;


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
	bool findSet(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};

struct Compress {
	map<int, int>mp;
	map<int, int>revmp;

	Compress(vector<int>vs) {
		setmp(vs);
	}
	Compress(const set<int>&vs) {
		setmp(vs);
	}
	Compress() :mp(), revmp() {

	}
	void setmp(vector<int>vs) {
		sort(vs.begin(), vs.end());
		vs.erase(unique(vs.begin(), vs.end()), vs.end());
		for (int i = 0; i < static_cast<int>(vs.size()); ++i) {
			mp[vs[i]] = i;
			revmp[i] = vs[i];
		}
	}
	void setmp(const set<int>&vs) {
		int num = 0;
		for (auto v : vs) {
			mp[v] = num;
			revmp[num] = v;
			num++;
		}
	}
};

void dfs(const int now,const vector<vector<int>>&edges,vector<int>&memo,int depth) {
	memo[now] = depth;
	for (auto e : edges[now]) {
		if (memo[e] == -1) {
			dfs(e, edges, memo, depth + 1);
		}
	}
}

int dia(const vector<vector<int>>&edges) {
	vector<int>memo(edges.size(),-1);
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

int main() {
	int N; cin >> N;
	vector<vector<int>>realedges;
	{
		vector<int>cs(N);
		for (int i = 0; i < N; ++i) {
			cin >> cs[i];
		}
		vector<vector<int>>edges(N);
		UnionFind uf(N);
		for (int i = 0; i < N - 1; ++i) {
			int a, b; cin >> a >> b; a--; b--;
			edges[a].push_back(b);
			edges[b].push_back(a);
			if (cs[a] == cs[b]) {
				uf.unionSet(a, b);
			}
		}
		vector<int>belongs(N);
		vector<int>as;
		for (int i = 0; i < N; ++i) {
			as.push_back(uf.root(i));
		}
		Compress cp(as);
		for (int i = 0; i < N; ++i) {
			belongs[i] = cp.mp[as[i]];
		}
		realedges.resize(cp.mp.size());
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < edges[i].size(); ++j) {
				int a = i;
				int b = edges[i][j];
				int reala = belongs[a];
				int realb = belongs[b];
				if (reala != realb) {
					realedges[reala].push_back(realb);
					realedges[realb].push_back(reala);
				}
			}
		}
		for (auto& es : realedges) {
			sort(es.begin(), es.end());
			es.erase(unique(es.begin(), es.end()), es.end());
		}
	}
	int d = dia(realedges);
	cout << (d+1) / 2 << endl;

	

	return 0;
}