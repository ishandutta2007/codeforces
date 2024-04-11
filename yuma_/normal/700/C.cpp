#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.txt"

//
struct Edge {
	int src;
	int dst;
	long long int cost;
	int id;
};
int s, t;
vector<vector<Edge>>edges;
int banid;

void dfs(const int now, const int from_id,vector<int>&comes,vector<int>&anss) {
	if (comes[now])return ;
	comes[now] = true;
	for (auto e : edges[now]) {
		if (e.id == banid)continue;
		if (e.id == from_id)continue;
		else {
			if (e.dst == t) {
				anss= vector<int>(1, e.id);
				return;
			}
			else {
				dfs(e.dst, e.id,comes,anss);
				if (!anss.empty()) {
					anss.emplace_back(e.id);
					return;
				}
			}
		}
	}
	return;
}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;

// res: bridges
// v: current node
// from: parent node
int dfs2(vector<vector<Edge>>&g, vector<int>& res, int v, int& count, int from_id, VI& low, VI& pre) {
	pre[v] = count++;
	low[v] = pre[v];
	for (auto it = g[v].begin(); it != g[v].end(); it++) {
		if (it->id == banid)continue;
		int to = it->dst;
		if (pre[to] == -1) {
			// destination has not been visited
			// visit destination and update low[v]
			low[v] = min(low[v], dfs2(g, res, to, count,it->id, low, pre));
			if (low[to] == pre[to]) {
				// edge is not contained in a closed path -> bridge
				//res.push_back(it->id);
				res[it->id] = true;
			}
		}
		else {
			if (from_id == it->id) {
				// ignore a path to parent
				continue;
			}
			low[v] = min(low[v], low[to]);
		}
	}
	return low[v];
}

// Calculate bridges in a undirected graph.
// Assume graph is connected and has no parallel edges or self-loops.
// g: adjacency list
// V: number of nodes
void  bridges(vector<vector<Edge>>&g, int V,vector<int>&res) {

	if (V > 0) {
		// assume at least the first vertex exists
		VI low(V, -1);  // lowest reacheable index
		VI pre(V, -1);  // pre-order index
		int count = 0;  // pre-order index counter
		dfs2(g, res,s, count, -1, low, pre);  // start dfs from vertex 0
	}
}

int main() {
	banid = -1;
	int N, M; cin >> N >> M;
	edges.resize(N);
	 cin >> s >> t; s--; t--;
	vector<Edge>eids;
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b; a--; b--; long long int w; cin >> w;
		Edge e{ a,b,w,i };
		Edge reve{ b,a,w,i };
		edges[a].push_back(e);
		edges[b].push_back(reve);
		eids.push_back(e);
	}
	vector<int>comes(N);
	vector<int>v;
	dfs(s,-1,comes,v);
	sort(v.begin(), v.end(), [=](const int l, const int r) {
		return eids[l].cost < eids[r].cost;
	});
	long long int ans = 2e9+1;
	vector<int>ids;
	if (v.empty()) {
		ans = 0;

	}
	else {
		for (int i = 0; i < v.size(); ++i) {
			banid = v[i];
			int bancost = eids[banid].cost;
			if (bancost >= ans)continue;
			vector<int>bris(eids.size());
			bridges(edges, N,bris);
			
			vector<int>acomes(N);
			vector<int>av;
			dfs(s, -1,acomes,av);
			if (av.empty()) {
				const int ncost = bancost;
				if (ans > ncost) {
					ans = ncost;
					ids = vector<int>{ banid };
				}
			}
			
			for (int j = 0; j < av.size(); ++j) {
				if (bris[av[j]]) {
					const int ncost = bancost + eids[av[j]].cost;
					if (ans > ncost) {
						ans = ncost;
						ids = vector<int>{ banid,av[j] };
					}
				}
			}
		}
	}
	if (ans == 2e9 + 1) {
		cout << -1 << endl;
	}
	else {
		cout << ans << endl;
		cout << ids.size() << endl;
		for (int i = 0; i < ids.size(); ++i) {
			printf("%d", ids[i] + 1);
			//cout << ids[i] + 1;
			if (i == ids.size() - 1)printf("\n");
			else printf(" ");
		}

	}
	
	
	
	return 0;
}