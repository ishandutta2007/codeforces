#include<bits/stdc++.h>
using namespace std;

int n,mod;

long long int fac[300001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>mod;
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%mod;
	long long int ans=0;
	for(int i=1;i<=n;i++){
		long long int x=(n-i+1);
		x=x*fac[i]%mod;
		x=x*(n-i+1)%mod;
		x=x*fac[n-i]%mod;
		ans=(ans+x)%mod;
	}
	cout<<ans<<endl;
}