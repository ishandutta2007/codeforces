#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

struct Edge {
	int src;
	int dst;
	int id;
};

// res: bridges
// v: current node
// from_id: parent edge
int bri_dfs(vector<vector<Edge>>&g, vector<int>& res, int now_node, int& count, int from_id, vector<int>& low, vector<int>& pre) {
	pre[now_node] = count++;
	low[now_node] = pre[now_node];
	for (auto it = g[now_node].begin(); it != g[now_node].end(); it++) {
		int to = it->dst;
		if (pre[to] == -1) {
			// destination has not been visited
			// visit destination and update low[now_node]
			low[now_node] = min(low[now_node], bri_dfs(g, res, to, count, it->id, low, pre));
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
		bri_dfs(g, res, 0, count, -1, low, pre);  // start dfs from vertex 0
	}
}


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

int main() {
	int N,M;cin>>N>>M;
	vector<vector<Edge>>edges(N);
	vector<Edge>es;
	int id=0;
	for (int i = 0; i < M; ++i) {
		int a,b;
		scanf("%d %d",&a,&b);
		a--;b--;
		edges[a].push_back(Edge{ a,b,id });

		edges[b].push_back(Edge{ b,a,id });
		id++;
		es.push_back(Edge{ a,b,id });
	}
	vector<int>res(id);;
	bridges(edges,N,res);

	UnionFind uf(N+M);
	for (int i = 0; i < M; ++i) {
		auto e(es[i]);
		if (!res[i]) {
			uf.unionSet(e.src,e.dst);
		}
	}
	vector<pair<int,int>>ps(N+M,make_pair(1e9,-1));
	for (int i = 0; i < N; ++i) {
		ps[uf.root(i)]=make_pair(min(ps[uf.root(i)].first,i),max(ps[uf.root(i)].second,i));
	}
	{
		vector<pair<int,int>>newps;
		for (auto p : ps) {
			if (p.second != -1&&p.first!=p.second) {
				newps.push_back(p);
			}
		}
		ps=newps;
		sort(ps.begin(),ps.end());
	}
	vector<int>ns(ps.size()+1);
	ns.back()=N;
	for (int i = int(ps.size())-1; i >=0; --i) {
		
		ns[i]=min(ps[i].second,ns[i+1]);
		
	}
	vector<int>max_rs(N);
	for (int i = 0; i < N; ++i) {
		auto it=lower_bound(ps.begin(),ps.end(),make_pair(i,-1));
		
		max_rs[i]=ns[it-ps.begin()];
	}

	vector<long long int>sums(N+1);
	sums[0]=0;
	for (int i = 1; i <= N; ++i) {
		sums[i]=sums[i-1]+(max_rs[i-1]-i+1);
	}

	int Q;cin>>Q;
	while (Q--) {
		int aa,bb;
		scanf("%d %d",&aa,&bb);
		long long int a,b;a=aa;b=bb;
		auto it=upper_bound(max_rs.begin()+a-1,max_rs.begin()+b,b);

		long long int c=it-max_rs.begin();
		long long int ans=sums[c]-sums[a-1]+(b-c)*(b-c+1)/2;
		cout<<ans<<endl;
	}

	return 0;
}