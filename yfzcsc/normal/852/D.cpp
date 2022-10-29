#include<bits/stdc++.h>
#define maxn 1100
#define inf 1831311
using namespace std;
namespace WXHAKIOI2018{
	struct edge{
		int r,nxt,w;
	}e[700*600];
	int S,T,head[maxn],dep[maxn],q[maxn],l,r,esz,cur[maxn];
	void init(int s,int t){
		esz=1,S=s,T=t;
		for(int i=S;i<=T;++i)head[i]=0;
	}
	void addedge(int u,int v,int w){
		e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;e[esz].w=w;
		e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;e[esz].w=0;
	}
	int bfs(){
		for(int i=S;i<=T;++i)dep[i]=0,cur[i]=head[i];
		l=r=0,dep[q[r++]=S]=1;
		while(l<r){
			int u=q[l++];
			for(int t=head[u];t;t=e[t].nxt)if(e[t].w&&!dep[e[t].r])
				dep[q[r++]=e[t].r]=dep[u]+1;
		}
		return dep[T]!=0;
	}
	int find(int u,int flow){
		if(u==T)return flow;
		int used=0,a=0;
		for(int& t=cur[u];t;t=e[t].nxt)if(e[t].w&&dep[e[t].r]==dep[u]+1){
			a=find(e[t].r,min(flow-used,e[t].w));
			e[t].w-=a,e[t^1].w+=a,used+=a;
			if(used==flow)return used;
		}
		if(!used)dep[u]=-1;
		return used;
	}
	int dinic(){
		int ans=0,a;
		while(bfs())while(a=find(S,inf))ans+=a;
		return ans;
	}
};
int f[maxn][maxn],v,e,n,k;
int a[maxn];
bool check(int ans){
	WXHAKIOI2018::init(0,n+v+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=v;++j)if(f[a[i]][j]<=ans)
			WXHAKIOI2018::addedge(i,j+n,inf);
	for(int i=1;i<=n;++i)WXHAKIOI2018::addedge(WXHAKIOI2018::S,i,1);
	for(int i=1;i<=v;++i)WXHAKIOI2018::addedge(i+n,WXHAKIOI2018::T,1);
	return WXHAKIOI2018::dinic()>=k;
}
int main(){
	scanf("%d%d%d%d",&v,&e,&n,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=v;++i)for(int j=1;j<=v;++j)
		if(i!=j)f[i][j]=inf;
	for(int i=1,a,b,t;i<=e;++i){
		scanf("%d%d%d",&a,&b,&t);
		f[a][b]=f[b][a]=min(f[a][b],t);
	}
	for(int k=1;k<=v;++k)
		for(int i=1;i<=v;++i)
			for(int j=1;j<=v;++j)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	int l=0,r=1731311,ans=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d",ans);
}