#include<bits/stdc++.h>
using namespace std;
const int N=100010,mod=1000000007;
int n;
char s[N]={},t[N]={};
long long f[N][4]={};
int main()
{
	cin>>n>>(s+1)>>(t+1);
	f[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		if(isdigit(s[i]))
			if(isdigit(t[i]))
				if(s[i]>t[i])
					for(int k=0;k<4;++k)
						(f[i][k|1]+=f[i-1][k])%=mod;
				else if(s[i]<t[i])
					for(int k=0;k<4;++k)
						(f[i][k|2]+=f[i-1][k])%=mod;
				else
					for(int k=0;k<4;++k)
						(f[i][k]+=f[i-1][k])%=mod;
			else
				for(int k=0;k<4;++k)
				{
					(f[i][k|1]+=f[i-1][k]*(s[i]-'0'))%=mod;
					(f[i][k|2]+=f[i-1][k]*('9'-s[i]))%=mod;
					(f[i][k]+=f[i-1][k])%=mod;
				}
		else
			if(isdigit(t[i]))
				for(int k=0;k<4;++k)
				{
					(f[i][k|1]+=f[i-1][k]*('9'-t[i]))%=mod;
					(f[i][k|2]+=f[i-1][k]*(t[i]-'0'))%=mod;
					(f[i][k]+=f[i-1][k])%=mod;
				}
			else
				for(int k=0;k<4;++k)
				{
					(f[i][k|1]+=f[i-1][k]*45)%=mod;
					(f[i][k|2]+=f[i-1][k]*45)%=mod;
					(f[i][k]+=f[i-1][k]*10)%=mod;
				}
	}
	cout<<f[n][3]<<endl;
}