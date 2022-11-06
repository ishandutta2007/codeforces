#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

map<int,pair<int,int>>summp;
int solve(int k){
	auto it=summp.lower_bound(k);
	if(it==summp.begin()){
		return 0;
	}
	if(prev(it)->second.second){
		return it->second.first-(it->first-k);
	}else{
		return it->second.first;
	}
}

int main() {
	int N,K,M;cin>>N>>K>>M;
	map<int,int>mp;
	for(int i=0;i<N;++i){
		int a,b;cin>>a>>b;
		mp[a]++;
		mp[b+1]--;
	}
	mp[2e9]=0;
	int prevt=-1,nowt;
	int prev=0,now;
	for(auto m:mp){
		nowt=m.first;
		summp[nowt]=summp[prevt];
		if(summp[prevt].second)summp[nowt].first+=(nowt-prevt);
		now=prev+m.second;
		summp[nowt].second=now>=K;
		prevt=nowt;
		prev=now;
	}
	while(M--){
		int a,b;cin>>a>>b;
		cout<<solve(b+1)-solve(a)<<endl;
	}
	return 0;
}