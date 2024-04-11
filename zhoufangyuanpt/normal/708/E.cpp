#include<cstdio>
#include<cstring>
using namespace std;
long long ksm(long long x,long long k)
{
	long long s=1;
	while(k>0)
	{
		if(k&1)s=s*x%1000000007;
		x=x*x%1000000007;
		k>>=1;
	}
	return s;
}
long long jc[110000],fjc[110000];
inline long long C(int n,int m){return n<m?0:jc[n]*fjc[n-m]%1000000007*fjc[m]%1000000007;}
long long f[1600],F[1600],t[1600];
int main()
{
	int n,m,k;long long a,b;
	scanf("%d%d%lld%lld%d",&n,&m,&a,&b,&k);
	long long p=a*ksm(b,1000000005)%1000000007,pp=(b-a)*ksm(b,1000000005)%1000000007;
	jc[0]=1;
	for(int i=1;i<=k;i++)jc[i]=jc[i-1]*i%1000000007;
	fjc[k]=ksm(jc[k],1000000005);
	for(int i=k-1;i>=0;i--)fjc[i]=fjc[i+1]*(i+1)%1000000007;
	for(int i=0;i<=m;i++)t[i]=C(k,i)*ksm(p,i)%1000000007*ksm(pp,k-i)%1000000007;
	for(int i=1;i<m;i++)f[i]=0;f[m]=1;F[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)F[j]=(F[j-1]+f[j])%1000000007;
		long long s=0,sss=0;
		for(int j=1;j<=m;j++)
		{
			s=(s+t[j-1])%1000000007;
			sss=(sss+t[j-1]*F[j-1])%1000000007;
			f[j]=((F[m]-F[m-j]+1000000007)*s-sss+1000000007)%1000000007*t[m-j]%1000000007;
		}
	}
	long long ss=0;
	for(int i=1;i<=m;i++)ss=(ss+f[i])%1000000007;
	printf("%lld\n",ss);
	return 0;
}