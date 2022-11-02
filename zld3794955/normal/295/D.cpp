#include<bits/stdc++.h>
using namespace std;
const int N=2020,M=2020,mod=1000000007;
int n,m,f[N][M]={},ans=0;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=f[i][0]=1,s=0;j<m;++j)
		{
			s=(s+f[i-1][j])%mod;
			f[i][j]=(f[i][j-1]+s)%mod;
		}
	for(int i=1;i<=n;++i)
		for(int j=1,s=0,t=1;j<m;++j)
		{
			s=(s+f[n-i][j])%mod;
			t=(t+s)%mod;
			ans=(ans+(long long)f[i][j]*(m-j)%mod*(t+mod-f[n-i][j])%mod)%mod;
		}
	cout<<ans<<endl;
	return 0;
}