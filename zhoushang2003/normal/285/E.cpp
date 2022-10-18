#include<iostream>
using namespace std;
const int N=1e3+1,D=1e9+7;
long long t,n,k,f[N],g[N],a[N],b[N],A;
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
	cin>>n>>k;
	a[0]=1;
	for(int i=1;i<N;i++)
		a[i]=a[i-1]*i%D;
	b[N-1]=P(a[N-1],D-2);
	for(int i=N-2;i>=0;i--)
		b[i]=b[i+1]*(i+1)%D;
	for(int i=0;i<=n/2;i++)
		g[i]=C(n-i,i);
	for(int i=0;i<=n/2;i++)
		for(int j=0;j<=n/2;j++)
			f[i+j]=(f[i+j]+g[i]*g[j])%D;
	for(int i=0;i<=n;i++)
		(f[i]*=a[n-i])%=D;
	for(int i=k;i<=n;i++)
		(A+=f[i]*C(i,k)%D*(1-(i-k)%2*2))%=D;
	cout<<(A+D)%D;
	return 0;
}