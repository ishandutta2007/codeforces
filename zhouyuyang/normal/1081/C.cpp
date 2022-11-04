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
int n,m,k,f[2005][2005];
const int mo=998244353;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	f[1][0]=m;
	for (int i=2;i<=n;i++)
		for (int j=0;j<=i;j++){
			f[i][j]=(f[i][j]+f[i-1][j])%mo;
			f[i][j+1]=(f[i][j+1]+1ll*f[i-1][j]*(m-1))%mo;
		}
	printf("%d\n",f[n][k]);
}