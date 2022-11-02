#include<bits/stdc++.h>
using namespace std;
const int N=4040,mod=1000000007;
int n;
long long C[N][N]={},f[N][2]={};
int main()
{	
	cin>>n;
	C[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	f[0][0]=1;
	f[0][1]=0;
	for(int i=1;i<=n;++i)
	{
		f[i][1]=(f[i-1][0]+f[i-1][1])%mod;
		for(int j=0;j<i;++j)
		{
			f[i][0]=(f[i][0]+f[j][0]*C[i-1][j])%mod;
			f[i][1]=(f[i][1]+f[j][1]*C[i-1][j])%mod;
		}
	}
	cout<<f[n][1]<<endl;
	return 0;
}