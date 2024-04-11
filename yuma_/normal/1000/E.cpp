#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

struct Edge {
	int id;
	int src;
	int dst;
	int num;
};

// res: bridges
// v: current node
// from_id: parent edge
int bri_dfs(vector<int>&oks, vector<vector<Edge>>&g, vector<int>& res, int now_node, int& count, int from_id, vector<int>& low, vector<int>& pre) {
	if (oks[now_node])return 0;
	else oks[now_node] = true;
	pre[now_node] = count++;
	low[now_node] = pre[now_node];
	for (auto it = g[now_node].begin(); it != g[now_node].end(); it++) {
		int to = it->dst;
		if (pre[to] == -1) {
			// destination has not been visited
			// visit destination and update low[now_node]
			low[now_node] = min(low[now_node], bri_dfs(oks, g, res, to, count, it->id, low, pre));
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
			low[now_node] = min(low[now_node], low[to]);
		}
	}
	return low[now_node];
}

// Calculate bridges in a undirected graph.
// Assume graph is connected and has no parallel edges or self-loops.
// g: adjacency list
// V: number of nodes
void  bridges(vector<vector<Edge>>&g, int V, vector<int>&res) {

	if (V > 0) {
		// assume at least the first vertex exists
		vector<int> low(V, -1);  // lowest reacheable index
		vector<int> pre(V, -1);  // pre-order index
		int count = 0;  // pre-order index counter
		vector<int>oks(V);
		for (int k = 0; k<V; ++k)bri_dfs(oks, g, res, k, count, -1, low, pre);  // start dfs from vertex 0
	}
}

pair<int,int> dfs(const vector<vector<Edge>>&graph, int start) {
	vector<int>v(graph.size(),1e7);
	priority_queue<pair<int,int>>que;
	que.push(make_pair(0,start));
	v[start]=0;
	while (!que.empty()) {
		auto p(que.top());
		que.pop();
		int now=p.second;
		int cost=-p.first;
		for (auto e : graph[now]) {
			int next_cost=cost+e.num;
			if (v[e.dst] > next_cost) {
				v[e.dst]=next_cost;
				que.push(make_pair(-next_cost,e.dst));
			}
		}
	}
	pair<int,int>ans(-1,-1);
	for (int i = 0; i < graph.size(); ++i) {
		auto p=make_pair(v[i],i);
		ans=max(ans,p);
	}
	return ans;
}
int main() {
	int N,M;cin>>N>>M;

	vector<vector<Edge>>edges(N);
	for (int i = 0; i < M; ++i) {
		int a,b;cin>>a>>b;
		a--;b--;
		edges[a].push_back(Edge{ i,a,b,0 });
		edges[b].push_back(Edge{ i,b,a,0 });
	}
	vector<int>valids(M);
	bridges(edges, N, valids);
	for (int i = 0; i < N; ++i) {
		for (auto&e : edges[i]) {
			if (valids[e.id]) {
				e.num=1;
			}
		}
	}

	auto p=dfs(edges,0);
	auto pp=dfs(edges,p.second);

	cout<<pp.first<<endl;

	return 0;
}