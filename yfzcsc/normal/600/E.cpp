#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
typedef long long ll;
struct edge{int r,nxt;}e[maxn<<1];
int son[maxn],n,head[maxn],esz,col[maxn],a[maxn],mxv,vis[maxn];
ll anses[maxn],sum;
void addedge(int u,int v){
	e[++esz].r=v;e[esz].nxt=head[u];head[u]=esz;
	e[++esz].r=u;e[esz].nxt=head[v];head[v]=esz;
}
int pre(int u,int f){
	int mxsize=0,s=0,sz=1;
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f){
		s=pre(e[t].r,u),sz+=s;
		if(mxsize<s)mxsize=s,son[u]=e[t].r;
	}
	return sz;
}
void cal(int u,int f,int k){
	a[col[u]]+=k;
	if(k>0&&a[col[u]]>=mxv){
		if(a[col[u]]>mxv)mxv=a[col[u]],sum=col[u];
		else sum+=col[u];
	}
	for(int t=head[u];t;t=e[t].nxt)if(e[t].r!=f&&!vis[e[t].r])
		cal(e[t].r,u,k);
}
void dfs(int u,int f,int keep){
	for(int t=head[u];t;t=e[t].nxt){
		if(e[t].r==f||e[t].r==son[u])continue;
		dfs(e[t].r,u,0);
	}
	if(son[u])
		dfs(son[u],u,1),vis[son[u]]=1;
	cal(u,f,1),vis[son[u]]=0;
	anses[u]=sum;
	if(!keep)
		cal(u,f,-1),mxv=sum=0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&col[i]);
	for(int i=2,u,v;i<=n;++i)scanf("%d%d",&u,&v),addedge(u,v);
	pre(1,0),dfs(1,0,1);
	for(int i=1;i<=n;++i)printf("%lld ",anses[i]);
}