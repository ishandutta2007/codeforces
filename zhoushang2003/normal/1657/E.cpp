#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3,D=998244353;
int n,m,f[N][N],p[N],t,A;
int P(int a,int b)
{
	t=1;
	while(b)
	{
		if(b&1)
			(t*=a)%=D;
		(a*=a)%=D,b/=2;
	}
	return t;
}
signed main()
{
	cin>>n>>m,f[0][0]=p[0]=1;
	for(int i=1;i<N;i++)
		p[i]=p[i-1]*i%D;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<n;j++)
			f[i][j]=f[i-1][j];
		for(int j=1;j<n;j++)
			for(int k=0;k<j;k++)
				(f[i][j]+=f[i-1][k]*P(p[j-k],D-2)%D*P(m-i+1,(k+j-1)*(j-k)/2))%=D;
	}
	cout<<f[m][n-1]*p[n-1]%D;
}