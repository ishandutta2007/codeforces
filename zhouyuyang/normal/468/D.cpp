#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint ungigned
#define db double
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
#define y1 wzpakking
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1ll<<60)
using namespace std;
const int N=100005;
ll ans;
int n,T,M,rt,tot;
int head[N],sz[N],mx[N];
int be[N],cnt[N];
set<int> S[N],A[N];
struct edge{
	int to,next,v;
}e[N*2];
struct node{
	int x,y;
	node operator +(node b){
		node a=*this;
		if (a.x>b.x) swap(a,b);
		if (b.x<a.y&&be[b.x]!=be[a.x]) a.y=b.x;
		if (b.y<a.y&&be[b.y]!=be[a.x]) a.y=b.y;
		return a;
	}
}t[N*4];
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
void dfs1(int x,int fa){
	sz[x]=1; mx[x]=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs1(e[i].to,x);
			sz[x]+=sz[e[i].to];
			mx[x]=max(mx[x],sz[e[i].to]);
		}
	mx[x]=max(mx[x],n-sz[x]);
	if (!rt||mx[x]<mx[rt]) rt=x;
}
void dfs2(int x,int fa,ll dep){
	ans+=dep; sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs2(e[i].to,x,dep+e[i].v);
			sz[x]+=sz[e[i].to];
		}
}
void dfs3(int x,int fa){
	A[T].insert(x); be[x]=T;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa)
			dfs3(e[i].to,x);
}
void pushup(int x){
	for (x=(x+M)/2;x;x/=2)
		t[x]=t[x*2]+t[x*2+1];
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	dfs1(1,0);
	dfs2(rt,0,0);
	printf("%lld\n",ans*2);
	for (int i=head[rt];i;i=e[i].next){
		S[sz[e[i].to]*2].insert(++T);
		cnt[T]=sz[e[i].to]*2;
		dfs3(e[i].to,rt);
	}
	be[N-1]=N-1;
	for (M=1;M<=n+1;M<<=1); M--;
	For(i,1,M*2+1) t[i]=(node){N-1,N-1};
	For(i,1,n) t[M+i]=(node){i,N-1};
	Rep(i,M,1) t[i]=t[i*2]+t[i*2+1];
	For(i,1,n){
		int d=n-i+1,j=0;
		set<int>::iterator it;
		for (it=S[d].begin();it!=S[d].end();it++)
			if ((*it)!=be[i]) j=*A[*it].begin();
		if (!j) j=((i==rt||be[t[1].x]!=be[i])?t[1].x:t[1].y);
		if (cnt[be[i]]){
			S[cnt[be[i]]].erase(be[i]);
			S[--cnt[be[i]]].insert(be[i]);
		}
		if (cnt[be[j]]){
			S[cnt[be[j]]].erase(be[j]);
			S[--cnt[be[j]]].insert(be[j]);
		}
		A[be[j]].erase(j);
		t[M+j]=(node){N-1,N-1};
		pushup(j);
		printf("%d ",j);
	}
}