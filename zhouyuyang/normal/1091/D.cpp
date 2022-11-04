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
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int mo=998244353;
const int N=1000005;
int n;
int fac[N],inv[N];
int C(int x,int y){
	return 1ll*fac[x]*inv[y]%mo*inv[x-y]%mo;
}
int main(){
	scanf("%d",&n);
	fac[0]=inv[0]=inv[1]=1;
	For(i,2,n) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,n){
		fac[i]=1ll*fac[i-1]*i%mo;
		inv[i]=1ll*inv[i-1]*inv[i]%mo;
	}
	int ans=fac[n];
	For(i,1,n-1)
		ans=(ans+1ll*C(n,i)*fac[i]%mo*(fac[n-i]-1))%mo;
	printf("%d\n",ans);
}
/*
1234
1243
1324
1342
1423
1432
2134
2143
2314
2341
2413
2431
3124
3142
3214
3241
3412
3421
4123
4132
4213
4231
4312
4321
*/