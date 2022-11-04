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

#define INF ((1<<30)-233)
#define sqr(x) ((x)*(x))
#define debug puts("wzpkking")
using namespace std;
int mu[66];
void init(){
	mu[1]=1;
	for (int i=1;i<=59;i++)
		for (int j=i*2;j<=59;j+=i) mu[j]-=mu[i];
}
void solve(){
	ll n,ans; scanf("%lld",&n); ans=n-1;
	for (int i=2;i<=59;i++){
		if (!mu[i]) continue;
		ll limit=(ll)pow(n,1.0/i);
		for (;;){
			limit++;
			ll tmp=n;
			for (int j=1;j<=i;j++) tmp/=limit;
			if (!tmp){
				limit--;
				break;
			}
		}
		ans+=(limit-1)*mu[i];
	}
	printf("%lld\n",ans);
}
int main(){
	init(); int T;
	scanf("%d",&T);
	while (T--) solve();
}