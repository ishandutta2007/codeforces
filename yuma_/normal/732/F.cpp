#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"

struct Edge {
	int from;
	int dest;
	int id;
};

struct realEdge {
	int from;
	int dest;
	int id;
	int afrom;
	int adest;
};

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

map<pair<int, int>, int>memo;
struct bridge {
	Edges edges;
	vector<vector<int> > connect;
	vector<int>roots, st, order;
	int cnt;

	bool dfs(const Graph &g, int from, int parent) {
		order[from] = cnt++;
		st.push_back(from);
		roots.push_back(from);
		for (Edge e : g[from]) {
			int to = e.dest;
			if (to == parent) continue;
			if (order[to] == -1) {
				bool ok=dfs(g, to, from);
				if (ok) {
					memo[make_pair(from, to)] = true;
					memo[make_pair(to, from)] = false;
				}
			}
			else {
				if (memo.find(make_pair(from, to)) == memo.end()) {

					memo[make_pair(from, to)] = true;
					memo[make_pair(to, from)] = false;
				}
				while (order[roots.back()] > order[to]) roots.pop_back();
			}
		}
		if (from == roots.back()) {
			edges.push_back(Edge{ parent, from });
			connect.push_back(vector<int>());
			while (true) {
				int w = st.back();
				st.pop_back();
				connect.back().push_back(w);
				if (from == w) break;
			}
			roots.pop_back();
			return false;
		}
		return true;
	}
	Edges get(const Graph &g) {
		const int n = g.size();
		edges.clear(); connect.clear();
		roots.clear(); st.clear(); order.assign(n, -1);
		cnt = 0;
		for (int i = 0; i < n; i++) {
			if (order[i] != -1) continue;
			dfs(g, i, i);
			edges.pop_back();
		}
		return edges;
	}
}br;


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

int N, M;
void dfs(const vector<vector<realEdge>>&es,int now,int from,map<pair<int,int>,int>&memo) {
	for (auto &&e : es[now]) {
		if (e.dest != from) {
			memo[make_pair(e.afrom, e.adest)] = false;
			memo[make_pair(e.adest, e.afrom)] = true;
			dfs(es, e.dest, e.from, memo);
		}
	}
}

void solve(vector<vector<Edge>>&es) {
	vector<pair<int, int>>anss(M);
	br.get(es);
	vector<int>belongs(N);

	int max_size = 0;
	int max_size_id = -1;
	for (int j = 0; j< br.connect.size(); ++j) {
		auto con = br.connect[j];
		for (auto n : con) {
			belongs[n] = j;
		}
		if (con.size() > max_size) {
			max_size = con.size();
			max_size_id = j;
		}
	}
	vector<vector<realEdge>>realedges(br.connect.size());
	for (auto e : br.edges) {
		if (belongs[e.from] != belongs[e.dest]) {
			realedges[belongs[e.from]].push_back(realEdge{
			belongs[e.from],belongs[e.dest],e.id,e.from,e.dest });
			realedges[belongs[e.dest]].push_back(realEdge{
				belongs[e.dest],belongs[e.from],e.id,e.dest,e.from });

		}
	}
	dfs(realedges, max_size_id, -1, memo);
	for (auto ee : es) {
		for (auto e : ee) {
			if (memo.find(make_pair(e.from, e.dest)) == memo.end()) {
				assert(false);
				memo[make_pair(e.from, e.dest)] = true;
				memo[make_pair(e.dest, e.from)] = false;
				anss[e.id] = make_pair(e.from, e.dest);
			}
			else if (memo[make_pair(e.from, e.dest)]) {
				anss[e.id] = make_pair(e.from, e.dest);
			}
		}
	}
	cout << max_size << endl;
	if (max_size == 1)max_size = 0;
	for (auto ans : anss) {
		printf("%d %d\n", ans.first+1, ans.second+1);
	}
	int a = 1;
	a++;
}


int main() {cin >> N >> M;
	UnionFind uf(N);
	vector<vector<Edge>>es(N);
	for (int i = 0; i < M; ++i) {
		int u, v; 
		scanf("%d %d", &u, &v); u--; v--;
		es[u].push_back(Edge{ u,v,i });
		es[v].push_back(Edge{ v,u,i });
		
	}
	
	solve(es);
	
	return 0;
}