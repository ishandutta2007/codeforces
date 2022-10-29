#include<bits/stdc++.h>
#define maxn 500100
using namespace std;
const int inf=1000000007;
struct edge{int r,nxt,w;}e[maxn<<1];
int head[maxn],n,son[maxn],dep[maxn],esz,a[maxn],c[1<<22],anses[maxn],mxv;
void addedge(int u,int v,int w){
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;e[esz].w=w;
	e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;e[esz].w=w;
}
int pre(int u,int f){
	int sz=1,mxsize=0,s=0;
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f){
		dep[e[t].r]=dep[u]+1,a[e[t].r]=a[u]^(1<<e[t].w),s=pre(e[t].r,u),sz+=s;
		if(mxsize<s)mxsize=s,son[u]=e[t].r;
	}
	return sz;
}
int find(int x){
	int ret=c[x];
	for(int i=1;i<(1<<22);i<<=1)ret=max(ret,c[x^i]);
	return ret;
}
void ins(int u,int f,int k){
	if(k>0)c[a[u]]=max(c[a[u]],dep[u]);
	else c[a[u]]=-inf;
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f)
		ins(e[t].r,u,k);
}
void cal(int u,int f){
	mxv=max(mxv,find(a[u])+dep[u]);
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f)
		cal(e[t].r,u);
}
void dfs(int u,int f,int keep){
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f&&e[t].r!=son[u])
		dfs(e[t].r,u,0);
	if(son[u])dfs(son[u],u,1);
	mxv=-inf;
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f&&e[t].r!=son[u])
		cal(e[t].r,u),ins(e[t].r,u,1);
	c[a[u]]=max(c[a[u]],dep[u]);
	anses[u]=max(find(a[u])-dep[u],mxv-2*dep[u]);
	if(!keep)ins(u,f,-1);
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f)anses[u]=max(anses[u],anses[e[t].r]);
}
char cmd[10];
int main(){
	scanf("%d",&n);
	for(int i=0;i<(1<<22);++i)c[i]=-inf;
	for(int i=2,u,v;i<=n;++i)
		scanf("%d%s",&u,cmd),addedge(u,i,cmd[0]-'a');
	pre(1,0),dfs(1,0,1);
	for(int i=1;i<=n;++i)printf("%d ",anses[i]);
}