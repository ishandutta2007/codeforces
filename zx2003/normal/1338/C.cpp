#include<bits/stdc++.h>
typedef long long ll;
int T,mp[4]={0,2,3,1};
ll n,a,b,c;
void getv(ll n){
	ll x=1,y=1;int i=0;
	for(;y+x<=n;y+=x,x*=4,i+=2);
	a=x+n-y;b=x*2;
	for(i-=2;i>=0;i-=2){
		int z=a>>i&3;
		b|=ll(mp[z])<<i;
	}
	c=a^b;
}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%lld",&n);
		getv((n+2)/3);
		printf("%lld\n",n%3==0?c:n%3==2?b:a);
	}
}