#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second

ll MOD;
ll modpow(ll x,ll k){
	if(k==0)return 1;
	ll ret=modpow(x,k/2);
	ret*=ret; ret%=MOD;
	if(k%2==1){
		ret*=x; ret%=MOD;
	}
	return ret;
}

int main(){
	static ll n;
	static ll a[200010];
	static ll cnt[1002]={};
	scanf("%lld%lld",&n,&MOD);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		cnt[a[i]%MOD]++;
	}
	
	for(int i=0;i<MOD;i++){
		if(cnt[i]>1){
			puts("0");
			return 0;
		}
	}
	
	ll ret=1;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ret*=abs(a[i]-a[j]);
			ret%=MOD;
		}
	}
	cout<<ret<<endl;
}