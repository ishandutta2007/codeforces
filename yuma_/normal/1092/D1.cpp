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
	vector<int>v(N);
	for(int i=0;i<N;++i)scanf("%d",&v[i]);
	int odd_plus=0;
	for (int i = 0; i < N; ++i) {
		if (v[i] % 2 == 1) {
			if(i%2)odd_plus++;
			else odd_plus--;
		}
	}
	bool ok;
	if (N % 2 == 1) {
		if(odd_plus==0||odd_plus==-1)ok=true;
		else ok=false;
	}
	else {
		if(odd_plus==0)ok=true;
		else ok=false;
	}
	if(ok)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}