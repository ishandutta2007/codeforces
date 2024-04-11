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

#define INF (1ll<<60)
#define sqr(x) ((x)*(x))
using namespace std;
const int N=100005;
int h[N][7],w[N][7],n,m;
ll f[40];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m-1) For(j,0,n-1) scanf("%d",&w[i][j]);
	For(i,0,m-1) For(j,0,n-1) scanf("%d",&h[i][j]);
	For(i,1,(1<<n)-1) f[i]=INF;
	For(i,1,m-1) For(j,0,(1<<n)-1){
		For(k,0,n-1) if (!(j&(1<<k)))
			f[j^(1<<k)]=min(f[j^(1<<k)],f[j]+w[i][k]);
		For(k,0,n-1) if (((j>>k)^(j>>((k+1)%n)))&1) f[j]+=h[i][k]; 
	}
	printf("%lld",f[(1<<n)-1]);
}