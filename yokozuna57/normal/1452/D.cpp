#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD=998244353;

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
	int n;
	cin>>n;
	
	ll dp[200010];
	ll inv=modpow(2,MOD-2);
	
	dp[0]=1;
	dp[1]=inv;
	dp[2]=inv*inv%MOD;
	for(int i=3;i<=n;i++){
		dp[i]=dp[i-2]*inv%MOD;
		dp[i]+=dp[i-1];
		dp[i]*=inv;
		dp[i]%=MOD;
	}
	cout<<dp[n]<<endl;
}