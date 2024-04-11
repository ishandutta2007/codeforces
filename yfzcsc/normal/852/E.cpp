#include<bits/stdc++.h>
#define maxn 100100
#define mod 1000000007
using namespace std;
struct edge{int r,nxt;}e[maxn<<1];
int head[maxn],ans,n,esz,f[maxn],gx[maxn],dg[maxn],pre[maxn],suf[maxn],tp,A[maxn];
void addedge(int u,int v){
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;
	e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;
	dg[u]++,dg[v]++;
}
void dfs(int u,int fa){
	bool flag=true;
	f[u]=1;
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=fa)
		dfs(e[t].r,u),f[u]=1ll*f[u]*f[e[t].r]%mod,flag=false;
	tp=0;
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=fa)A[++tp]=e[t].r;
	pre[0]=suf[tp+1]=1;
	for(int i=1;i<=tp;++i)pre[i]=1ll*pre[i-1]*f[A[i]]%mod;
	for(int i=tp;i>=1;--i)suf[i]=1ll*suf[i+1]*f[A[i]]%mod;
	for(int i=1;i<=tp;++i)gx[A[i]]=1ll*pre[i-1]*suf[i+1]%mod;
	if(flag)return ;
	else f[u]=(f[u]<<1)%mod;
}
void dfs2(int u,int fa,int g){
//	printf("[%d,%d]",u,g);
	bool flag=true;
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=fa)
		dfs2(e[t].r,u,1ll*g*gx[e[t].r]*(dg[u]==1?1:2)%mod),flag=false;
	if(flag)f[u]=(f[u]<<1)%mod;
	ans=(ans+1ll*g*f[u])%mod;
}
int main(){
	scanf("%d",&n);
	if(n==1){
		puts("1");
		return 0;
	}
	for(int i=2,u,v;i<=n;++i)
		scanf("%d%d",&u,&v),addedge(u,v);
	dfs(1,-1),dfs2(1,-1,1);
	printf("%d",ans);
}