#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;


namespace cent {

	struct Edge {
		int src;
		int dst;
		long long int cost;
	};
	using Graph = vector<vector<Edge>>;

	class Centroid {
	private:
		int dfs(const Graph&g, const int now, const int from, vector<int>&ch_nums, const vector<int>&oks) {
			int sum = 1;
			for (auto &&e : g[now]) {
				if (e.dst == from || oks[e.dst] != -1)continue;
				else {
					sum += dfs(g, e.dst, e.src, ch_nums, oks);
				}
			}
			return ch_nums[now] = sum;
		}

		int find_centroid(const int asize, const vector<vector<Edge>>&graph, const int pre_root, const int pre_from, const vector<int>&ch_nums, const vector<int>&oks) {
			for (auto&& e : graph[pre_root]) {
				if (e.dst == pre_from)continue;
				if (oks[e.dst] != -1)continue;
				if (ch_nums[e.dst]>asize / 2)return find_centroid(asize, graph, e.dst, e.src, ch_nums, oks);
			}
			return pre_root;
		}

		void dfs2(const Graph&g, const int root,const int now, const int from, const vector<int>&oks,int depth) {
			mp[make_pair(root,now)]=depth;
			for (auto &&e : g[now]) {
				if (e.dst == from || oks[e.dst] != -1)continue;
				else {
					dfs2(g,root,e.dst,e.src,oks,depth+1);
				}
			}
		};


		void cent(const vector<vector<Edge>>&graph, vector<int>&oks, const int root, const int from, vector<vector<int>>&centroid_edges, int& fst_centroid, int depth, vector<int>&ch_nums) {
			dfs(graph, root, from, ch_nums, oks);

			int cent_id = find_centroid(ch_nums[root], graph, root, from, ch_nums, oks);


			dfs2(graph,cent_id,cent_id,-1,oks,0);
			lens1[cent_id][make_pair(0,0)]--;
			lens2[cent_id][0]--;


			oks[cent_id] = depth;

			//for (auto&& e : graph[cent_id]) {
			//	if (e.dst == from)continue;
			//	if (oks[e.dst] != -1)continue;

			//	dfs2(graph, e.dst, e.dst, e.src, oks,e.cost%mod,e.cost%mod,1);

			//	for (auto&& l1 : lens1[e.dst]) {
			//		int keta = l1.first.second;
			//		long long int num = l1.first.first;

			//		long long int need = (mod - num) / mod_pow(10, keta);
			//		need%=mod;
			//		auto it = lens2[e.dst].find(need);
			//		if (it != lens2[e.dst].end()) {
			//			ans -= l1.second*it->second;
			//		}
			//	}
			//	lens1[e.dst].clear();
			//	lens2[e.dst].clear();
			//}

			if (from != -1) {
				centroid_edges[from].push_back(cent_id);
			}
			else {
				fst_centroid = cent_id;
			}
			for (auto&& e : graph[cent_id]) {
				if (e.dst == from)continue;
				if (oks[e.dst] != -1)continue;
				cent(graph, oks, e.dst, e.src, centroid_edges, fst_centroid, depth + 1, ch_nums);
			}
		}

	public:

		map<pair<int,int>,int>mp;

		vector<map<pair<long long int,int>, long long int>>lens1;
		vector<map<long long int, long long int>>lens2;
		vector<vector<int>> centroid_graph;
		vector<int>ts;
		vector<int>parents;
		vector<int>oks;
		vector<int>anss;

		//fst:root  snd:centroid_graph
		void init(const Graph&g) {
			lens1.resize(g.size());
			lens2.resize(g.size());
			oks = vector<int>(g.size(), -1);
			int root = -1;
			centroid_graph.resize(g.size());
			parents = vector<int>(g.size(), -1);
			ts=vector<int>(g.size(),-1);
			anss=vector<int>(g.size(),100000);

			vector<int>ch_nums(g.size());
			cent(g, oks, 0, -1, centroid_graph, root, 0, ch_nums);

			for (int i = 0; i < centroid_graph.size(); ++i) {
				for (auto&& e : centroid_graph[i]) {
					parents[e] = i;
				}
			}
			return ;
		}
	}centroid;


	void addEdge(Graph& g, int a, int b, long long int c) {
		g[a].push_back(Edge{ a,b,c });
		g[b].push_back(Edge{ b,a,c });
	}
}




int main()
{

	int N;cin>>N;
	int Q;cin>>Q;
	using namespace cent;
	Centroid cc;
	Graph graph(N);
	for (int i = 0; i < N-1; ++i) {
		int a,b,c;scanf("%d %d",&a,&b);a--;b--;
		addEdge(graph,a,b,1);
	}
	cc.init(graph);
	const int root=find(cc.parents.begin(),cc.parents.end(),-1)-cc.parents.begin();
	bool flag=false;Q++;
	while (Q--) {
		int t,a;
		if (flag) {
			cin >> t >> a; a--;
		}
		else {
			flag=true;
			t=1;
			a=0;
		}
		if (t == 1) {
			int now = a;
			int nk = 0;
			while (now != root) {
				cc.anss[now]=min(nk,cc.anss[now]);

				nk = cc.mp[make_pair(cc.parents[now], a)];
				now = cc.parents[now];
			}
			cc.anss[now] = min(nk, cc.anss[now]);
		}
		else {
			int ans=1e8;
			int now=a;
			int nk=0;
			while (now != root) {
				ans=min(cc.anss[now]+nk,ans);
				nk=cc.mp[make_pair(cc.parents[now],a)];
				now=cc.parents[now];
			}
			ans = min(cc.anss[now] + nk, ans);
			cout<<ans<<endl;
		}
	}
	return 0;
}