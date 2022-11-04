#include<bits/stdc++.h>
#define N 200005
using namespace std;
struct edge{
	int to,next;
}e[N];
struct Que{
	int x,t,id;
}a[N];
int head[N],fa[N],dep[N];
int sz[N],pos[N],q[N],top[N];
int s[N*3],sd[N*3],tg[N*3];
int n,Q,tot,ans[N];
bool cmp(Que a,Que b){
	if (a.t+dep[a.x]!=b.t+dep[b.x])
		return a.t+dep[a.x]<b.t+dep[b.x];
	return a.x<b.x;
}
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x,int tp){
	top[x]=tp; pos[x]=++q[0];
	q[q[0]]=x; int k=0;
	for (int i=head[x];i;i=e[i].next)
		if (sz[e[i].to]>sz[k]) k=e[i].to;
	if (k) dfs(k,tp);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=k) dfs(e[i].to,e[i].to);
}
void build(int k,int l,int r){
	s[k]=tg[k]=-1e9;
	if (l==r){
		sd[k]=dep[q[l]]*2;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	sd[k]=max(sd[k*2],sd[k*2+1]);
}
void upd(int k,int v){
	s[k]=max(s[k],sd[k]+v);
	tg[k]=max(tg[k],v);
}
void pushdown(int k){
	if (tg[k]!=-1e9){
		upd(k*2,tg[k]);
		upd(k*2+1,tg[k]);
		tg[k]=-1e9;
	}
}
void change(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y){
		upd(k,v);
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) change(k*2,l,mid,x,y,v);
	else if (x>mid) change(k*2+1,mid+1,r,x,y,v);
	else change(k*2,l,mid,x,mid,v),
		 change(k*2+1,mid+1,r,mid+1,y,v);
	s[k]=max(s[k*2],s[k*2+1]);
}
int ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return s[k];
	int mid=(l+r)/2;
	pushdown(k);
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return max(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y));
}
int solve(int x,int t){
	int u=x;
	while (u){
		if (ask(1,1,n,pos[top[u]],pos[u])<=dep[x]+t){
			u=fa[top[u]];
			continue;
		}
		int l=pos[top[u]]+1,r=pos[u]+1;
		while (l<r){
			int mid=(l+r)/2;
			if (ask(1,1,n,mid,pos[u])>dep[x]+t) l=mid+1;
			else r=mid;
		}
		u=q[l-1];
		break;
	}
	if (!u) u=1;
	int ret=2*(dep[x]-dep[u])+t,v=x;
	for (;top[v]!=top[u];v=fa[top[v]])
		change(1,1,n,pos[top[v]],pos[v],ret-dep[x]);
	change(1,1,n,pos[u],pos[v],ret-dep[x]);
	return ret;
}
int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	scanf("%d%d",&n,&Q); n++;
	for (int i=2;i<=n;i++){
		scanf("%d",&fa[i]);
		add(++fa[i],i);
		dep[i]=dep[fa[i]]+1;
	}
	for (int i=n;i;i--){
		sz[i]++;
		if (fa[i]) sz[fa[i]]+=sz[i];
	}
	dfs(1,1);
	build(1,1,n);
	for (int i=1;i<=Q;i++){
		scanf("%d%d",&a[i].x,&a[i].t);
		a[i].x++; a[i].id=i;
	}
	sort(a+1,a+Q+1,cmp);
	for (int i=1;i<=Q;i++)
		ans[a[i].id]=solve(a[i].x,a[i].t);
	for (int i=1;i<=Q;i++)
		printf("%d ",ans[i]);
}