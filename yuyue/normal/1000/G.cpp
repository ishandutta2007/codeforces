#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
#define oo(x) fixed<<setprecision(x)
using namespace std;
LL read(){
    char ch=getchar(); LL w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=3e5+10;
struct edge{
	int y,v;
	edge (int _=0,int __=0){
		y=_; v=__; 
	}
};
vector<edge> v[M];
int a[M],n,m,q,dep[M];
LL dp[M],g[M][20],dis[M],s[M],lmx[M];
int f[M][20],lg[M],pre[M];
void dfs(int x,int fa){ 
	dep[x]=dep[fa]+1; s[x]=s[fa]+a[fa]; f[x][0]=fa; dp[x]=a[x];
//	cout<<lmx[x]<<" "<<x<<" fuck?\n";
	F(i,1,lg[dep[x]]) f[x][i]=f[f[x][i-1]][i-1];
	F(i,0,SZ(v[x])){
		int y=v[x][i].y; 
		if (y==fa) continue; 
		dis[y]=dis[x]+v[x][i].v; pre[y]=v[x][i].v; dfs(y,x);
		dp[x]=max(dp[x],dp[x]+dp[y]-2ll*v[x][i].v);
	}
	F(i,0,SZ(v[x])){
		int y=v[x][i].y; 
		if (y==fa) continue; 
		g[y][0]=dp[x]-max(0ll,dp[y]-2ll*v[x][i].v)-2ll*pre[y];
	}
}
LL ret=0;
void dd(int x,int fa){
	lmx[x]=max(0ll,lmx[fa]+g[x][0]);
//	cout<<x<<" "<<lmx[x]<<"    yysb\n";
	F(i,0,SZ(v[x])){
		int y=v[x][i].y; 
		if (y==fa) continue; 
		dd(y,x);
	}
}
int lca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int del=dep[x]-dep[y],op=x,opp=y; ret=0;
	F(i,0,lg[del]) if (del>>i&1) ret+=g[x][i],x=f[x][i];
	if (x==y) {
//		cout<<ret<<" "<<lmx[x]<<"    mdfuc\n"; 
		ret+=lmx[x]+dp[op]; 
		return x;
	}
	DF(i,lg[dep[x]],0){
		if (f[x][i]^f[y][i]){
			ret+=g[x][i]+g[y][i]; 
			x=f[x][i]; y=f[y][i];
		}
	}
//	cout<<dp[f[x][0]]<<"\n";
//	cout<<lmx[f[x][0]]<<" "<<dp[op]<<" "<<dp[opp]<<" "<<dp[f[x][0]]-max(0ll,dp[x]-2ll*pre[x])-max(0ll,dp[y]-2ll*pre[y])<<" "<<ret<<"     yyyyy\n";
	ret+=dp[op]+dp[opp]+dp[f[x][0]]-max(0ll,dp[x]-2ll*pre[x])-max(0ll,dp[y]-2ll*pre[y])+lmx[f[x][0]]-2ll*pre[x]-2ll*pre[y];
	return f[x][0];
}
int main(){
//	freopen("map.in","r",stdin);
//	freopen("map.out","w",stdout);
	n=read(); q=read();
	F(i,1,n) a[i]=read();
	F(i,1,n-1){
		int x=read(),y=read(),z=read();
		v[x].pb(edge(y,z)); 
		v[y].pb(edge(x,z));
	}
	F(i,2,n) lg[i]=lg[i>>1]+1;
	dfs(1,0); dd(1,0);
	F(i,1,lg[n]){
		F(x,1,n) g[x][i]=g[x][i-1]+g[f[x][i-1]][i-1];
	}
	F(i,1,q){
		int x=read(),y=read();
		int o=lca(x,y);
		cout<<ret+(-2ll*dis[o]+dis[x]+dis[y])<<"\n";
	}
    return 0;
}