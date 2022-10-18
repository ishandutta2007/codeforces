#include<bits/stdc++.h>
using namespace std;
const long long N=7e4,D=998244353,P=D*D;
int n,k,b[N],f[N],g[N];
long long t,A;
int Q(long long a,int b)
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
int main()
{
	cin>>n>>k,b[0]=g[0]=1,f[0]=n;
	for(int i=1;i<N;i++)
		b[i]=(long long)b[i-1]*Q(i,D-2)%D;
	for(int i=1;i<=2*k;i++)
		f[i]=(long long)f[i-1]*(n-i)%D;
	for(int i=1;i<=k;i++)
		g[i]=(long long)b[i]*Q(f[i-1],D-2)%D;
	for(int i=1;i<=k;i++)
	{
		A=0;
		for(int j=0;j<=i&&j<=n-i;j++)
			A+=(long long)f[i+j-1]*g[j]%D*b[i-j]-P,A+=A>>63&P;
		cout<<A%D<<' ';
	}
	return 0;
}