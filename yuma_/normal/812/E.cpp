#include <bits/stdc++.h>
using namespace std;

int max_depth=0;
void dfs(const vector<int>&as,const int now,const int depth,
const vector<vector<int>>&edges,map<int,long long int>&plusmp,map<int,long long int>&zeromp){
	if(edges[now].empty()){
		max_depth=max(max_depth,depth);
	}
	for(auto e:edges[now]){
		dfs(as,e,depth+1,edges,plusmp,zeromp);
	}
	if(depth%2){
		plusmp[as[now]]++;
	}else{
		zeromp[as[now]]++;
	}
}
int main() {
	int N;cin>>N;
	vector<int>as;
	vector<vector<int>>edges(N);
	for(int i=0;i<N;++i){
		int a;cin>>a;
		as.emplace_back(a);
	}
	for(int i=0;i<N-1;++i){
		int a;cin>>a;
		edges[a-1].push_back(i+1);
	}
	map<int,long long int>plusmp,zeromp;
	dfs(as,0,0,edges,plusmp,zeromp);
	if(!(max_depth%2)){
		swap(plusmp,zeromp);
	}
	int axor=0;
	long long int zeronum=0,plusnum=0;
	for(auto m:plusmp){
		if(m.second%2)axor^=m.first;
		plusnum+=m.second;
	}
	zeronum=N-plusnum;
	long long int ans=0;
	if(axor==0){
		ans+=zeronum*(zeronum-1)/2;
		ans+=plusnum*(plusnum-1)/2;
	}
	for(auto pm:plusmp){
		if(zeromp.find(pm.first^axor)!=zeromp.end()){
			ans+=pm.second*zeromp[pm.first^axor];
		}
	}
	cout<<ans<<endl;
	return 0;
}