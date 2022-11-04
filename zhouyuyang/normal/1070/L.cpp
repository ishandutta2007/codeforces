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
const int N=2005;
int n,m,ans[N],h[N];
bitset<N> a[N];
vector<int> e[N];
bool check1(){
	For(i,1,n)
		if (e[i].size()&1)
			return 0;
	return 1;
}
void gauss(){
	int it=1;
	For(i,1,n){
		int j=it;
		for (;j<=n;j++)
			if (a[j][i]) break;
		if (j>n) continue;
		if (j>it) swap(a[j],a[it]);
		h[it]=i;
		For(j,it+1,n) if (a[j][i])
			a[j]^=a[it];
		it++;
	}
	int las=n+1;
	Rep(i,it-1,1){
		For(j,h[i]+1,las-1) ans[j]=0;
		ans[h[i]]=a[i][0];
		For(j,1,i-1) if (a[j][h[i]]) a[j]^=a[i];
		las=h[i];
	}
	For(i,1,las-1) ans[i]=0;
}
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) e[i].clear();
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	if (check1()){
		puts("1");
		For(i,1,n) printf("1 ");
		puts("");
		return;
	}
	For(i,1,n){
		a[i]=0;
		for (auto j:e[i]) a[i].set(j);
		if (e[i].size()&1)
			a[i].set(i),a[i].set(0);
	}
	CLR(ans,0);
	gauss();
	puts("2");
	For(i,1,n)
		printf("%d ",ans[i]+1);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}