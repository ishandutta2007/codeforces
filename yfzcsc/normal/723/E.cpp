#include<bits/stdc++.h>
#define maxm 70000
#define maxn 250
using namespace std;
struct edge{
	int r,nxt,w,bh;
}e[maxm];
int head[maxn],esz,d[maxn],in[maxn],r[maxn],n,m,t,sz;
bool vis[maxm],xvis[maxn];
void addedge(int u,int v,int bh){
	e[++esz].r=v;e[esz].nxt=head[u];
	head[u]=esz;e[esz].bh=bh;
}
void dfs(int u){
	for(int t=head[u];t;t=e[t].nxt)if(!vis[e[t].bh]){
		if(u&&e[t].r) printf("%d %d\n",u,e[t].r);
		vis[e[t].bh]=true;
		dfs(e[t].r);
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		memset(head,0,sizeof(head));
		memset(vis,0,sizeof(vis));
		memset(d,0,sizeof(d));
		memset(r,0,sizeof(r));
		memset(xvis,0,sizeof(xvis));
		memset(in,0,sizeof(in));
		sz=esz=0;
		int ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;++i){
			int u,v;scanf("%d%d",&u,&v);
			addedge(u,v,i);
			addedge(v,u,i);
			d[u]++;d[v]++;
		}
		for(int i=1;i<=n;++i)if(~d[i]&1)ans++;
		printf("%d\n",ans);
		for(int i=1;i<=n;++i)if(d[i]&1)
			addedge(0,i,m+(++sz)),addedge(i,0,m+(sz));
		for(int i=0;i<=n;++i)dfs(i);		
	}
}