#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,mo=998244353;
inline int poww(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;
	return ans;
}
int n,u,v,i;
vector<pair<int,int>>e[N];
vector<int>g[N];int gg[N],f[N];
struct xint{
	int zcnt,x;
	inline void del(int v){if(!v)--zcnt;else x=1ll*x*poww(v,mo-2)%mo;}
	inline void ins(int v){if(!v)++zcnt;else x=1ll*x*v%mo;}
	inline operator int(){return zcnt?0:x;}
}X;
void dfs(int x,int fa){
	for(auto u:e[x])if(u.second!=fa)dfs(u.second,x);g[x].resize(e[x].size());
	X=(xint){0,1};
	for(auto u:e[x])if(u.second!=fa)X.ins(f[u.second]);
	for(int j=0;j<e[x].size();++j)if(e[x][j].second!=fa){
		int y=e[x][j].second,z1=0,z2=gg[y],i;
		X.del(f[y]);
		for(i=0;i<e[y].size() && e[y][i].first<=e[x][j].first;++i)z1=(z1+g[y][i])%mo;
		for(;i<e[y].size();++i)z2=(z2+g[y][i])%mo;
		g[x][j]=1ll*z2*X%mo;
		f[x]=(f[x]+g[x][j])%mo;
		X.ins(z1);
	}else g[x][j]=X;
	gg[x]=X;
	f[x]=(f[x]+gg[x])%mo;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;for(i=1;i<n;++i)cin>>u>>v,e[u].push_back(make_pair(i,v)),e[v].push_back(make_pair(i,u));
	dfs(1,0);cout<<f[1]<<endl;
	return 0;
}