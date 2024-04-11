#include<bits/stdc++.h>
using namespace std;
const int N=4e5+1,M=2e3+1,D=1e9+7;
long long a[N],b[N],r,c,n,t,A,f[N];
pair<int,int>p[M];
long long P(long long a,long long b)
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
long long C(int n,int m)
{
	return a[n]*b[m]%D*b[n-m]%D;
}
int main()
{
	a[0]=1;
	for(int i=1;i<N;i++)
		a[i]=a[i-1]*i%D;
	b[N-1]=P(a[N-1],D-2);
	for(int i=N-1;i>0;i--)
		b[i-1]=b[i]*i%D;
	cin>>r>>c>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	sort(p+1,p+n+1),A=C(r+c-2,r-1);
	for(int i=1;i<=n;i++)
	{
		f[i]+=C(p[i].first+p[i].second-2,p[i].first-1),(A-=C(r+c-p[i].first-p[i].second,r-p[i].first)*f[i])%=D;
		for(int j=i+1;j<=n;j++)
			if(p[j].second>=p[i].second)
				(f[j]-=C(p[j].first+p[j].second-p[i].first-p[i].second,p[j].first-p[i].first)*f[i])%=D;
	}
	cout<<(A+D)%D;
	return 0;
}