#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

vector<vector<pair<int,long long int>>>tree;
vector<int>back_ids;

namespace lca_tree {

	using Edge=pair<int,long long int>;

	class Tree {
	public:
		Tree(int V, int root) : root(root), cnum(V), place(V), id(V) {
			T.resize(V);
			for (int i = 0; i < MAXLOGV; i++) {
				parent[i].resize(V);
			}
			depth.resize(V);
			lens.resize(V);
		}

		// init
		void init(const vector<vector<Edge>>&e) {
			T = e;
			dfs(root, 0, 0,0);
			int id = 0;
			getid(root, 0, id);
		}
		// uvlca
		int lca(int u, int v) const {
			if (depth[u] > depth[v]) swap(u, v);
			for (int k = 0; k < MAXLOGV; k++) {
				if ((depth[v] - depth[u]) >> k & 1) {
					v = parent[k][v];
				}
			}
			if (u == v) return u;
			for (int k = MAXLOGV - 1; k >= 0; k--) {
				if (parent[k][u] != parent[k][v]) {
					u = parent[k][u];
					v = parent[k][v];
				}
			}
			return parent[0][u];
		}
		//// uv
		//// edge
		long long int dist(int u, int v) const {
			int p = lca(u, v);
			return (lens[u] - lens[p]) + (lens[v] - lens[p]);
		}
		int dfs(int v, int p,int d,long long int l) {
			parent[0][v] = p;
			depth[v] = d;
			lens[v]=l;
			cnum[v] = 0;
			for (int i = 1; i < MAXLOGV; i++) {
				parent[i][v] = parent[i - 1][parent[i - 1][v]];
			}
			for (auto anext : T[v]) {
				int next=anext.first;
				if (next != p) cnum[v] += dfs(next, v, d + 1,l+anext.second);
			}
			return cnum[v] + 1;
		}

		void getid(const int v, const int p, int &nplace) {
			place[v] = nplace;
			id[nplace] = v;
			nplace++;
			for (auto anext : T[v]) {
				int next=anext.first;
				if (next != p) getid(next, v, nplace);
			}
		}
		static const int MAXLOGV = 25;
		// 
		vector<vector<Edge> > T;

		// 
		int root;

		// 
		vector<int> parent[MAXLOGV];
		// ()
		vector<int> depth;
		//()
		vector<long long int>lens;

		//
		vector<int>cnum;

		//
		vector<int>place;
		vector<int>id;

	};
}

void dfs(const int now, const int from, const vector<vector<pair<int, int>>>&edges,vector<int>&used) {
	used[now]=true;
	for (auto e : edges[now]) {
		if(e.first==from)continue;
		else {
			if (used[e.first]) {
				back_ids.push_back(now);
				back_ids.push_back(e.first);
			}
			else {
				tree[now].push_back(e);
				dfs(e.first,now,edges,used);
			}
		}
	}
}

int main() {
	int N,M;cin>>N>>M;
	vector<vector<pair<int,int>>>edges(N);
	for (int i = 0; i < M; ++i) {
		int a,b,c;scanf("%d %d %d",&a,&b,&c);
		a--;b--;
		edges[a].push_back(make_pair(b,c));
		edges[b].push_back(make_pair(a,c));
	}
	tree.resize(N);
	vector<int>used(N);
	dfs(0,-1,edges,used);

	lca_tree::Tree t(N,0);
	t.init(tree);

	sort(back_ids.begin(),back_ids.end());
	back_ids.erase(unique(back_ids.begin(),back_ids.end()),back_ids.end());

	vector<vector<long long int>>lens(back_ids.size(),vector<long long int>(back_ids.size(),1e18));
	for (int i = 0; i < N; ++i) {
		for (auto e : edges[i]) {
			auto it=find(back_ids.begin(),back_ids.end(),i);
			auto jt=find(back_ids.begin(),back_ids.end(),e.first);
			if (it != back_ids.end() && jt != back_ids.end()) {
				lens[it-back_ids.begin()][jt-back_ids.begin()]=e.second;
			}
		}
	}

	for (int i = 0; i < back_ids.size(); ++i) {
		for (int j = 0; j < back_ids.size(); ++j) {
			long long int acost=t.dist(back_ids[i],back_ids[j]);
			lens[i][j]=min(lens[i][j],acost);
		}
	}
	for (int k = 0; k < back_ids.size(); ++k) {
		for (int i = 0; i < back_ids.size(); ++i) {
			for (int j = 0; j < back_ids.size(); ++j) {
				lens[i][j]=min(lens[i][j],lens[i][k]+lens[k][j]);
			}
		}
	}
	 
	int Q;cin>>Q;
	while (Q--) {
		int a,b;scanf("%d %d",&a,&b);
		a--;b--;
		long long int acost=1e18;
		acost=t.dist(a,b);
		vector<long long int>a_costs(back_ids.size()),b_costs(back_ids.size());
		for (int i = 0; i < back_ids.size(); ++i) {
			a_costs[i]=t.dist(a,back_ids[i]);
			b_costs[i]=t.dist(b,back_ids[i]);
		}
		for (int i = 0; i < back_ids.size(); ++i) {
			for (int j = 0; j < back_ids.size(); ++j) {
				long long int now_cost=lens[i][j];
				now_cost+=a_costs[i]+b_costs[j];
				acost=min(acost,now_cost);
			}
		}
		printf("%lld\n",acost);
	}
	return 0;
}