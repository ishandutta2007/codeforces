#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

using Weight = pair<long long int, int>;

struct Edge {
	int src, dst;
	long long int  weight;
	long long int c;
	int id;
	Edge(int src_, int dst_, long long int weight_ ,const int id_) :
		src(src_), dst(dst_), weight(weight_), id(id_) { }
	Edge(int src_, int dst_, long long int weight_,long long int  c, const int id_) :
		src(src_), dst(dst_), weight(weight_),c(c), id(id_) { }
};
long long int INI = 0;
class Tree {
public:
	Tree(int V, int root) : V(V), root(root), cnum(V), place(V), id(V),
		T(V),parent(MAXLOGV,vector<int>(V)),depth(V),ws(MAXLOGV,vector<Weight>(V,make_pair(INI,-1))) {
	}
	// uv
	// lca
	void unite(Edge&e) {
		T[e.src].push_back(Edge(e.src, e.dst, e.weight, e.id));
		T[e.dst].push_back(Edge(e.dst, e.src, e.weight, e.id));
	}
	// init
	// lca
	void init() {
		dfs(root, 0, 0,0,-1);
		int id = 0;
		getid(root, 0, id);
	}
	Weight connect(const Weight&l, const  Weight&r)const  {
		return max(l, r);
	}
	// uvlca
	Weight lca(int u, int v) const {
		if (depth[u] > depth[v]) swap(u, v);
		Weight ans = make_pair(INI,-1);
		for (int k = 0; k < MAXLOGV; k++) {
			if ((depth[v] - depth[u]) >> k & 1) {
				ans = connect(ans, ws[k][v]);
				v = parent[k][v];
				
			}
		}
		if (u == v) return ans;
		for (int k = MAXLOGV - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				ans = connect(ans,ws[k][u]);
				ans = connect(ans,ws[k][v]);
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		ans = connect(ans,ws[0][u]);
		ans = connect(ans, ws[0][v]);
		return ans;
	}

	int dfs(int v, int p, int d,long long int w,int id) {
		parent[0][v] = p;
		ws[0][v] =make_pair(w,id);
		depth[v] = d;
		cnum[v] = 0;
		for (int i = 1; i < MAXLOGV; i++) {
			parent[i][v] = parent[i - 1][parent[i - 1][v]];
			
			ws[i][v] = connect(ws[i - 1][v], ws[i - 1][parent[i - 1][v]]);
		}
		for (auto e : T[v]) {
			auto next = e.dst;
			if (next != p) cnum[v] += dfs(next, v, d + 1,e.weight,e.id);
		}
		return cnum[v] + 1;
	}

	void getid(const int v, const int p, int &nplace) {
		place[v] = nplace;
		id[nplace] = v;
		nplace++;
		for (auto e : T[v]) {
			const auto next = e.dst;
			if (next != p) getid(next, v, nplace);
		}
	}
	static const int MAXLOGV = 25;
	// 
	vector<vector<Edge> > T;
	// 
	int V;
	// 
	int root;

	// 
	vector<vector<int>>parent;
	// aa
	vector<vector<Weight>>ws;
	// 
	vector<int> depth;

	//
	vector<int>cnum;

	//
	vector<int>place;
	vector<int>id;

};
class Compare {
public:
	bool operator() (const Edge&l, const Edge&r) {
		return l.weight > r.weight;
	}
};

int main() {
	int N, M; cin >> N >> M;
	vector<vector<Edge>>edges(N);
	vector<Edge>e_col;
	{
		vector<int>ws(M), cs(M);
		for (int i = 0; i < M; ++i) {
			cin >> ws[i];
		}
		for (int i = 0; i < M; ++i) {
			cin >> cs[i];
		}
		for (int i = 0; i < M; ++i) {
			int a, b; cin >> a >> b; a--; b--;
			Edge e(a, b, ws[i],cs[i], i);
			Edge reve(b, a, ws[i],cs[i], i);
			edges[a].push_back(e);
			edges[b].push_back(reve);
			e_col.push_back(e);
		}
	}
	Tree t(N,0);
	vector<int>e_used(M);
	{
		priority_queue<Edge, vector<Edge>, Compare>que;
		for (auto e : edges[0]) {
			que.push(e);
		}
		vector<int>oks(N);
		oks[0] = true;
		while (!que.empty()) {
			Edge atop(que.top());
			que.pop();
			if (!oks[atop.dst]) {
				t.unite(atop);
				e_used[atop.id] = true;
				oks[atop.dst] = true;
				for (auto e : edges[atop.dst]) {
					if (!oks[e.dst]) {
						que.push(e);
					}
				}
			}
		}
	}
	long long int S; cin >> S;
	t.init();
	long long int min_c = INT_MAX;
	long long int sum_w = 0;
	pair<Weight, int>ans;
	for (int i = 0; i < M; ++i) {
		if (e_used[i]) {
			min_c = min(min_c, e_col[i].c);
			sum_w += e_col[i].weight;
		}
		auto p = make_pair(make_pair(sum_w - S / min_c,-1), -1);
		ans = p;
	}
	for (int i = 0; i < M;++i){
		if (!e_used[i]) {
			auto e = e_col[i];
			if (min_c > e.c) {
				Weight p = t.lca(e.src, e.dst);
				auto nans = make_pair(make_pair(sum_w - p.first+ e.weight - S / e.c,p.second), i);
				ans = min(ans, nans);
			}
		}
	}
	cout << ans.first.first << endl;
	long long int sum = 0;
	long long int aa = -1;
	int ab = -1;
	int anum = 0, bnum = 0;
	long long int ac = -1;
	long long int ad = -1;
	vector<pair<int, long long int>>anss;
	if (ans.second == -1) {
		bool flag = false;
		for (int i = 0; i < M; ++i) {
			Edge e(e_col[i]);
			if (e_used[i]) {
				if (!flag&&e.c == min_c) {
					flag = true;
					anss.emplace_back(i + 1, e.weight - S / e.c);
					sum += e.weight - S / e.c;
				}
				else {
					anss.emplace_back(i + 1, e.weight);
					sum += e.weight;
				}
			}
		}
		if (!flag)assert(false);
	}
	else {
		for (int i = 0; i < M; ++i) {
			Edge e(e_col[i]);
			if (e_used[i]) {
				if (ans.first.second==i) {
					ab = i;
					ac = e.weight;
					anum++;
					continue;
				}
				else {
					anss.emplace_back(i + 1, e.weight);
					sum += e.weight;
				}
			}
			else if (ans.second == i) {
				bnum++;
				anss.emplace_back(i + 1, e.weight - S / e.c);
				aa = e.c;
				ad = S / e.c;
				sum += e.weight - S / e.c;
			}
		}
	}
	assert(anss.size() == N - 1);
	if (sum != ans.first.first) {
		cout << ans.first.first << " " << ans.first.second << " " << ans.second << endl;
		cout << sum << endl;
		cout << aa << endl;
		cout << ab << endl;
		cout << ac << endl;
		cout << ad << endl;
		cout << anum << endl << bnum << endl;
	}
	sort(anss.begin(), anss.end(), [](const pair<long long int, int>&l, const pair<long long int, int>&r) {
		return l.second < r.second; }
	);
	for (auto a : anss) {
		cout << a.first << " " << a.second << endl;
	}
	
	return 0;
}