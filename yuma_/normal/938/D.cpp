#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
using namespace std;

typedef long double ld;

int main() { 
	int N,M;cin>>N>>M;
	vector<vector<pair<int,long long int>>>graph(N);

	for(int i=0;i<M;++i){
		int a,b;scanf("%d %d",&a,&b);a--;b--;
		long long int cost;scanf("%lld",&cost);cost*=2;
		graph[a].push_back(make_pair(b,cost));
		graph[b].push_back(make_pair(a,cost));
	}
	priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int,int>>>que;
	vector<long long int>anss(N,1e18);
	for(int i=0;i<N;++i){
		long long int a;scanf("%lld",&a);
		que.push(make_pair(a,i));
		anss[i]=a;
	}
	while(!que.empty()){
		auto p(que.top());
		que.pop();
		int now(p.second);
		long long int now_cost(p.first);
		if(anss[now]!=now_cost)continue;
		for(int i=0;i<graph[now].size();++i){
			int next(graph[now][i].first);
			long long int next_cost(now_cost+graph[now][i].second);
			if(next_cost<anss[next]){
				anss[next]=next_cost;
				que.push(make_pair(next_cost,next));
			}
		}
	}

	for(int i=0;i<anss.size();++i){
		cout<<anss[i];
		if(i==anss.size()-1)cout<<endl;
		else cout<<" ";
	}
	return 0;

}