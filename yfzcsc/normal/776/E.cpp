#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;
ll phi(ll x){
	ll ans=1;
	for(ll i=2;i*i<=x;i++)if(x%i==0){
		ans*=i-1,x/=i;
		while(x%i==0)x/=i,ans*=i;
	}
	if(x>1)ans*=x-1;
	return ans;
}
int main(){
	ll n,k;cin>>n>>k;n=phi(n);
	for(ll i=2;i<=k;i++){
		if(n==1)break;
		if(i%2==1)n=phi(n);
	}
	cout<<n%mod;
}