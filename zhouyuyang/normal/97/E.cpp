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
 
#define inf 1e18
#define sqr(x) ((x)*(x))
using namespace std;
const int N=100005;
vector<int> e[N];
int dep[N],f[N],ok[N];
int cnt[N],fa[N][18];
int n,m;
int get(int x){
	return x==f[x]?x:f[x]=get(f[x]);
}
void dfs(int x){
	dep[x]=dep[fa[x][0]]+1;
	for (auto i:e[x])
		if (!dep[i]){
			fa[i][0]=x; dfs(i);
			if (get(x)==get(i)) ok[x]|=ok[i];
		}
		else if (dep[i]+1<dep[x]){
			if ((dep[i]+dep[x]+1)&1) ok[x]=1;
			for (int y=get(x);dep[i]+1<dep[y];y=get(y)) f[y]=fa[y][0];
		}
}
void dfs2(int x){
	cnt[x]+=ok[x];
	for (auto i:e[x])
		if (dep[i]==dep[x]+1){
			if (get(x)==get(i)) ok[i]|=ok[x];
			cnt[i]=cnt[x]; dfs2(i);
		}
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	For(i,0,16) if (tmp&(1<<i)) x=fa[x][i];
	Rep(i,16,0) if (fa[x][i]!=fa[y][i])
		x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
bool ask(int x,int y){
	int L=LCA(x,y);
	if (!L) return 0;
	return ((dep[y]+dep[x])&1)||(cnt[x]+cnt[y]-2*cnt[L]);
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	For(i,1,n) f[i]=i;
	For(i,1,n) if (!dep[i]) dfs(i);
	For(i,1,16) For(j,1,n)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	For(i,1,n) if (dep[i]==1) dfs2(i);
	scanf("%d",&m);
	while (m--){
		int x,y;
		scanf("%d%d",&x,&y);
		puts(ask(x,y)?"Yes":"No");
	}
}