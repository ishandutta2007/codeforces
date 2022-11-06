#include<stdio.h>
long long n,m,t,g,a,b,c,d,p,q;
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
int main(){
	scanf("%lld%lld%lld",&n,&m,&t);g=gcd(n,m);p=n/g;q=m/g;
	while(t--){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);b--;d--;
		if(a&1)b/=p;else b/=q;
		if(c&1)d/=p;else d/=q;
		printf("%s\n",b==d?"YES":"NO");
	}
}