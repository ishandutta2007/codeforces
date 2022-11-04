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
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)%s
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
const int N=1000005;
vector<int> e[N],E[N],S,T;
int ok[25],vis[N],cnt[N*2],n,m;
void dfs(int x){
	if (vis[x]) return;
	vis[x]=1;
	for (auto i:e[x]) dfs(i);
} 
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); E[y].PB(x);
	}
	For(i,1,n){
		if (!e[i].size()) T.PB(i);
		if (!E[i].size()) S.PB(i);
	}
	int sz=S.size();
	For(i,0,sz-1){
		CLR(vis,0); dfs(S[i]);
		For(j,0,sz-1)
			if (vis[T[j]]) ok[i]|=1<<j;
	}
	For(i,0,(1<<sz)-1) cnt[i]=cnt[i/2]+(i&1);
	For(i,0,(1<<sz)-1){
		int res=0;
		For(j,0,sz-1) if (i&(1<<j)) res|=ok[j];
		int cnt1=cnt[i],cnt2=cnt[res];
		if (cnt2<cnt1||(cnt2==cnt1&&cnt1!=0&&cnt1!=sz))
			return puts("NO"),0;
	}
	puts("YES");
}
/*
V(i,j)*C(k+l-i-j,k-i)*a^(k-i)*b^(l-j)*h^(km+l) 
*/