#include<bits/stdc++.h>
#define M 10000005
#define N 100005 
using namespace std;
int ls[M],rs[M],v[M],id;
int rt[N],head[N],dep[N];
struct edge{int to,next;}e[N*2];
int n,Rt,Q,tot,ans,a[N];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
int add(int k,int l,int r,int p,int d){
	int now=++id; v[now]=min(v[k],d);
	ls[now]=ls[k]; rs[now]=rs[k];
	if (l==r) return now;
	int mid=(l+r)/2;
	if (p<=mid) ls[now]=add(ls[now],l,mid,p,d);
	else rs[now]=add(rs[now],mid+1,r,p,d);
	return now;
}
int ask(int k,int l,int r,int x,int y){
	//printf("%d %d %d %d\n",l,r,x,y);
	if (l==x&&r==y) return v[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(ls[k],l,mid,x,y);
	if (x>mid) return ask(rs[k],mid+1,r,x,y);
	return min(ask(ls[k],l,mid,x,mid),ask(rs[k],mid+1,r,mid+1,y));
}
int merge(int x,int y,int l,int r){
	if (!x||!y) return x+y;
	int now=++id,mid=(l+r)/2;
	v[now]=min(v[x],v[y]);
	ls[now]=merge(ls[x],ls[y],l,mid);
	rs[now]=merge(rs[x],rs[y],mid+1,r);
	return now;
}

void dfs(int x,int fa){
	rt[x]=add(rt[x],1,n,dep[x],a[x]);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dep[e[i].to]=dep[x]+1;
			dfs(e[i].to,x);
			rt[x]=merge(rt[x],rt[e[i].to],1,n);
		}
}
int main(){
	scanf("%d%d",&n,&Rt);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	memset(v,63,sizeof(v));
	dep[Rt]=1; dfs(Rt,0);
	scanf("%d",&Q);
	while (Q--){
		int x,y; scanf("%d%d",&x,&y);
		x=(x+ans)%n+1; y=(y+ans)%n;
		int l=dep[x],r=min(dep[x]+y,n);
		printf("%d\n",ans=ask(rt[x],1,n,l,r));
	}
}