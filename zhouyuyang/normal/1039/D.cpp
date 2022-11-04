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

#define INF ((1<<30)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
const int N=100005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
int dfn[N],fa[N],n;
void dfs(int x,int fa){
	dfn[x]=++(*dfn);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs(e[i].to,x);
			::fa[dfn[e[i].to]]=dfn[x];
		}
}
int f[N],g[N][2],ans[N];
int calc(int k){
	for (int i=n;i;i--) f[i]=g[i][0]=g[i][1]=0;
	for (int i=n;;i--){
		int *h=g[fa[i]],d=0;
		if (g[i][0]+g[i][1]+1>=k) ++f[i];
		else d=g[i][0]+1;
		if (i==1) return f[i];
		f[fa[i]]+=f[i];
		if (d>h[0]) h[1]=h[0],h[0]=d;
		else h[1]=max(h[1],d);
	}
}
void sol(int l,int r){
	if (r-l==1||ans[l]==ans[r]){
		for (;(++l)<r;ans[l]=ans[r]);
		return;
	}
	int mid=(l+r)>>1;
	ans[mid]=calc(mid);
	sol(l,mid); sol(mid,r);
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int x,y; scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0); ans[1]=n;
	sol(1,n+1);
	for (int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
}