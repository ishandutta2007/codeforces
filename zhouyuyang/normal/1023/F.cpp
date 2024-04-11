#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long
#define inf 1000000001
#define y1 y1___
using namespace std;
#define N 500005
int n,k,m,fa[N],f[N],cnt,head[N],num,res[N],dep[N];ll ans;
struct edge{int to,nxt,typ;}e[N<<1];
struct node{int x,y,w;node(){}node(int x_,int y_,int w_){x=x_,y=y_,w=w_;}}a[N];
int getfa(int x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
void adde(int x,int y,int typ){e[++cnt].to=y;e[cnt].nxt=head[x];head[x]=cnt;e[cnt].typ=typ;}
void dfs(int u){
	for (int i=head[u];i;i=e[i].nxt) if (e[i].to!=f[u]){
		int v=e[i].to;
		f[v]=u;dep[v]=dep[u]+1;dfs(v);
	}
}
int main(){
	scanf("%d%d%d",&n,&k,&m);int x,y,w;
	rep (i,1,n) fa[i]=i;
	rep (i,1,k) scanf("%d%d",&x,&y),adde(x,y,0),adde(y,x,0),fa[getfa(x)]=getfa(y);
	rep (i,1,m){
		scanf("%d%d%d",&x,&y,&w);
		if (getfa(x)!=getfa(y)) adde(x,y,1),adde(y,x,1),fa[getfa(x)]=getfa(y);
		else a[++num]=node(x,y,w);
	}
	dfs(1);
	rep (i,1,n) fa[i]=i;
	rep (i,1,num){
		x=getfa(a[i].x),y=getfa(a[i].y);
		while (x!=y)
			if (dep[x]>dep[y]) res[x]=a[i].w,fa[x]=getfa(f[x]),x=fa[x];
			else res[y]=a[i].w,fa[y]=getfa(f[y]),y=fa[y];
	}
	rep (u,1,n)
		for (int i=head[u],v;i;i=e[i].nxt)
			if ((v=e[i].to)==f[u]&&!e[i].typ)
				if (fa[u]==u) return puts("-1"),0;else ans+=res[u];
	cout<<ans<<'\n';
	return 0;
}