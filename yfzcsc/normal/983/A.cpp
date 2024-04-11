#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int T;
	ll p,q,A;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld",&p,&q,&A);
		ll g=__gcd(p,q);
		p/=g,q/=g;
		if(p==0){
			puts("Finite");
		} else {
			while(true){
				ll t=__gcd(q,A);
				if(t==1)break;
				q/=t,A=t;
			} 
			if(q!=1)puts("Infinite");
			else puts("Finite");
		} 
	}
}