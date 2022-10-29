#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
struct edge{
	int r,nxt;
}e[maxn<<1];
int fr[maxn],to[maxn],id[maxn];
int K,anses[maxn],wxh[maxn],head[maxn],esz,n,a[maxn],tim;
int mxdep[maxn],son[maxn],fa[maxn],tadd[maxn],top[maxn],sum[maxn];
vector<int>dp[maxn];
void addedge(int u,int v){
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;
	e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;
}
void predfs(int u,int f){
	fa[u]=f,mxdep[u]=0,son[u]=0;
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f){
		predfs(e[t].r,u);
		if(mxdep[u]<mxdep[e[t].r]+1)
			mxdep[u]=mxdep[e[t].r]+1,son[u]=e[t].r;
	}
}
void predfs2(int u,int tp){
	top[u]=tp;
	a[++tim]=u,id[u]=tim;
	if(son[u])predfs2(son[u],tp);
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=fa[u]&&e[t].r!=son[u])
		predfs2(e[t].r,e[t].r);
}
void caldp(int u___){
	for(int z=tim;z>=1;--z){
		int u=a[z];
		sum[u]=0;
		int _sum=0;
		for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=fa[u])_sum+=sum[e[t].r];
		if(son[u])tadd[u]=tadd[son[u]]+_sum-sum[son[u]],dp[top[u]][mxdep[u]]=(-tadd[u]+_sum);
		else dp[top[u]][mxdep[u]]=0,tadd[u]=0;
		for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=fa[u]&&e[t].r!=son[u]){
			int c,v=e[t].r;
			for(int i=0;i<=mxdep[v];++i){
				c=dp[top[v]][i]+tadd[v];
				int x=mxdep[v]-i+1;
				int y=K-1-x;
				if(y>=0&&y<mxdep[u]+1){
					int pos=mxdep[u]-y;
	//				printf("(%d,%d)[%d,%d]=%d(%d)\n",u,v,x,y,-sum[v]+c+1+(*dp[u])[pos],(*dp[u])[pos]);
					sum[u]=max(sum[u],-sum[v]+c+1+dp[top[u]][pos]+tadd[u]);
				}
			}
			for(int i=0;i<=mxdep[v];++i){
				c=dp[top[v]][i]+tadd[v];
				int x=mxdep[v]-i+1;
				dp[top[u]][mxdep[u]-x]=max(dp[top[u]][mxdep[u]-x],c+_sum-sum[v]-tadd[u]);
			}
		}
		if(mxdep[u]+1>=K)sum[u]=max(sum[u],dp[top[u]][mxdep[u]+1-K]+1+tadd[u]);
		sum[u]=max(sum[u],_sum);	
		
	}
//	printf("{%d:%d}\n",u,sum[u]);
}
int cal(int x){
	if(~wxh[x])return wxh[x];
	K=x,caldp(1);
	return wxh[x]=sum[1];
}
void solve(int l,int r){
	if(cal(l)==cal(r)){
		for(int i=l;i<=r;++i)anses[i]=cal(l);
		return ;
	} else {
		int mid=l+r>>1;
		solve(l,mid);
		solve(mid+1,r);
	}
}
int main(){
	memset(wxh,-1,sizeof(wxh));
	scanf("%d",&n);
//	n=1e5;
	for(int i=2,u,v;i<=n;++i){
		scanf("%d%d",&u,&v);
		fr[i]=u,to[i]=v;
		addedge(u,v);
	}
	predfs(1,0),predfs2(1,1);
	memset(head,0,sizeof(head)),esz=0;
	for(int i=2;i<=n;++i)
		addedge(id[fr[i]],id[to[i]]);
	tim=0,predfs(1,0),predfs2(1,1);
	for(int i=1;i<=n;++i)if(i==top[i])
		dp[i]=vector<int>(mxdep[i]+1);
	solve(1,n);
	for(int i=1;i<=n;++i)printf("%d\n",anses[i]);
}