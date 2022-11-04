#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint ungigned
#define db double
#define PQ priority_queue
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
#define fi first
#define se second
#define BG begin
#define ED end

#define For(i,j,k) for (int i=(j);i<=(int)k;i++)
#define Rep(i,j,k) for (int i=(j);i>=(int)k;i++)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF (1ll<<61)
#define sqr(x) (1ll*(x)*(x))
using namespace std;

const int N=1005;
const int mo=1000000007;
int C[N][N],f[N][N][2][2],g[N];
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	For(i,0,n) C[i][0]=1;
	For(i,1,n) For(j,1,i) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
	f[0][0][1][0]=1;
	For(i,0,n-1) For(j,0,i) For(a,0,1) For(b,0,1){
		int v=f[i][j][a][b];
		if (!v) continue;
		UPD(f[i+1][j][b][0],v);
		UPD(f[i+1][j+1][b][1],v);
		if (!a) UPD(f[i+1][j+1][b][0],v);
	}
	For(i,0,n){
		For(a,0,1) UPD(g[i],f[n][i][a][0]);
		For(j,1,n-i) g[i]=1ll*g[i]*j%mo;
	}
	for (int i=n;i>=k;i--) For(j,i+1,n)
		UPD(g[i],mo-1ll*g[j]*C[j][i]%mo);
	printf("%d\n",g[k]);
}