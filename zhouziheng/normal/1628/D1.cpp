#include<cstdio>

using namespace std;

const long long MOD=1e9+7,INV2=(MOD+1)/2;
int add(int x,int y){return x+y>=MOD?x+y-MOD:x+y;}
int sub(int x,int y){return x>=y?x-y:x+MOD-y;}

long long fast_pow(long long b,long long p)
{
	long long ans=1;while(p){if(p&1)ans=ans*b%MOD;b=b*b%MOD;p>>=1;}
	return ans;
}
long long INV(long long x){return fast_pow(x,MOD-2);}


long long fac[3000000],invf[3000000];
void init_fac(int n)
{
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%MOD;
	invf[n]=INV(fac[n]);for(int i=n-1;i>=0;i--)invf[i]=invf[i+1]*(i+1)%MOD;
}
long long C(int n,int m)
{
	return fac[n]*invf[m]%MOD*invf[n-m]%MOD;
}
int main()
{
	int T=0;scanf("%d",&T);init_fac(1000000);
	while(T--)
	{
		int n=0,m=0;long long k=0;scanf("%d%d%lld",&n,&m,&k);
		long long ans=0;if(m==n)ans=n;else if(m==0)ans=0;
		else
		{
			for(int i=1;i<=m;i++)ans=add(ans,(long long)i*C(n-i-1,m-i)%MOD*fast_pow(INV2,n-i)%MOD);
		}
		printf("%lld\n",ans*k%MOD);
		
	}
}