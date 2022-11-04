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
const int N=200005;
vector<int> e[N];
pii mx[N],mx2[N],ans;
int dep[N],n,p;
void dfs(int x,int fa){
	mx[x]=pii(-1,x);
	mx2[x]=pii(-1,0);
	for (auto i:e[x]) if (i!=fa){
		dep[i]=dep[x]+1; dfs(i,x);
		if (mx[i].fi>mx[x].fi) mx2[x]=mx[x],mx[x]=mx[i];
		else if (mx[i].fi>mx2[x].fi) mx2[x]=mx[i];
	}
	mx[x].fi++; mx2[x].fi++;
	if ((e[x].size()-(fa!=0))>=2){
		pii tmp(dep[x],mx[x].fi+mx2[x].fi);
		if (tmp>ans) ans=tmp,p=x;
	}
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	int x1,x2,x3,x4;
	dfs(1,0); 
	x1=mx[p].se,x2=mx2[p].se;
	ans=pii(0,0); dep[p]=0;
	dfs(p,0);
	printf("%d %d\n%d %d\n",x1,mx[p].se,x2,mx2[p].se);
}