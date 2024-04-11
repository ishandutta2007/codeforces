#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint ungigned
#define db long double
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
const int N=22,M=(1<<22)+5;
int n,m,T,ans;
int P[N],a[N][N];
int v[M],dp[M],sum[M];
int f[N],mk[N];
char s[M];
int main(){
	scanf("%d%d%d%s",&n,&m,&T,s+1);
	For(i,0,m) P[i]=1<<i;
	For(i,0,m-1) scanf("%d",&v[P[i]]);
	For(i,0,m-1) For(j,0,m-1) scanf("%d",&a[i][j]);
	For(i,1,n){
		int k=s[i]-'A';
		For(j,0,m-1) if (f[j]){
			if (f[k]>f[j]) continue;
			dp[mk[j]]+=a[j][k];
			dp[mk[j]|P[j]]-=a[j][k];
			dp[mk[j]|P[k]]-=a[j][k];
			dp[mk[j]|P[j]|P[k]]+=a[j][k];
		}
		f[k]=i; mk[k]=0;
		For(j,0,m-1) if (j!=k) mk[j]|=P[k];
	}
	For(i,0,m-1) For(j,1,P[m]-1)
		if (j&P[i]) dp[j]+=dp[j^P[i]];
	For(i,1,P[m]-1) sum[i]=sum[i-(i&(-i))]+v[i&(-i)];
	int tmp=0,ans=0;
	For(i,0,m-1) if (!f[i]) tmp|=P[i];
	For(i,0,P[m]-1) if (dp[i]+sum[i]<=T&&!(i&tmp)&&(i|tmp)!=(P[m]-1)) ans++;
	printf("%d",ans);
}