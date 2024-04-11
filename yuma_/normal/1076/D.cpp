#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
struct Edge{
	int id;
	int src;
	int dst;
	long long int cost;
};
struct aa {
	int now;
	long long int cost;

};
class Compare {
public:
	bool operator()(const aa&l, const aa&r)const  {
		return l.cost>r.cost;
	}
};

int main()
{
	int N,M,K;cin>>N>>M>>K;
	vector<vector<Edge>>graph(N);
	vector<Edge>edges;
	for (int i = 0; i < M; ++i) {
		int a,b,c;scanf("%d %d %d",&a,&b,&c);
		a--;b--;
		graph[a].push_back(Edge{i, a,b,c });
		graph[b].push_back(Edge{ i,b,a,c });
		edges.push_back(Edge{ i,a,b,c });
	}

	priority_queue<aa,vector<aa>,Compare>que;
	vector<long long int>memo(N,1e18);
	vector< int>prev_ids(N,-1);
	memo[0]=0;
	que.push(aa{ 0,0 });

	while (!que.empty()) {
		auto atop(que.top());
		que.pop();
		if(memo[atop.now]!=atop.cost)continue;
		for (auto e : graph[atop.now]) {
			long long int next_cost=atop.cost+e.cost;
			if (next_cost < memo[e.dst]) {
				memo[e.dst]=next_cost;
				prev_ids[e.dst]=e.id;
				que.push(aa{ e.dst,next_cost });
			}
		}
	}
	vector<pair<long long int,int>>use_ids;
	for (int i = 1; i < N; ++i) {
		use_ids.push_back(make_pair(memo[i],prev_ids[i]));
	}
	sort(use_ids.begin(),use_ids.end());
	vector<int>ans_ids;
	for (int i = 0; i < use_ids.size(); ++i) {
		ans_ids.push_back(use_ids[i].second+1);
	}
	if(ans_ids.size()>K)ans_ids.resize(K);
	cout<<ans_ids.size()<<endl;
	for(auto id:ans_ids)printf("%d ",id);
	cout<<endl;
	return 0;
}