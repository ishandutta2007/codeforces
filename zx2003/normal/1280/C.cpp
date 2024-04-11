#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,k,i,sz[N],u,v,t;
ll ans1,ans2;
vector<pair<int,int>>e[N];
void dfs(int x,int fa){
	sz[x]=1;
	for(auto u:e[x]){
		int y=u.first,t=u.second;if(y==fa)continue;
		dfs(y,x);sz[x]+=sz[y];ans1+=sz[y]&1?t:0;ans2+=1ll*min(sz[y],k*2-sz[y])*t;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	for(cin>>T;T--;){
		cin>>k;
		ans1=ans2=0;for(i=1;i<=k*2;++i)e[i].clear();
		for(i=1;i<k*2;++i)cin>>u>>v>>t,e[u].push_back({v,t}),e[v].push_back({u,t});
		dfs(1,0);
		cout<<ans1<<' '<<ans2<<'\n';
	}
	return 0;
}