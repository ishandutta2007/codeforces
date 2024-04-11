#include<bits/stdc++.h>
#define maxn 150100
using namespace std;
typedef long long ll;
int n;
ll ai[maxn],bi[maxn];
ll ans=0;
ll gt(ll a){
	for(ll i=2;i*i<=a;++i)if(a%i==0)return i;
	return a;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		ans=__gcd(ans,x*y);
		ai[i]=x,bi[i]=y;
	}
	if(ans==1)puts("-1");
	else if(__gcd(ans,ai[1])>1)printf("%lld",gt(__gcd(ans,ai[1])));
	else printf("%lld",gt(__gcd(ans,bi[1])));
}