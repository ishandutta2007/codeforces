#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;

int answer=0;
int blue_cnt,red_cnt;

pair<int, int>dfs(int now, int from, const vector<vector<int>>&edges,
	const vector<int>&colors) {

	int now_red_cnt=0;
	int now_blue_cnt=0;
	for (auto e : edges[now]) {
		if(e==from)continue;
		else {
			auto p=dfs(e,now,edges,colors);
			now_red_cnt+=p.first;
			now_blue_cnt+=p.second;
		}
	}
	if(colors[now]==1)now_red_cnt++;
	if(colors[now]==2)now_blue_cnt++;
	if(now_red_cnt==0&&now_blue_cnt==blue_cnt)answer++;
	else if(now_red_cnt==red_cnt&&now_blue_cnt==0)answer++;

	return make_pair(now_red_cnt,now_blue_cnt);
}

int main() {
	int N;cin>>N;
	vector<int>colors(N);
	for(int i=0;i<N;++i)scanf("%d",&colors[i]);
	vector<vector<int>>edges(N);
	for (int i = 0; i < N - 1; ++i) {
		int u,v;scanf("%d %d",&u,&v);
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	blue_cnt=count(colors.begin(),colors.end(),2);
	red_cnt=count(colors.begin(),colors.end(),1);
	dfs(0,-1,edges,colors);
	cout<<answer<<endl;
	return 0;
}