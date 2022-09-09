#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,U=1e8;
typedef pair<int,int>pii;
vector<pii>e[N];
int n,q,u,v,l,i,rt,x,y,la;
namespace getM{
int md,u,v,dad[N],dep[N],dis[N];
void dfs(int x,int fa,int d){
	if(d>=md)md=d,u=x;dad[x]=fa;dep[x]=d;
	for(pii E:e[x])if(E.first!=fa)dfs(E.first,x,d+E.second);
}
void getd(int x,int fa,int d){dis[x]=max(dis[x],d);for(pii E:e[x])if(E.first!=fa)getd(E.first,x,d+E.second);}
inline int work(){
	dfs(1,0,0);dfs(v=u,0,0);
	getd(u,0,0);getd(v,0,0);
	int mn=1<<30,mnid=0,i;
	for(i=1;i<=n;++i)if(dis[i]<mn)mn=dis[i],mnid=i;
	return mnid;
}
}
int len[N],md[N],ma[N],dad[N],dep[N],rt0[N],rt1[N],rt2[N],top[N],rtt0;
void dfs(int u,int fa){
	dad[u]=fa;md[u]=dep[u];
	for(pii E:e[u])if(E.first!=fa){
		dep[E.first]=dep[u]+E.second;dfs(E.first,u);int nl=len[E.first]+E.second;
		if(nl>len[u])len[u]=nl,ma[u]=E.first,md[u]=md[E.first];
	}
}
struct node{int l,r,s,c;}t[N*130];int tcnt;
void ins(int x,int&y,int l,int r,int k,int v){
	t[y=++tcnt]=t[x];t[y].c+=v;t[y].s+=k*v;if(l==r)return;
	int m=l+r>>1;if(k<=m)ins(t[x].l,t[y].l,l,m,k,v);else ins(t[x].r,t[y].r,m+1,r,k,v);
}
int ask(int x,int y,int l,int r,int k){
	if(l==r)return min(k,t[y].c+t[x].c)*l;
	int m=l+r>>1,c=t[t[y].r].c+t[t[x].r].c,s=t[t[y].r].s+t[t[x].r].s;
	if(k<=c)
			return ask(t[x].r,t[y].r,m+1,r,k);
		else return ask(t[x].l,t[y].l,l,m,k-c)+s;
}
void dfs2(int u,int fa,int lst){
	ins(lst,rt0[u],0,U,md[top[u]]-dep[dad[top[u]]],-1);
	ins(rt0[u],rt1[u],0,U,getM::dis[u]+len[u]-md[u],-1);
	ins(rt0[u],rt2[u],0,U,len[u],1);
	if(top[u]==u)
		ins(rtt0,rtt0,0,U,md[u]-dep[fa],1);
	if(ma[u])top[ma[u]]=top[u],dfs2(ma[u],u,lst);
	for(pii E:e[u])if(E.first!=fa && E.first!=ma[u])
		top[E.first]=E.first,dfs2(E.first,u,rt2[u]);
}
int main(){
	scanf("%d%d",&n,&q);
	for(i=1;i<n;++i)scanf("%d%d%d",&u,&v,&l),e[u].push_back(pii(v,l)),e[v].push_back(pii(u,l));
	rt=getM::work();
	dfs(rt,0);top[rt]=rt;dfs2(rt,0,0);
	for(i=1;i<=q;++i){
		scanf("%d%d",&x,&y);
		if(i>1)x=(x+la-1)%n+1,y=(y+la-1)%n+1;
if(i==76)
++i,--i;
		printf("%d\n",la=x==rt?ask(0,rtt0,0,U,y<<1):getM::dis[x]+len[x]+ask(rt1[x],rtt0,0,U,y-1<<1));
	}
	return 0;
}