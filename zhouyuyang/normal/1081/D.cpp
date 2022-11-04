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
 
#define inf 1<<30
#define sqr(x) ((x)*(x))
using namespace std;
const int N=200005;
int n,m,k,tp;
struct edge{
	int x,y,v;
}e[N];
bool cmp(edge a,edge b){
	return a.v<b.v;
}
int id[N],fa[N],sz[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
vector<int> E[N];
int ans[N];
void dfs(int x){
	for (auto i:E[x]){
		ans[i]=max(ans[i],ans[x]);
		dfs(i);
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k); tp=n;
	for (int i=1;i<=k;i++) scanf("%d",&id[i]),sz[id[i]]=1;
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].v);
	sort(e+1,e+m+1,cmp);
	for (int i=1;i<=m;i++){
		int x=get(e[i].x),y=get(e[i].y);
		if (x!=y){
			fa[x]=fa[y]=++tp; fa[tp]=tp;
			sz[tp]=sz[x]+sz[y];
			E[tp].PB(x); E[tp].PB(y);
			if (sz[x]&&sz[y])
				ans[tp]=e[i].v;
		}
	}
	for (int i=1;i<=tp;i++)
		if (get(i)==i)
			dfs(i);
	for (int i=1;i<=k;i++)
		printf("%d ",ans[id[i]]);
}