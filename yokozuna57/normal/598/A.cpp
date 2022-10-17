#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll solve(ll n){
	ll ret=n*(n+1)/2;
	ll x=1;
	while((x<<1)<=n)x<<=1;
	ret-=2*(2*x-1);
	return ret;
}

int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		ll n;
		scanf("%lld",&n);
		printf("%lld\n",solve(n));
	}
}