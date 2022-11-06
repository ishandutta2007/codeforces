#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = long double;

//bool operator<(const vector<int>&l, const vector<int>&r) {
//	if(l.size()!=r.size())return l.size()<r.size();
//	else {
//		for (int i = 0; i < l.size(); ++i) {
//			if(l[i]!=r[i])return l[i]<r[i];
//		}
//		return false;
//	}
//}
int dfs(const vector<vector<int>>&edges,
	const vector<int>&querys,
	vector<int>&v,vector<pair<vector<int>,int>>&mp,
	const int now,const int from) {

	int sum=0;
	for (auto e : edges[now]) {
		if (e != from) {
			vector<int>now_v;
			int now_cnt=dfs(edges,querys,now_v,mp,e,now);
			sum+=now_cnt;
			v.insert(v.end(),now_v.begin(),now_v.end());
		}
	}
	v.push_back(now);
	if (querys[now] != -1) {
		int need=querys[now]-sum;
		if(need<0||need>v.size())throw(false);
		else {
			mp.push_back(make_pair(v,need));
			v.clear();
			return querys[now];
		}
	}
	else {
		return sum;
	}
}

typedef long long  Weight;
struct Edge {
	int src, dest;
	int cap, rev;
	Weight weight;
	bool operator < (const Edge &rhs) const { return weight > rhs.weight; }
};

const int V = 4000;
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;
Weight h[V];                //
Weight dist[V];             //
int prevv[V], preve[V];  //

void add_edge(Graph &g, int src, int dest, int cap, Weight weight) {
	g[src].push_back(Edge{ src, dest, cap, (int)g[dest].size(), weight });
	g[dest].push_back(Edge{ dest, src, 0, (int)g[src].size() - 1, -weight });
}
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(auto i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const Weight INF = 2147483647;
const Weight ZERO=0;
//doubleeps
Weight min_cost_flow(Graph &g, int s, int t, int f) {
	Weight res = ZERO;
	memset(h, ZERO, sizeof(h));
	typedef pair<Weight, int> P;
//
//REP(i, g.size() / 2 - 1) {
//	int v = i + 2;
//	REP(j, g[v].size()) {
//		Edge &e = g[v][j];
//		if (e.cap == 0) continue;
//		int u = e.dest;
//		h[u] = min(h[u], h[v] + e.weight);
//	}
//	v = i + g.size() / 2 + 1;
//	REP(j, g[v].size()) {
//		Edge &e = g[v][j];
//		if (e.cap == 0) continue;
//		int u = e.dest;
//		h[u] = min(h[u], h[v] + e.weight);
//	}
//}
	while (f > 0) {
		priority_queue<P, vector<P>, greater<P> > que;
		fill(dist, dist + V, INF);
		dist[s] = 0;
		que.push(P(ZERO, s));
		while (!que.empty()) {
			P p = que.top(); que.pop();
			const int v = p.second;
			if (dist[v] < p.first) continue;
			REP(i, g[v].size()) {
				Edge &e = g[v][i];
				if (e.cap > 0 && dist[e.dest] > dist[v] + e.weight + h[v] - h[e.dest]) {
					dist[e.dest] = dist[v] + e.weight + h[v] - h[e.dest];
					prevv[e.dest] = v;
					preve[e.dest] = i;
					que.push(P(dist[e.dest], e.dest));
				}
			}
		}
		if (dist[t] == INF) return -1;
		for(int v=0;v<V;++v) h[v] = h[v] + dist[v];

		int d = f;
		for (int v = t; v != s; v = prevv[v]) d = min(d, g[prevv[v]][preve[v]].cap);
		f -= d;
		res = res + d * h[t];
		for (int v = t; v != s; v = prevv[v]) {
			Edge &e = g[prevv[v]][preve[v]];
			e.cap -= d;
			g[v][e.rev].cap += d;
		}
	}
	return res;
}
int main() {
	int N;
	vector<int>roots(2);
	cin>>N>>roots[0]>>roots[1];
	roots[0]--;roots[1]--;
	vector<long long int>v(N);
	for (int i = 0; i < N; ++i) {
		scanf("%lld",&v[i]);
	}
	vector<vector<vector<int>>>edges(2,vector<vector<int>>(N,vector<int>()));
	for (int k = 0; k < 2; ++k) {
		for (int i = 0; i < N - 1; ++i) {
			int a, b; cin >> a >> b;
			a--; b--;
			edges[k][a].push_back(b);
			edges[k][b].push_back(a);
		}
	}
	vector<vector<int>>querys(2,vector<int>(N,-1));
	for (int k = 0; k < 2; ++k) {
		int Q;scanf("%d",&Q);
		for (int i = 0; i < Q; ++i) {
			int a,b;cin>>a>>b;a--;
			querys[k][a]=b;
		}
	}
	vector<vector<pair<vector<int>,int>>>mps(2);
	for (int k = 0; k < 2; ++k) {
		vector<int>v;
		try {
			dfs(edges[k], querys[k], v, mps[k], roots[k], -1);

		}
		catch (...) {
			cout<<-1<<endl;
			return 0;
		}
	}

	const int start=0;
	const int in_connects=start+1;
	const int in_node=in_connects+mps[0].size();
	const int out_node=in_node+N;
	const int out_connects=out_node+N;
	const int goal=out_connects+mps[1].size();

	Graph g(goal+1);
	for (int i = 0; i < mps[0].size(); ++i) {
		add_edge(g,start,in_connects+i,mps[0][i].second,0);
		for (auto t : mps[0][i].first) {
			add_edge(g,in_connects+i,in_node+t,1,0);
		}
	}
	for (int i = 0; i < N; ++i) {
		add_edge(g,in_node+i,out_node+i,1,100000-v[i]);
	}
	for (int i = 0; i < mps[1].size(); ++i) {
		for (auto t : mps[1][i].first) {
			add_edge(g, out_node+t,out_connects+i, 1, 0);
		}
		add_edge(g,out_connects+i,goal,mps[1][i].second,0);
	}

	int aflow=max(querys[0][roots[0]],querys[1][roots[1]]);
	long long int sum=min_cost_flow(g,start,goal,
		aflow);
	if(sum==-1)cout<<-1<<endl;
	else {
		cout<<100000ll*aflow-sum<<endl;
	}
	return 0;
}