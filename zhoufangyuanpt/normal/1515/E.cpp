#include<cstdio>
#include<cstring>
using namespace std;
int p;
long long jc[1100],fjc[1100];
long long ksm(long long x,long long k)
{
	long long s=1;
	while(k>0)
	{
		if(k&1)s=s*x%p;
		x=x*x%p;
		k>>=1;
	}
	return s;
}
long long f[410][410],g[410];
inline long long C(int n,int m){return jc[n]*fjc[n-m]%p*fjc[m]%p;}
int main()
{
	int n;scanf("%d%d",&n,&p);
	jc[0]=fjc[0]=1;
	for(int i=1;i<=n;i++)
	{
		jc[i]=jc[i-1]*i%p;
		fjc[i]=ksm(jc[i],p-2);
	}
	for(int i=1;i<=n;i++)
	{
		g[i]=0;
		for(int j=1;j<=i;j++)g[i]=(g[i]+C(i-1,j-1))%p;
	}
	memset(f,0,sizeof(f));f[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			for(int k=1;k<=j&&k<=i-2;k++)
			{
				f[i][j]=(f[i][j]+f[i-k-1][j-k]*g[k]%p*C(j,k))%p;
			}
		}
		f[i][i]=g[i];
	}
	long long ss=0;
	for(int i=1;i<=n;i++)ss=(ss+f[n][i])%p;
	printf("%lld\n",ss);
	return 0;
}