#include<bits/stdc++.h>
using namespace std;
const int L=12,mod=1000000007;
long long ans=0;
int m,n,a[L]={},f[L][L][10][2]={},t[L]={},g[L]={};
long long tryy(int s,int d)
{
	if(s<0)
		return 0;
	if(d>6)
		return 1;
	long long sum=0;
	for(int i=0;i<=n;++i)
	{
		--t[i];
		sum=(sum+(t[i]+1)*tryy(s-i,d+1))%mod;
		++t[i];
	}
	return sum;
}
int main()
{
	cin>>m;
	while(m)
		a[++n]=m%10,m/=10;
	for(int d=0;d<=9;++d)
		f[1][d==4 || d==7][d][d>a[1]]=1;
	for(int i=2;i<=n;++i)
		for(int j=0;j<=n;++j)
			for(int d1=0;d1<=9;++d1)
				for(int d2=0;d2<=9;++d2)
				{
					int k=j+(d2==4 || d2==7);
					if(d2>a[i])
						f[i][k][d2][1]+=f[i-1][j][d1][0]+f[i-1][j][d1][1];
					else if(d2<a[i])
						f[i][k][d2][0]+=f[i-1][j][d1][0]+f[i-1][j][d1][1];
					else
					{
						f[i][k][d2][1]+=f[i-1][j][d1][1];
						f[i][k][d2][0]+=f[i-1][j][d1][0];
					}
				}
	for(int j=0;j<=n;++j)
		for(int d=0;d<=9;++d)
			t[j]+=f[n][j][d][0];
	--t[0];
	for(int i=1;i<=n;++i)
		ans=(ans+t[i]*tryy(i-1,1))%mod;
	cout<<ans<<endl;
	return 0;
}