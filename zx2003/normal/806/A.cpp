#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,x,y,p,q;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
int main(){
	cin>>T;
	while(T--){
		cin>>x>>y>>p>>q;
		if(p==0 && x>0){
			puts("-1");
			continue;
		}
		if(p==q && x<y){
			puts("-1");
			continue;
		}
		if(x*q==y*p){
			puts("0");continue;
		}
		ll d=gcd(p,q);
		p/=d;q/=d;
		ll l=1,r=1000000000,m;
		for(;l<r;){
			m=(l+r)>>1;
			if(p*m<x || q*m<y || q*m-y<p*m-x)l=m+1;
				else r=m;
		}
		cout<<q*l-y<<'\n';
	}
	return 0;
}