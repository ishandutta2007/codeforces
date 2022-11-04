#include<bits/stdc++.h>
#define ll long long
#define N 300005
#define inf 1000000000000000000ll
using namespace std;
struct edge{int to,next;}e[N*4];
ll mn[N*4],tg[N*4],f[N];
int val[N],ord[N],L[N],R[N];
int head[N],out[N],in[N];
int n,m,tot,T,x,y,l,r;
void add(int x,int y,int *head){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void build(int k,int l,int r){
	tg[k]=0; mn[k]=1e9;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void change(int k,int l,int r,int x,ll v){
	if (l==r){
		mn[k]=v;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,v);
	else change(k*2+1,mid+1,r,x,v);
	mn[k]=min(min(mn[k*2],mn[k*2+1])+tg[k],inf);
}
void add(int k,int l,int r,int x,int y,ll v){
	if (x>y) return;
	if (l==x&&r==y){
		tg[k]+=v; mn[k]+=v;
		return;
	}
	int mid=(l+r)/2;
	if (y<=mid) add(k*2,l,mid,x,y,v);
	else if (x>mid) add(k*2+1,mid+1,r,x,y,v);
	else add(k*2,l,mid,x,mid,v),add(k*2+1,mid+1,r,mid+1,y,v);
	mn[k]=min(min(mn[k*2],mn[k*2+1])+tg[k],inf);
}
ll ask(int k,int l,int r,int x,int y){
	if (x>y) return inf;
	if (l==x&&r==y) return mn[k];
	int mid=(l+r)/2;
	if (y<=mid) return min(ask(k*2,l,mid,x,y)+tg[k],inf);
	if (x>mid) return min(ask(k*2+1,mid+1,r,x,y)+tg[k],inf);
	return min(min(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y))+tg[k],inf);
}
void dfs(int x,int fa){
	L[x]=T+1;
	for (int i=in[x];i;i=e[i].next)
		ord[e[i].to]=++T;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa) dfs(e[i].to,x);
	R[x]=T;
}
void solve(int x,int fa){
	ll ans=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			solve(e[i].to,x);
			ans=min(ans+f[e[i].to],inf);
		}
	if (x==1){
		f[1]=ans;
		return;
	}
	for (int i=in[x];i;i=e[i].next)
		change(1,1,m,ord[e[i].to],ans+val[e[i].to]);
	for (int i=out[x];i;i=e[i].next)
		change(1,1,m,ord[e[i].to],inf);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa)
			add(1,1,m,L[e[i].to],R[e[i].to],ans-f[e[i].to]);
	f[x]=ask(1,1,m,L[x],R[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		add(x,y,head);
		add(y,x,head);
	}
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&l,&r,&val[i]);
		add(l,i,in); add(r,i,out);
	}
	dfs(1,0);
	build(1,1,m);
	solve(1,0);
	printf("%I64d",f[1]==inf?-1:f[1]);
}