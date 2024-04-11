#include<bits/stdc++.h>
using namespace std;
const int N=2020,K=2020,mod=1000000007;
int n,k;
long long f[N][K]={},s[N][K]={};
char ch[N]={};
int main()
{	
	cin>>n>>k>>(ch+1);
	f[0][0]=s[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=k;++j)
		{
			f[i][j]=s[i-1][j]*(ch[i]-'a');
			for(int l=0; l<i && (l+1)*(n-i+1)<=j;++l)
				f[i][j]+=f[i-l-1][j-(l+1)*(n-i+1)]*('z'-ch[i]);
			f[i][j]%=mod;
		}
		for(int j=0;j<=k;++j)
			s[i][j]=(f[i][j]+s[i-1][j])%mod;
	}
	cout<<s[n][k]<<endl;
	return 0;
}