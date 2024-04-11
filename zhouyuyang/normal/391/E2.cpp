#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
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
#define SUB(i,j) for (int all=(int)(j+2147483648ll),i=(int)(j);i>=0;i=(i-1)&j) 
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1<<30)
using namespace std;
const int N=300005;
struct Tree{
	vector<int> e[N];
	ll dis[N],sz[N],Dis[N];
	ll val,mx;
	int n;
	void add(int x,int y){
		e[x].PB(y); e[y].PB(x);
	}
	void dfs(int x,int fa){
		dis[x]=0; sz[x]=1;
		For(i,0,e[x].size()-1){
			int to=e[x][i];
			if (to!=fa){
				dfs(to,x);
				sz[x]+=sz[to];
				dis[x]+=sz[to]+dis[to];
			}
		}
	}
	void dfs2(int x,int fa){
		For(i,0,e[x].size()-1){
			int to=e[x][i];
			if (to!=fa){
				Dis[to]=Dis[x]+n-2*sz[to];
				dfs2(to,x);
			}
		}
	}
	void init(){
		For(i,1,n-1){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		dfs(1,0);
		Dis[1]=dis[1];
		dfs2(1,0); val=0;
		For(i,1,n){
			val+=Dis[i];
			mx=max(mx,Dis[i]);
		}
	}
}T0,T1,T2;
ll val;
int dep[N];
pll solve(int x,int fa,Tree &T0,Tree &T1,Tree &T2){
	pll ans=pll(0,0);
	ans.fi=max(ans.fi,1ll*(T1.mx+T1.n)*(T0.n+T2.n)+1ll*T0.Dis[x]*T1.n+1ll*dep[x]*T1.n*T2.n);
	ans.se=max(ans.se,1ll*(T2.mx+T2.n)*(T0.n+T1.n)+1ll*T0.Dis[x]*T2.n+1ll*dep[x]*T1.n*T2.n);
	ll del=2ll*dep[x]*T1.n*T2.n;
	val=max(val,ans.fi+ans.se-del);
	For(i,0,T0.e[x].size()-1){
		int to=T0.e[x][i];
		if (to==fa) continue;
		dep[to]=dep[x]+1;
		pll tmp=solve(to,x,T0,T1,T2);
		val=max(val,ans.fi+tmp.se-del);
		val=max(val,ans.se+tmp.fi-del);
		ans.fi=max(ans.fi,tmp.fi);
		ans.se=max(ans.se,tmp.se);
	}
	return ans;
}
int main(){
	scanf("%d%d%d",&T0.n,&T1.n,&T2.n);
	T0.init(); T1.init(); T2.init();
	solve(1,0,T0,T1,T2);
	solve(1,0,T1,T2,T0);
	solve(1,0,T2,T0,T1);
	printf("%lld\n",(T0.val+T1.val+T2.val)/2+val);
}