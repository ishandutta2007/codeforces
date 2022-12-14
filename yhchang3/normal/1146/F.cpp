#include<bits/stdc++.h>
using namespace std;
vector<int> edge[200001];
#define pll pair<long long int,long long int>
#define plll pair<pll,long long int>
const int mod = 998244353;

long long int ex(long long int x,long long int b){
	x%=mod;
	long long int res=1;
	while(b){
		if(b&1)
			res=res*x%mod;
		x=x*x%mod;
		b/=2;
	}
	return res;
}

plll dfs(int now){
	if(edge[now].size()==0)
		return {{0,1},0};
	if(edge[now].size()==1){
		plll tmp=dfs(edge[now][0]);
		return {{(tmp.first.first+tmp.first.second)%mod,0},(tmp.first.second+tmp.second)%mod};
	}
	vector<plll> v;
	v.clear();
	for(int i=0;i<edge[now].size();i++)
		v.push_back(dfs(edge[now][i]));
	long long int ret1=1,ret2=1,ret3=0;
	for(int i=0;i<v.size();i++)
		ret1=ret1*(v[i].first.first+v[i].first.second)%mod;
	for(int i=0;i<v.size();i++)
		ret3=(ret3+(v[i].second+v[i].first.second)%mod*ret1%mod*ex(v[i].first.first+v[i].first.second,mod-2))%mod;
	for(int i=0;i<v.size();i++)
		ret2=ret2*(v[i].first.first+v[i].first.second*2+v[i].second)%mod;
	ret2=(ret2-ret1-ret3+mod+mod)%mod;
	return {{ret1,ret2},ret3};
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=2,x;i<=n;i++){
		cin>>x;
		edge[x].push_back(i);
	}
	plll tmp=dfs(1);
//	cout<<tmp.first.first<<' '<<tmp.first.second<<' '<<tmp.second<<endl;
	cout<<(tmp.first.first+tmp.first.second)%mod<<endl;
}