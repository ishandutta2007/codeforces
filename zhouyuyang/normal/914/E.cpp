#include<bits/stdc++.h>
#define ll long long
#define N 200005 
using namespace std;
struct edge{int to,next;}e[N*2];
int head[N],f[N],dep[N],sz[N],vis[N];
ll sum[(1<<20)+233][2],V[N][22],inc[N][22],ans[N];
char s[N];
int tot,n;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void pre(int x){
	sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (!sz[e[i].to]){
			pre(e[i].to);
			sz[x]+=sz[e[i].to];
		}
}
int getroot(int x,int fa,int lim){
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]&&e[i].to!=fa&&sz[e[i].to]>lim)
			return getroot(e[i].to,x,lim);
	return x;
}
void dfs(int x,int fa,int fr){
	sz[x]=1;
	V[x][dep[fr]]=V[fa][dep[fr]]^(1<<s[x]);
	sum[V[x][dep[fr]]][0]++;
	sum[V[x][dep[fr]-1]][1]++;
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]&&e[i].to!=fa){
			dfs(e[i].to,x,fr);
			sz[x]+=sz[e[i].to];
		}
}
void cal(int x,int fa,int fr){
	ll t1=inc[x][dep[fr]];
	ll t2=inc[x][dep[fr]-1];
	for (int i=-1;i<20;i++){
		int tmp=(i==-1?0:(1<<i));
		inc[x][dep[fr]]+=sum[V[x][dep[fr]]^(1<<s[fr])^tmp][0];
		inc[x][dep[fr]-1]-=sum[V[x][dep[fr]-1]^(1<<s[f[fr]])^tmp][1];
	}
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]&&e[i].to!=fa)
			cal(e[i].to,x,fr);
}
ll upd(int x,int fa,int fr){
	for (int i=head[x];i;i=e[i].next)
		if (dep[e[i].to]>dep[fr]&&e[i].to!=fa)
			inc[x][dep[fr]]+=upd(e[i].to,x,fr);
	if (x!=fr) ans[x]+=inc[x][dep[fr]];
	else ans[x]+=inc[x][dep[fr]]/2+1;
	return inc[x][dep[fr]];
}
void clear(int x,int fa,int fr){
	sum[V[x][dep[fr]]][0]=0;
	sum[V[x][dep[fr]-1]][1]=0;
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]&&e[i].to!=fa)
			clear(e[i].to,x,fr);
}
void solve(int x,int fa){
	//printf("%d %d\n",x,f);
	x=getroot(x,x,sz[x]/2);
	vis[x]=1;
	dep[x]=dep[f[x]=fa]+1;
	dfs(x,x,x);
	cal(x,x,x);
	clear(x,x,x);
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]) solve(e[i].to,x);
	upd(x,x,x);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)
		s[i]-='a';
	pre(1);
	solve(1,0);
	for (int i=1;i<=n;i++)
		printf("%lld ",ans[i]);
}