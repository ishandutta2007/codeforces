#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
struct edge{int r,nxt;}e[maxn<<1];
int f[maxn][256],n,fa[maxn],dep[maxn],m,sta[maxn],pre[maxn],tp,trie[maxn*20][2],ptr,head[maxn],esz,a[maxn];
void addedge(int u,int v){
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;
	e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;
}
void insert(int x){
	int rt=0;
	for(int i=16;i>=0;--i){
		if(!trie[rt][x>>i&1])trie[rt][x>>i&1]=++ptr;
		rt=trie[rt][x>>i&1];
	}
}
int find(int x){
	int ans=0,rt=0;
	for(int i=16;i>=0;--i){
		int y=(x>>i&1);
		if(trie[rt][!y])
			rt=trie[rt][!y],ans|=!y<<i;
		else rt=trie[rt][y],ans|=y<<i;
	}
	return ans^x;
}
void dfs(int u){
	sta[++tp]=u,dep[u]=dep[fa[u]]+1;
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=fa[u])
		fa[e[t].r]=u,dfs(e[t].r);
	if(tp>256){
		for(int i=0;i<=ptr;++i)trie[i][0]=trie[i][1]=0;
		pre[u]=sta[tp-256],ptr=0;
		for(int i=0;i<256;++i)
			insert(a[sta[tp-i]]^i);
		for(int i=0;i<256;++i)
			f[u][i]=find(i<<8);
	}
	tp--;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=2,u,v;i<=n;++i)
		scanf("%d%d",&u,&v),addedge(u,v);
	dfs(1);
	for(int i=1,u,v;i<=m;++i){
		scanf("%d%d",&u,&v);
		int ans=0,z=0;
		while(dep[pre[v]]>=dep[u])
			ans=max(ans,f[v][z]),z++,v=pre[v];//,printf("[ok]");
		z<<=8;
		while(v!=fa[u])
			ans=max(ans,z^a[v]),v=fa[v],z++;
		printf("%d\n",ans);
	}
}