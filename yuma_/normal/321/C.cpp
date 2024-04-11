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
	long long int cost;
};
using Graph=vector<vector<Edge>>;

class Centroid {
public:
	int dfs(const Graph&g, const int now, const int from, vector<int>&ch_nums, const vector<int>&oks) {
		int sum = 1;
		for (auto &&e : g[now]) {
			if (e.dst == from || oks[e.dst]!=-1)continue;
			else {
				sum += dfs(g, e.dst, e.src, ch_nums,oks);
			}
		}
		return ch_nums[now] = sum;
	};


	int find_centroid(const int asize, const vector<vector<Edge>>&graph, const int pre_root, const int pre_from, const vector<int>&ch_nums, const vector<int>&oks) {
		for (auto&& e : graph[pre_root]) {
			if (e.dst == pre_from)continue;
			if (oks[e.dst]!=-1)continue;
			if (ch_nums[e.dst]>asize / 2)return find_centroid(asize, graph, e.dst, e.src, ch_nums, oks);
		}
		return pre_root;
	}

	//void dfs2(const Graph&g, const int now, const int from,vector<long long int>&lens,const int root_id, long long int nlen) {
	//	lens.push_back(nlen);
	//	mp[make_pair(root_id,now)]=nlen;
	//	for (auto &&e : g[now]) {
	//		if (e.dst == from || oks[e.dst] != -1)continue;
	//		else {
	//			dfs2(g,e.dst,e.src,lens,root_id,nlen+e.cost);
	//		}
	//	}
	//}

	void cent(const vector<vector<Edge>>&graph, vector<int>&oks, const int root, const int from, vector<vector<int>>&centroid_edges, int& fst_centroid,int depth,vector<int>&ch_nums) {
dfs(graph, root, from, ch_nums, oks);

		int cent_id = find_centroid(ch_nums[root], graph, root, from, ch_nums, oks);

		
		//dfs2(graph,cent_id,from,lens[cent_id],0);
		sort(lens[cent_id].begin(),lens[cent_id].end());

		oks[cent_id] = depth;
		if (from != -1) {
			centroid_edges[from].push_back(cent_id);
		}
		else {
			fst_centroid = cent_id;
		}
		for (auto e : graph[cent_id]) {
			if (e.dst == from)continue;
			if (oks[e.dst]!=-1)continue;
			cent(graph, oks, e.dst, e.src, centroid_edges, fst_centroid,depth+1,ch_nums);
		}
	}

public:


	vector<vector<long long int>>lens;
	vector<vector<int>> centroid_graph;
	vector<int>parents;
	vector<int>oks;
	map<pair<int,int>,long long int>mp;

	//fst:root  snd:centroid_graph
	vector<vector<int>> get_cent_parent(const Graph&g) {
		lens.resize(g.size());
		oks=vector<int>(g.size(),-1);
		int root = -1;
		centroid_graph.resize(g.size());
		parents=vector<int>(g.size(),-1);
		vector<int>ch_nums(g.size());
		cent(g, oks, 0, -1, centroid_graph, root,0,ch_nums);

		for (int i = 0; i < centroid_graph.size(); ++i) {
			for (auto&& e : centroid_graph[i]) {
				parents[e] = i;
			}
		}
		return centroid_graph;
	}
}centroid;


void addEdge(Graph& g ,int a, int b,long long int c) {
	g[a - 1].push_back(Edge{ a - 1,b - 1,c });
	g[b - 1].push_back(Edge{ b - 1,a - 1,c });
}


// driver function
int main()
{
	int N,Q;cin>>N;
	Graph graph(N);
	for (int i = 0; i < N-1; ++i) {
		int a,b;
		scanf("%d %d",&a,&b);
		int c=1;
		//long long int c;cin>>c;
		addEdge(graph,a,b,c);
	}
	centroid.get_cent_parent(graph);
	vector<int>anss;
	for (int i = 0; i < N; ++i) {
		anss.push_back(centroid.oks[i]);
		cout<<char('A'+centroid.oks[i])<<" ";
	}
	cout<<endl;
	return 0;
}