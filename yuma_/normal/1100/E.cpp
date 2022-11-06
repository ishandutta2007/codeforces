#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

struct Edge {
	int id;
	int src;
	int dst;
	int cost;
};

vector<int>mk_places(int N, const vector<vector<Edge>>&graph,int amid) {
	vector<int>comes(N);
	for (int i = 0; i < N; ++i) {
		for (auto e : graph[i]) {
			if (e.cost > amid) {
				comes[e.dst]++;
			}
		}
	}
	queue<int>que;
	int id = 0;
	vector<int>places(N);
	for (int i = 0; i < N; ++i) {
		if (!comes[i]) {
			que.push(i);
		}
	}
	while (!que.empty()) {
		int now = que.front();
		que.pop();
		places[now] = id++;
		for (auto e : graph[now]) {
			if(e.cost<=amid)continue;
			comes[e.dst]--;
			assert(comes[e.dst] >= 0);
			if (comes[e.dst] == 0) {
				que.push(e.dst);
			}
		}
	}
	if (all_of(comes.begin(), comes.end(), [](const int a) {return a == 0; })) {
		return places;
	}
	else {
		vector<int>dummy;
		return dummy;
	}
}
int main() {
	int N,M;cin>>N>>M;
	vector<vector<Edge>>graph(N);
	for (int i = 0; i < M; ++i) {
		int u,v,c;
		scanf("%d %d %d",&u,&v,&c);u--;v--;
		graph[u].push_back(Edge{i, u,v,c });
	}
	int amin=-1;
	int amax=1e9+10;
	while (amin + 1 != amax) {
		int amid=((amin+amax)/2);
		vector<int>used(N);
		vector<int>av=mk_places(N,graph,amid);
		bool ok=!av.empty();
		if (ok) {
			amax=amid;
		}
		else {
			amin=amid;
		}
	}

	int ans_cost = amax;
	vector<int>places=mk_places(N,graph,amax);
	vector<int>ans_edge_ids;
	for (int i = 0; i < N; ++i) {
		for (auto e : graph[i]) {
			if (places[e.src] > places[e.dst]) {
				ans_edge_ids.push_back(e.id+1);
			}
		}
	}
	cout<<ans_cost<<" "<<ans_edge_ids.size()<<endl;
	for (int i = 0; i < ans_edge_ids.size(); ++i) {
		printf("%d ",ans_edge_ids[i]);
	}
	cout<<endl;
	return 0;
}