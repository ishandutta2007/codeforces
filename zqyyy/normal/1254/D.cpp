#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=150007,mod=998244353;
int Inv(int x){return x==1?1:mod-1ll*(mod/x)*Inv(mod%x)%mod;}
inline void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
int n,Q,s_dfn,sz[N],dfn[N],low[N],inv;
vector<int>G[N];
vector<pair<int,int> >vec[N];
void dfs(int x,int fa){
	sz[x]=1,dfn[x]=++s_dfn;
	for(int y:G[x])if(y^fa)dfs(y,x),sz[x]+=sz[y],vec[x].push_back({low[y],y});
	low[x]=s_dfn;
}
struct b1t{
	int c[N];
	inline void Add(int p,int x){for(;p<=n;p+=p&-p)add(c[p],x);}
	inline void modify(int l,int r,int x){Add(l,x),Add(r+1,mod-x);}
	inline int ask(int p){int res=0;for(;p;p^=p&-p)add(res,c[p]);return res;}
}T;
int sum,tot,p[N],d[N],a[N];
inline int query(int x,int y){
	if(x==y)return 0;
	if(dfn[x]<dfn[y] || low[y]<dfn[x])return 1ll*(n-sz[y])*inv%mod;
	return 1ll*sz[lower_bound(vec[y].begin(),vec[y].end(),make_pair(dfn[x],0))->second]*inv%mod;
}
inline void work(int Q){
	tot=0;
	for(int i=1;i<=Q;i++){
		int opt=read();
		if(opt==1)p[++tot]=read(),d[tot]=read(),add(sum,d[tot]),add(a[p[tot]],d[tot]);
		else{
			int x=read(),ans=(sum+mod-T.ask(dfn[x]))%mod;
			for(int j=1;j<=tot;j++)add(ans,mod-1ll*d[j]*query(x,p[j])%mod);
			printf("%d\n",ans);
		}
	}
	for(int x=1;x<=n;x++)
		if(a[x]){
			for(int y:G[x])
				if(sz[x]<sz[y])T.modify(1,dfn[x]-1,1ll*a[x]*(n-sz[x])%mod*inv%mod),T.modify(low[x]+1,n,1ll*a[x]*(n-sz[x])%mod*inv%mod);
				else T.modify(dfn[y],low[y],1ll*a[x]*sz[y]%mod*inv%mod);
			a[x]=0;
		}
}
int main(){
	n=read(),Q=read(),inv=Inv(n);
	for(int i=1,x,y;i<n;i++)x=read(),y=read(),G[x].push_back(y),G[y].push_back(x);
	dfs(1,0);
	int B=sqrt(Q);
	while(Q){int x=min(B,Q);work(x);Q-=x;}
	return 0;
}