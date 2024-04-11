#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

long long int costs[200010];
long long int ch_cnts[200010];
long long int answer=0;
void dfs2(const int now,long long int now_sum, const vector<vector<int>>&graph, int from) {
	answer=max(answer,now_sum);

	for (auto e : graph[now]) {
		if(e==from)continue;
		dfs2(e,now_sum+ch_cnts[0]-ch_cnts[e]*2,graph,now);
	}
}
long long int dfs(const int now, const vector<vector<int>>&graph, int depth,int from) {
	long long int sum=depth*costs[now];
	ch_cnts[now]=costs[now];
	for (auto e : graph[now]) {
		if(e==from)continue;
		sum+=dfs(e,graph,depth+1,now);
		ch_cnts[now]+=ch_cnts[e];
	}
	return sum;
}

int main()
{
	int N;cin>>N;
	for (int i = 0; i < N; ++i) {
		scanf("%lld",&costs[i]);
	}
	vector<vector<int>>graph(N);
	for (int i = 0; i < N-1; ++i) {
		int a,b;scanf("%d %d",&a,&b);
		a--;b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	long long int now_sum=dfs(0,graph,0,-1);
	dfs2(0,now_sum,graph,-1);
	cout<<answer<<endl;
	return 0;
}