#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
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
#define fi first
#define se second
#define BG begin
#define ED end

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

#define INF (1ll<<61)
#define sqr(x) ((x)*(x))
using namespace std;
const int N=405;
int v[N],a[N],F[N],n;
int f[N][N],u[N][N],d[N][N];
int main(){
	scanf("%d",&n);
	CLR(u,200); CLR(d,200); CLR(f,200);
	For(i,1,n) scanf("%d",&v[i]);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) u[i][i]=d[i][i]=0;
	Rep(i,n,1) For(j,i,n){
		For(k,i,j-1) f[i][j]=max(f[i][j],f[i][k]+f[k+1][j]);
		For(k,i,j-1) if (a[k]==a[j]-1) u[i][j]=max(u[i][j],u[i][k]+(k<j-1?f[k+1][j-1]:0));
		For(k,i+1,j) if (a[k]==a[i]-1) d[i][j]=max(d[i][j],d[k][j]+(k>i+1?f[i+1][k-1]:0));
		For(k,i,j) if (a[k]>=a[i]&&a[k]>=a[j]&&2*a[k]-a[i]-a[j]<=j-i)
			f[i][j]=max(f[i][j],u[i][k]+d[k][j]+v[2*a[k]-a[i]-a[j]+1]);
	} 
	For(i,1,n){
		F[i]=F[i-1];
		For(j,1,i)
			F[i]=max(F[i],F[j-1]+f[j][i]);
	}
	printf("%d\n",F[n]); 
}