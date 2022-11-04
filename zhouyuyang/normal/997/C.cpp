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
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));

#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2

#define INF (1ll<<60)
using namespace std;

const int N=1000005;
const int mo=998244353;
int fac[N],inv[N],n,ans;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	int n;
	scanf("%d",&n);
	fac[0]=inv[0]=inv[1]=1;
	int ans2=power(power(3,n)+mo-3,n);
	ans2=(power(3,1ll*n*n%(mo-1))+mo-ans2)%mo;
	For(i,2,n) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,n) fac[i]=1ll*fac[i-1]*i%mo,inv[i]=1ll*inv[i-1]*inv[i]%mo;
	For(i,1,n){
		int val=power(3,n-i);
		int wzp=power(val+mo-1,n);
		wzp=(wzp+mo-power(val,n))%mo;
		wzp=1ll*wzp*fac[n]%mo*inv[n-i]%mo*inv[i]%mo;
		UPD(ans,(i&1?mo-wzp:wzp));
	}
	ans2=(2ll*ans2+3ll*mo-3ll*ans)%mo;
	printf("%d\n",ans2);
	/*
	C(n,i)*C(n,j)*3^(n-i)*(n-j)*-1 (i+j)
	C(n,j)*-1(j)*3^(n-j)
	*/
}
/*
+1 -2 +1
-2 +12 -18
+1 -18 +81
=-1+12+81-36=81-25=
*/