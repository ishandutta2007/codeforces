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
int Rev(int x){
	return x&1?x+1:x-1;
}
namespace SAT{
	const int M=12000005;
	vector<int> v[M],V[M];
	int n,mrk[M],q[M];
	bool be[M],ok[M];
	void add(int x,int y){
		v[x].PB(y); v[Rev(y)].PB(Rev(x));
		V[y].PB(x); V[Rev(x)].PB(Rev(y));
	}
	void dfs(int x){
		be[x]=1;
		for (int i=0;i<v[x].size();i++)
			if (!be[v[x][i]]) dfs(v[x][i]);
		q[++*q]=x;
	}
	void rdfs(int x){
		mrk[x]=*mrk;
		for (int i=0;i<V[x].size();i++)
			if (!mrk[V[x][i]]) rdfs(V[x][i]);
	}
	bool solve(){
		For(i,1,n) if (!be[i]) dfs(i);
		Rep(i,n,1) if (!mrk[q[i]]) ++*mrk,rdfs(q[i]);
		For(i,1,n/2) if (mrk[i*2-1]==mrk[i*2]) return 0;
		For(i,1,n/2) ok[i*2-(mrk[i*2-1]>mrk[i*2])]=1;
		return 1;
	}
}
const int N=100005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n,m;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
int sz[N],fa[N],dep[N];
void dfs1(int x){
	sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			fa[e[i].to]=x;
			dep[e[i].to]=dep[x]+1;
			dfs1(e[i].to);
			sz[x]+=sz[e[i].to];
		}
}
int top[N],dfn[N];
void dfs2(int x,int tp){
	top[x]=tp; dfn[x]=++*dfn;
	int k=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&sz[e[i].to]>sz[k])
			k=e[i].to;
	if (k) dfs2(k,tp);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=k)
			dfs2(e[i].to,e[i].to); 
}
int L[N*4],R[N*4],cnt;
vector<int> v[N*4];
void build(int k,int l,int r){
	L[k]=++cnt; R[k]=(cnt+=v[k].size());
	if (k^1) SAT::add(R[k/2]*2-1,L[k]*2-1);
	for (int j=0;j<v[k].size();j++){
		SAT::add(v[k][j],(L[k]+1+j)*2-1);
		SAT::add((L[k]+j)*2-1,(L[k]+1+j)*2-1);
		SAT::add((L[k]+j)*2-1,Rev(v[k][j]));
	}
	if (l!=r){
		int mid=(l+r)/2;
		build(k*2,l,mid);
		build(k*2+1,mid+1,r);
	}
}
void ins(int k,int l,int r,int x,int y,int id){
	if (l==x&&r==y)
		return v[k].push_back(id);
	int mid=(l+r)/2;
	if (y<=mid) ins(k*2,l,mid,x,y,id);
	else if (x>mid) ins(k*2+1,mid+1,r,x,y,id);
	else ins(k*2,l,mid,x,mid,id),
		 ins(k*2+1,mid+1,r,mid+1,y,id);
}
void ins(int x,int y,int id){
	for (;top[x]!=top[y];x=fa[top[x]]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		ins(1,1,n,dfn[top[x]],dfn[x],id);
	}
	if (dfn[x]>dfn[y]) swap(x,y);
	if (dfn[x]<dfn[y]) ins(1,1,n,dfn[x]+1,dfn[y],id);
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs1(1);
	dfs2(1,1);
	scanf("%d",&m); cnt=m;
	For(i,1,m){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		ins(a,b,i*2-1);
		ins(c,d,i*2);
	}
	build(1,1,n);
	SAT::n=cnt*2;
	if (!SAT::solve())
		return puts("NO"),0;
	puts("YES");
	for (int i=1;i<=m;i++)
		printf("%d\n",SAT::ok[i*2]+1);
}