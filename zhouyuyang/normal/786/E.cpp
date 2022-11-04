#include<bits/stdc++.h>
#define N 20005
using namespace std;
int n,m,ans;
vector<int> v1,v2;
//------------Network Flow--------------
struct edge{int to,next,f;}e[N*666];
int head[N*5],dis[N*5],q[N*5];
int tot=1,sum,S,T;
int cur[N*5],vis[N*5];
void add(int x,int y,int f){
	e[++tot]=(edge){y,head[x],f};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot; 
}
bool bfs(){
	for (int i=1;i<=sum;i++)
		dis[i]=-1;
	int h=0,t=1;
	dis[S]=0;
	q[1]=S;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (e[i].f&&dis[e[i].to]==-1){
				dis[e[i].to]=dis[x]+1;
				q[++t]=e[i].to;
				if (e[i].to==T) return 1;
			}
	}
	return 0;
}
int dinic(int x,int flow){
	if (x==T) return flow;
	int rest=flow,k;
	for (int i=cur[x];i&&rest;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			cur[x]=i;
			k=dinic(e[i].to,min(e[i].f,rest));
			rest-=k;
			e[i].f-=k;
			e[i^1].f+=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
void dfs(int x){
	if (vis[x]) return;
	vis[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].f&&!vis[e[i].to])
			dfs(e[i].to);
}
//-----------------Tree----------------------------
vector<int> V[N];
int sz[N],fa[N],dep[N];
int id[N],cal[N],top[N];
#define pa pair<int,int>
map<pa,int> mp;
int Tim;
int A[N*4],B[N*4];
void dfs1(int x){
	sz[x]=1;
	for (int i=0;i<V[x].size();i++){
		int y=V[x][i];
		if (y==fa[x]) continue;
		dep[y]=dep[x]+1;
		fa[y]=x;
		dfs1(y);
		sz[x]+=sz[y];
	}
}
void dfs2(int x,int tp){
	id[x]=++Tim;
	if (fa[x])
		cal[id[x]]=mp[pa(x,fa[x])];
	top[x]=tp;
	int k=0;
	for (int i=0;i<V[x].size();i++){
		int y=V[x][i];
		if (y!=fa[x]&&sz[y]>sz[k])
			k=y;
	}
	if (k)
		dfs2(k,tp);
	for (int i=0;i<V[x].size();i++){
		int y=V[x][i];
		if (y!=fa[x]&&y!=k)
			dfs2(y,y);
	}
}
//---------------Segment Tree---------------
int at[N*5],ql,qr;
void build(int k,int l,int r){
	at[k]=++sum;
	if (l==r){
		B[cal[l]]=at[k];
		add(at[k],T,1);
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	add(at[k],at[k*2],1e9);
	add(at[k],at[k*2+1],1e9);
}
void query(int k,int l,int r){
	if (ql<=l&&qr>=r){
		add(sum,at[k],1e9);
		return;
	}
	int mid=(l+r)/2;
	if (ql<=mid) query(k*2,l,mid);
	if (qr>mid) query(k*2+1,mid+1,r);
}
void Query(int x,int y){
	for (;top[x]!=top[y];){
		//printf("%d %d %d %d\n",x,y,top[x],top[y]);
		//for (int i=1;i<=1000000000;i++);
		if (dep[top[x]]<dep[top[y]])
			swap(x,y);
		ql=id[top[x]];
		qr=id[x];
		query(1,1,n);
		x=fa[top[x]];
	}
	if (id[x]>id[y])
		swap(x,y);
	ql=id[x]+1; qr=id[y];
	if (ql<=qr)
		query(1,1,n);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		V[x].push_back(y);
		V[y].push_back(x);
		mp[pa(x,y)]=mp[pa(y,x)]=i;
	}
	dfs1(1);
	dfs2(1,1);
	S=++sum;
	T=++sum;
	build(1,1,n);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		A[i]=++sum;
		add(S,sum,1);
		Query(x,y);
	}
	while (bfs()){
		for (int i=1;i<=sum;i++)
			cur[i]=head[i];
		ans+=dinic(S,1e9);
	}
	dfs(S);
	for (int i=1;i<=m;i++)
		if (!vis[A[i]]) v1.push_back(i);
	for (int i=1;i<n;i++)
		if (vis[B[i]]) v2.push_back(i);
	printf("%d\n",ans);
	printf("%d ",v1.size());
	for (int i=0;i<v1.size();i++)
		printf("%d ",v1[i]);
	puts("");
	printf("%d ",v2.size());
	for (int i=0;i<v2.size();i++)
		printf("%d ",v2[i]);
}