#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define fi first
#define se second
#define BG begin
#define ED end

#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF (1<<29)
#define sqr(x) ((x)*(x))
#define all ((1<<30)-1)
using namespace std;
const int N=200005;
const int M=N*190;
int ls[M],rs[M],tg[M];
int tot,lim,rt[N];
ll sum[M],s[N],ds[N];
void change(int &k,int l,int r,int x,int y,int v){
	if (k<=lim){
		ls[++tot]=ls[k]; rs[tot]=rs[k];
		tg[tot]=tg[k]; sum[tot]=sum[k];
		k=tot;
	}
	if (l==x&&r==y){
		tg[k]+=v;
		sum[k]+=v*(s[r]-s[l-1]);
		return;
	}
	int mid=(l+r)/2;
	if (y<=mid) change(ls[k],l,mid,x,y,v);
	else if (x>mid) change(rs[k],mid+1,r,x,y,v);
	else change(ls[k],l,mid,x,mid,v),
		 change(rs[k],mid+1,r,mid+1,y,v);
	sum[k]=tg[k]*(s[r]-s[l-1])+sum[ls[k]]+sum[rs[k]];
}
ll ask(int k,int l,int r,int x,int y){
	if (!k||(l==x&&r==y)) return sum[k];
	int mid=(l+r)/2;
	ll ans=tg[k]*(s[y]-s[x-1]);
	if (y<=mid) return ans+ask(ls[k],l,mid,x,y);
	if (x>mid) return ans+ask(rs[k],mid+1,r,x,y);
	return ans+ask(ls[k],l,mid,x,mid)+
			   ask(rs[k],mid+1,r,mid+1,y);
}

struct edge{
	int to,next,v;
}e[N*2];
int head[N],etot,n,Q,T;
int fa[N],top[N],sz[N];
int dfn[N],a[N],Dep[N];
ll dep[N];
void insert(int i,int x){
	for (;x;x=fa[top[x]])
		change(rt[i],1,n,dfn[top[x]],dfn[x],1);
}
void change(int i,int x,int y){
	int valx=-1,valy=1;
	for (;top[x]!=top[y];x=fa[top[x]]){
		if (Dep[top[x]]<Dep[top[y]])
			swap(x,y),swap(valx,valy);
		change(rt[i],1,n,dfn[top[x]],dfn[x],valx);
	}
	if (dfn[x]>dfn[y])
		swap(x,y),swap(valx,valy);
	if (dfn[x]!=dfn[y])
		change(rt[i],1,n,dfn[x]+1,dfn[y],valy);
}
ll ask(int i,int x){
	ll ans=0;
	for (;x;x=fa[top[x]])
		ans+=ask(rt[i],1,n,dfn[top[x]],dfn[x]);
	return ans;
}

void build(){
	lim=tot=0;
	For(i,1,n){
		rt[i]=rt[i-1];
		insert(i,a[i]);
		lim=tot;
	}
}

void add(int x,int y,int v){
	e[++etot]=(edge){y,head[x],v};
	head[x]=etot;
}
void dfs(int x,int f){
	sz[x]=1; fa[x]=f;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			dep[e[i].to]=dep[x]+e[i].v;
			Dep[e[i].to]=Dep[x]+1;
			dfs(e[i].to,x);
			sz[x]+=sz[e[i].to];
		}
}
void dfs2(int x,int tp){
	top[x]=tp; dfn[x]=++T;
	s[T]=dep[x]-dep[fa[x]];
	int k=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&sz[e[i].to]>sz[k])
			k=e[i].to;
	if (k) dfs2(k,tp);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=k)
			dfs2(e[i].to,e[i].to);
}

ll ans;
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n-1){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	dfs(1,0); dfs2(1,1);
	For(i,1,n) ds[i]=dep[a[i]];
	For(i,1,n) s[i]+=s[i-1],ds[i]+=ds[i-1];
	For(i,1,Q){
		int tp,x,y,z;
		if (i%100000==1) build();
		scanf("%d%d",&tp,&x),x^=ans&all;
		if (tp==1){
			scanf("%d%d",&y,&z);
			y^=ans&all,z^=ans&all;
			printf("%lld\n",ans=ds[y]-ds[x-1]+(y-x+1)*dep[z]-2*(ask(y,z)-ask(x-1,z)));
		}
		else{
			change(x,a[x],a[x+1]); lim=tot;
			ds[x]+=dep[a[x+1]]-dep[a[x]];
			swap(a[x+1],a[x]);
		}
	}
}