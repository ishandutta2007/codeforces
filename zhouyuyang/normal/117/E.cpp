#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second

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

#define INF ((1ll<<60)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
const int N=100005,LG=17;
struct seg{
	int tg[N*4],sum[N*4],t[N*4];
	void pushdown(int k){
		if (!tg[k]) return;
		t[k*2]=sum[k*2]-t[k*2];
		t[k*2+1]=sum[k*2+1]-t[k*2+1];
		tg[k]^=1; tg[k*2]^=1; tg[k*2+1]^=1;
	}
	void build(int k,int l,int r){
		tg[k]=t[k]=0; sum[k]=r-l+1;
		if (l==r) return;
		int mid=(l+r)/2;
		build(k*2,l,mid); build(k*2+1,mid+1,r);
	}
	void change(int k,int l,int r,int x,int y){
		if (l==x&&r==y){
			tg[k]^=1; t[k]=sum[k]-t[k];
			return;
		} 
		pushdown(k);
		int mid=(l+r)/2;
		if (y<=mid) change(k*2,l,mid,x,y);
		else if (x>mid) change(k*2+1,mid+1,r,x,y);
		else change(k*2,l,mid,x,mid),
			 change(k*2+1,mid+1,r,mid+1,y);
		t[k]=t[k*2]+t[k*2+1];
	}
}T1,T2;
int v[N],b[N],a[N];
vector<int> e[N];
bool init(int x,int fa){
	v[x]=1; b[++*b]=x;
	for (auto i:e[x]) if (i!=fa){
		if (!v[i]){
			if (init(i,x)) return 1;
		}
		else{
			for (int j=*b;b[j]!=i;j--) a[++*a]=b[j];
			return a[++*a]=i,1;
		}
	}
	--*b;
	return v[x]=0;
}
int dep[N],id[N],sz[N];
int dfn[N],top[N],fa[N][LG];
void dfs1(int x,int ID){
	id[x]=ID; sz[x]=1;
	for (auto i:e[x])	
		if (i!=fa[x][0]&&!v[i]){
			dep[i]=dep[x]+1; fa[i][0]=x;
			dfs1(i,ID); sz[x]+=sz[i];
		}
}
void dfs2(int x,int tp){
	dfn[x]=++*dfn; top[x]=tp;
	int k=0;
	for (auto i:e[x])
		if (i!=fa[x][0]&&!v[i]&&sz[i]>sz[k]) k=i;
	if (k) dfs2(k,tp);
	for (auto i:e[x])
		if (i!=fa[x][0]&&!v[i]&&i!=k) dfs2(i,i);
}
int n,Q;
void init(){
	scanf("%d%d",&n,&Q);
	For(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	init(1,0); CLR(v,0);
	For(i,1,*a) v[a[i]]=1;
	For(i,1,*a) dfs1(a[i],i),dfs2(a[i],0);
	For(j,1,LG-1) For(i,1,n)
		fa[i][j]=fa[fa[i][j-1]][j-1];
	T1.build(1,1,n);
	T2.build(1,1,*a);
}
int getlca(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	For(i,0,LG-1)
		if (tmp&(1<<i)) x=fa[x][i];
	Rep(i,LG-1,0)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
void go(int x,int L){
	if (x==L) return;
	for (;top[x]!=top[L];x=fa[top[x]][0])
		T1.change(1,1,n,dfn[top[x]],dfn[x]);
	if (x!=L) T1.change(1,1,n,dfn[L]+1,dfn[x]);
}
void askque(){
	int x,y; scanf("%d%d",&x,&y);
	if (id[x]==id[y]){
		int L=getlca(x,y);
		go(x,L); go(y,L);
	}
	else{
		go(x,a[id[x]]); x=id[x];
		go(y,a[id[y]]); y=id[y];
		bool rev=0;
		if (x>y) swap(x,y),rev=1;
		int tp,dis1=y-x,dis2=*a-dis1;
		if (dis1!=dis2){
			if (dis1<dis2)
				T2.change(1,1,*a,x,y-1);
			else{
				T2.change(1,1,*a,y,*a);
				if (x!=1) T2.change(1,1,*a,1,x-1);
			}
		}
		else{
			if (rev) swap(x,y);
			int v1=a[x%*a+1];
			int v2=a[(x+*a-2)%*a+1];
			if (v1>v2) swap(x,y);
			if (x<y) T2.change(1,1,*a,x,y-1);
			else{
				T2.change(1,1,*a,x,*a);
				if (y!=1) T2.change(1,1,*a,1,y-1);
			}
		}
	}
	printf("%d\n",n-T1.t[1]-min(T2.t[1],(*a)-1));
}
int main(){
	init();
	while (Q--) askque();
}