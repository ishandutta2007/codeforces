#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
set<ll>st;
ll n;
void sol(ll x){
	ll z=n/x;
	st.insert(z*(z-1)/2*x+(n/x));
}
int main(){
	scanf("%lld",&n);
	for(ll i=1;i*i<=n;++i)if(n%i==0){
		sol(i),sol(n/i);
	}
	for(auto s:st)printf("%lld ",s);
}