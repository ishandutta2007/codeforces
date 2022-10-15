#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
    int f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e5+7;
struct Edge{int to,nxt,w;}e[N<<1];
int s_e,head[N];
inline void add_e(int x,int y,int w){
    e[++s_e]={y,head[x],w},head[x]=s_e;
}
int n,m;
struct Tree{
    int rt,rk[N],f[N][19],son[N];
    ll len[N],rem[N],D,sum,cd[N],s[N],dis[N],g[N],dep[N][19];
    int tot,d[N];
    void dfs(int x,int fa,ll dis){
	if(dis>D)D=dis,rt=x;
	for(int i=head[x],y;i;i=e[i].nxt)
	    if((y=e[i].to)^fa)dfs(y,x,dis+e[i].w);
    }
    void dfs1(int x,int fa){
	f[x][0]=fa;
	for(int i=1;i<=18;i++)f[x][i]=f[f[x][i-1]][i-1],dep[x][i]=dep[x][i-1]+dep[f[x][i-1]][i-1];
	for(int i=head[x];i;i=e[i].nxt){
	    int y=e[i].to;if(y==fa)continue;
	    dis[y]=dis[x]+e[i].w,sum+=e[i].w,dep[y][0]=e[i].w,dfs1(y,x);
	    if(g[x]<g[y]+e[i].w)son[x]=y,g[x]=g[y]+e[i].w;
	}
    }
    void dfs2(int x,int fa,ll dd){
	if(!son[x]){len[x]=cd[++tot]=dd,d[tot]=x;return;}
	for(int i=head[x],y;i;i=e[i].nxt)
	    if((y=e[i].to)!=fa)
		if(y!=son[x])dfs2(y,x,e[i].w);
		else dfs2(y,x,dd+e[i].w),len[x]=len[y],rem[x]=rem[y]+e[i].w;
    }
    inline void build(int xx){
	D=-1,dfs(xx,0,0),dfs1(rt,0),dfs2(rt,0,0),sort(cd+1,cd+tot+1);
	for(int i=1;i<=n;i++)rk[i]=tot-(upper_bound(cd+1,cd+tot+1,len[i])-cd-1)+1;
	reverse(cd+1,cd+tot+1);
	for(int i=1;i<=tot;i++)s[i]=s[i-1]+cd[i];
    }
    inline ll gf(int x,int k){
	ll res=g[x];
	for(int i=18;~i;i--)
	    if(rk[f[x][i]]>k)res+=dep[x][i],x=f[x][i];
	res+=dep[x][0],x=f[x][0];
	res-=min(rem[x],cd[k]);
	return res;
    }
    inline ll query(int u,int k){
	k=(k<<1)-1;
	if(k>=tot)return sum;
	if(rk[u]<=k)return s[k];
	return s[k]+gf(u,k);
    }
}T[2];
int main(){
    n=read(),m=read();
    for(int i=1;i<n;i++){
	int x=read(),y=read(),w=read();
	add_e(x,y,w),add_e(y,x,w);
    }
    T[0].build(1),T[1].build(T[0].rt);ll lst=0;
    while(m--){
	int x=(read()+lst-1)%n+1,k=(read()+lst-1)%n+1;
	printf("%lld\n",lst=max(T[0].query(x,k),T[1].query(x,k)));
    }
    return 0;
}