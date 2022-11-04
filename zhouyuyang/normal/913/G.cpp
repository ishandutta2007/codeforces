#include<bits/stdc++.h>
#define ll long long
using namespace std;
int length(ll x){
	if (!x) return 1;
	int ans=1;
	for (;x;x/=10,ans++);
	return ans;
}
ll mul(ll a,ll b,ll mo){
	ll s=0;
	for (;b;b>>=10,a=(a<<10)%mo)
		s=(s+a*(b&1023))%mo;
	return s;
}
ll power(ll a,ll b,ll mo){
	ll s=1;
	for (;b>0;b/=2,a=mul(a,a,mo))
		if (b&1) s=mul(s,a,mo);
	return s;
}
int main(){
	int T; scanf("%d",&T);
	while (T--){
		ll a; scanf("%I64d",&a);
		int n=length(a);
		for (int m=0;;m++){
			ll b=(-a)&((1ll<<(n+m))-1);
			if ((a+b)%5==0) b+=1ll<<(n+m);
			if ((b==0&&m==0)||length(b)<=m){
				ll c=(a+b)>>(n+m);
				ll t;
				if (c%5==0) t=-1;
				if (c%5==1) t=0;
				if (c%5==2) t=1;
				if (c%5==3) t=3;
				if (c%5==4) t=2;
				ll p5=5;
				for (int i=1;i<n+m;i++){
					for (;power(2,t,p5*5)!=c%(p5*5);t+=p5/5*4);
					p5*=5;
				}
				printf("%I64d\n",t+n+m);
				break;
			}
			a*=10;
		}
	} 
}