#include<bits/stdc++.h>
using namespace std;
const int N=110,M=110;
int n,m;
long long a[N]={},b[M]={},s[N][M]={},mod=0;
long long gcd(long long a,long long b)
{
	return b ? gcd(b,a%b) : a;
}
int main()
{	
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			cin>>s[i][j];
	int t=min_element(s[1]+1,s[1]+m+1)-s[1];
	for(int i=1;i<=n;++i)
		a[i]=s[i][t];
	for(int j=1;j<=m;++j)
		b[j]=s[1][j]-a[1];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			long long tmp=s[i][j]-a[i]-b[j];
			if(tmp<0)
				tmp=-tmp;
			mod=gcd(tmp,mod);
		}
	if(mod)
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				if((a[i]+b[j])%mod!=s[i][j])
				{
					puts("NO");
					return 0;
				}
	}
	else
		mod=100000000000;
	puts("YES");
	cout<<mod<<endl;
	for(int i=1;i<=n;++i)
		cout<<a[i]<<' ';
	cout<<endl;
	for(int j=1;j<=m;++j)
		cout<<b[j]<<' ';
	cout<<endl;
	return 0;
}