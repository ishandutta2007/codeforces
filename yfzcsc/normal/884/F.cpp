#include<bits/stdc++.h>
#define maxn 220
#define inf 1000000007
using namespace std;
struct edge{int r,nxt,w,cost;}e[maxn*maxn*2];
int ans,S,T,n,head[maxn],cnt[100],esz=1,dist[maxn],q[500],vis[maxn],l,r,val[maxn];
char s[maxn];
void addedge(int u,int v,int w,int cost){
	cost=-cost;
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;e[esz].w=w;e[esz].cost=cost;
	e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;e[esz].w=0;e[esz].cost=-cost;
}
bool spfa(){
	for(int i=S;i<=T;++i)dist[i]=inf,vis[i]=0;
	l=r=0,q[r++]=S,dist[S]=0;
	while(l!=r){
		int u=q[l++];l&=255;vis[u]=false;
//		printf("[%d,%d]",u,dist[u]);
		for(int t=head[u];t;t=e[t].nxt)if(e[t].w&&dist[e[t].r]>dist[u]+e[t].cost){
			dist[e[t].r]=dist[u]+e[t].cost;
			if(!vis[e[t].r])vis[e[t].r]=true,q[r++]=e[t].r,r&=255;
		}
	}
//	printf("[%d]",T);
	return dist[T]!=inf;
}
int find(int u,int flow){
//	printf("[u=%d]\n",u);
	if(u==T)return flow;
	vis[u]=1;
	int used=0;
	for(int t=head[u];t;t=e[t].nxt)if(e[t].w&&!vis[e[t].r]&&dist[e[t].r]==dist[u]+e[t].cost){
		int a=find(e[t].r,min(e[t].w,flow-used));
		used+=a,e[t].w-=a,e[t^1].w+=a,ans+=e[t].cost*a;
		if(flow==used)return used;
	}
	return used;
}
int dinic(){
	ans=0;
	while(spfa())find(S,inf);
	return ans;
}
int main(){
	int ans=0;
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
		cnt[s[i]-'a'+1]++;
	for(int i=1;i<=n;++i)
		scanf("%d",&val[i]);
	S=0,T=n/2+26+1;
	for(int i=1;i<=26;++i)
		addedge(S,i,cnt[i],0);
	for(int i=1;i<=26;++i)
		for(int j=1;j<=n/2;++j){
			if(s[j]==i+'a'-1||s[n+1-j]==i+'a'-1)
				addedge(i,j+26,1,s[j]==s[n+1-j]?max(val[j],val[n+1-j]):(s[j]==i+'a'-1?val[j]:val[n+1-j]));
			else addedge(i,j+26,1,0);
		}
	for(int i=1;i<=n/2;++i)
		addedge(i+26,T,2,0);
	printf("%d",-dinic());
}