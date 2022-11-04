#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator

#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
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

const int N=255;
int n,mid;
int ls[N],rs[N],a[N],sz[N];
int f[N][2][3],vis[N][2][3];
int dfs(int x){
	if (a[x]!=-1) return sz[x]=0;
	sz[x]=dfs(ls[x])+dfs(rs[x])+1;
	if (sz[rs[x]]&1) swap(ls[x],rs[x]);
	return sz[x];
}
bool merge(bool x,bool y,bool tp){
	return tp?x&y:x|y;
}
//f[i][j][k]:subT i,ok to skip(k),operator j
bool dp(int n,int p,int s){
	if (a[n]!=-1) return a[n]>=mid;
	if (sz[n]==1) return merge(a[ls[n]]>=mid,a[rs[n]]>=mid,p^(s==2));
	if (vis[n][p][s]) return f[n][p][s];
	vis[n][p][s]=1;
	if (s){
		if (!(sz[ls[n]]&1)){
			f[n][p][s]=dp(n,!p,0);
			if (sz[rs[n]]){
				int val0=dp(rs[n],p,1+(!sz[ls[n]]&&s==1));
				int val1=dp(ls[n],!p,0);
				int val=merge(val0,val1,!p);
				f[n][p][s]=merge(f[n][p][s],val,p);
			}
			if (sz[ls[n]]){
				int val0=dp(ls[n],p,1+(!sz[rs[n]]&&s==1));
				int val1=dp(rs[n],!p,0);
				int val=merge(val0,val1,!p);
				f[n][p][s]=merge(f[n][p][s],val,p);
			}
			//even-even-skip
		}
		else if (sz[rs[n]]&1){
			f[n][p][s]=dp(n,!p,0);
			{
				int val0=dp(rs[n],!p,1+(sz[ls[n]]==1&&s==1));
				int val1=dp(ls[n],p,0);
				int val=merge(val0,val1,!p);
				f[n][p][s]=merge(f[n][p][s],val,p);
			}
			{
				int val0=dp(ls[n],!p,1+(sz[rs[n]]==1&&s==1));
				int val1=dp(rs[n],p,0);
				int val=merge(val0,val1,!p);
				f[n][p][s]=merge(f[n][p][s],val,p);
			}
		}
		else{
			int val0=dp(rs[n],p,0);
			int val1=dp(ls[n],p,1+(!sz[rs[n]]&&s==1));
			f[n][p][s]=merge(val0,val1,p);
		}
	}
	else{
		if (!(sz[ls[n]]&1))
			f[n][p][s]=merge(dp(ls[n],p,0),dp(rs[n],p,0),p);
			//even-even-noskip
		else if (sz[rs[n]]&1)
			f[n][p][s]=merge(dp(ls[n],p,1),dp(rs[n],p,1),p);
			//odd-odd-noskip
		else{
			int val0=merge(dp(ls[n],p,0),dp(rs[n],!p,0),!p);
			int val1=merge(dp(rs[n],p,1),dp(ls[n],!p,1),!p);
			f[n][p][s]=merge(val0,val1,p);
			//odd-even-noskip
		}
	}
	return f[n][p][s];
}
void solve(){
	scanf("%d",&n);
	For(i,0,n-1){
		scanf("%d",&a[i]);
		if (a[i]==-1) scanf("%d%d",&ls[i],&rs[i]);
	}
	dfs(0);
	int l=0,r=1001,ans=0;
	while (l<=r){
		mid=(l+r)/2;
		CLR(vis,0);
		if (dp(0,0,0))
			ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}