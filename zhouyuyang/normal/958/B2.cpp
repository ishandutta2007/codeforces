#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x); i<=(y); i++)
#define ll long long
#define ld long double
#define inf 1000000000
#define pii pair<int,int>
#define F first
#define S second
using namespace std;
ll read(){
	char ch=getchar(); ll x=0; int op=1;
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') op=-1;
	for (; isdigit(ch); ch=getchar()) x=(x<<1)+(x<<3)+ch-'0';
	return x*op;
}
#define N 100005
int n,head[N],cnt,rt,mxdep,po,mx[N],dep[N],fa[N],son[N],ans[N];
struct edge{ int to,nxt; }e[N<<1];
void adde(int x,int y){
	e[++cnt].to=y; e[cnt].nxt=head[x]; head[x]=cnt;
}
void ins(int x,int y){
	adde(x,y); adde(y,x);
}
void dfs(int u,int d){
	if (d>mxdep) mxdep=d,rt=u;
	for (int i=head[u],v; i; i=e[i].nxt) if ((v=e[i].to)!=fa[u]){
		fa[v]=u; dfs(v,d+1);
	}
}
void dfs2(int u){
	mx[u]=dep[u]; son[u]=0;
	for (int i=head[u],v; i; i=e[i].nxt) if ((v=e[i].to)!=fa[u]){
		fa[v]=u; dep[v]=dep[u]+1; dfs2(v);
		mx[u]=max(mx[u],mx[v]);
		if (!son[u] || mx[v]>mx[son[u]]) son[u]=v;
	}
}
int main(){
	n=read();
	rep (i,1,n-1){
		int x=read(),y=read(); ins(x,y);
	}
	dfs(1,0); fa[rt]=0; dfs2(rt);
	priority_queue<pii> q;
	ans[1]=1; q.push(pii(mx[rt],rt)); po=1;
	while (!q.empty()){
		int val=q.top().F,u=q.top().S; q.pop();
		ans[++po]=ans[po-1]+val;
		for (; u; u=son[u]){
			for (int i=head[u],v; i; i=e[i].nxt) if ((v=e[i].to)!=fa[u] && v!=son[u])
				q.push(pii(mx[v]-dep[v]+1,v));
		}
	}
	rep (i,po+1,n) ans[i]=n;
	rep (i,1,n) printf("%d ",ans[i]);
}