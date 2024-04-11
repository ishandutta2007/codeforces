#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const int mod=1e9+7;
LL fast(LL x,int p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret; 
}
const int M=2222;
int k,pa,pb,inv,Pa,Pb,coe;
int dp[M][M];
signed main(){
	cin>>k>>pa>>pb; inv=fast(pa+pb,mod-2); Pa=1ll*pa*inv%mod; Pb=1ll*pb*inv%mod; coe=1ll*pa*fast(pb,mod-2)%mod;
	for (int i=k;i;i--){
		for (int j=k;~j;j--){
			if (i+j>=k) dp[i][j]=(i+j+coe)%mod; 
			else dp[i][j]=(1ll*Pa*dp[i+1][j]+1ll*Pb*dp[i][i+j])%mod;
		}
	}
	cout<<dp[1][0]<<"\n";
	return 0;
}