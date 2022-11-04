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
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define inf (1ll<<60)
using namespace std;
#define gc getchar
inline int read(){
	int x=0;
	char ch=gc();
	for (;ch<'0'||ch>'9';ch=gc());
	for (;ch>='0'&&ch<='9';ch=gc())
		x=x*10-48+ch;
	return x;
}
const int N=400;
int T,mo,f[N+5][N+5];
int fac[N+5],g[N+5],h[N+5];
int main(){
	scanf("%d%d",&T,&mo);
	fac[0]=f[0][0]=1;
	For(i,1,N) fac[i]=g[i]=h[i]=1ll*fac[i-1]*i%mo;
	For(i,1,N) For(j,1,i-1) g[i]=(g[i]+mo-1ll*g[j]*fac[i-j]%mo)%mo;
	For(i,1,N) For(j,1,i) For(k,1,i-j+1) f[i][j]=(f[i][j]+1ll*f[i-k][j-1]*fac[k])%mo;
	For(i,1,N) For(j,1,i-1) h[i]=(h[i]+mo-2ll*g[j]*fac[i-j]%mo)%mo;
	For(i,1,N) For(j,3,i-1) h[i]=(h[i]+mo-1ll*h[j]*f[i][j]%mo)%mo;
	h[2]=2;
	while (T--) printf("%d\n",h[read()]);
}