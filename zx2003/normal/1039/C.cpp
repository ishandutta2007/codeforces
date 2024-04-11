#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mo=1e9+7,N=5e5+5;
int n,m,k,i,x,y,z,ans,mi[N];
ll c[N];
unordered_map<ll,vector<pair<int,int>>>mp;
vector<int>e[N];
bool vi[N];
void dfs(int x){vi[x]=1;for(int y:e[x])if(!vi[y])dfs(y),--z;}
int main(){
	for(i=*mi=1;i<N;++i)mi[i]=2*mi[i-1]%mo;
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m>>k;
	for(i=1;i<=n;++i)cin>>c[i];
	for(i=1;i<=m;++i)cin>>x>>y,mp[c[x]^c[y]].push_back({x,y});
	ans=((1ll<<k)-mp.size())%mo*mi[n]%mo;
	for(auto u:mp){
		z=n;
		for(auto e:u.second)tie(x,y)=e,::e[x].push_back(y),::e[y].push_back(x);
		for(auto e:u.second){tie(x,y)=e;if(!vi[x])dfs(x);}
		ans=(ans+mi[z])%mo;
		for(auto e:u.second)tie(x,y)=e,::e[x].clear(),::e[y].clear(),vi[x]=vi[y]=0;
	}
	printf("%d\n",ans);
	return 0;
}