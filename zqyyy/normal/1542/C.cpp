#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return f?r:-r;
}
const int mod=1e9+7;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
ll n,x,y;
inline void work(){
	n=read(),x=1,y=1;ll ans=0;
	if(n==1){puts("2");return;}
	if(n==2){puts("5");return;}
	for(int i=2;i<=n;i++){
		y=lcm(x,i);
		(ans+=(n/x-n/y)*i)%=mod;
		 x=y;if(x>n)break;
	}
	printf("%lld\n",ans);
}
int main(){
	int T=read();
	while(T--)work();
	return 0;	
}