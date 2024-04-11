#include<cstdio>
#include<algorithm>

using namespace std;

int gcd(int x,int y){return y?gcd(y,x%y):x;}

const long long MOD=998244353,G=3;
long long add(long long x,long long y){return x+y>=MOD?x+y-MOD:x+y;}
long long sub(long long x,long long y){return x>=y?x-y:x+MOD-y;}

long long fast_pow(long long b,long long p)
{
	long long ans=1;while(p){if(p&1)ans=ans*b%MOD;b=b*b%MOD;p>>=1;}
	return ans;
}
long long INV(long long x){return fast_pow(x,MOD-2);}

long long fac[2000000],invf[2000000];
void init_fac(int n)
{
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%MOD;
	invf[n]=INV(fac[n]);for(int i=n-1;i>=0;i--)invf[i]=invf[i+1]*(i+1)%MOD;
}
long long C(int n,int m)
{
	if(n<0||m<0||n<m)return 0;return fac[n]*invf[m]%MOD*invf[n-m]%MOD;
}

int cnt[2000000];

long long phi[2000000],mu[2000000];
bool prm[2000000];int prm_lst[2000000],prm_cnt;

void init_mu(int n)
{
	for(int i=2;i<=n;i++)prm[i]=1;
	mu[1]=1,phi[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(prm[i])prm_lst[++prm_cnt]=i,mu[i]=MOD-1,phi[i]=i-1;
		for(int j=1;j<=prm_cnt&&prm_lst[j]*i<=n;j++)
		{
			int x=prm_lst[j];prm[x*i]=0;
			if(i%x==0)
			{
				mu[i*x]=0;phi[i*x]=phi[i]*x;break;
			}
			mu[i*x]=mu[i]*mu[x]%MOD,phi[i*x]=phi[i]*phi[x];
		}
	}
}

long long f[2000000],g[2000000];
int main()
{
	int T=0;scanf("%d",&T);init_fac(1000000),init_mu(1000000);
	while(T--)
	{
		int n=0;scanf("%d",&n);
		for(int i=1;i<=n;i++)cnt[i]=0;int d=0;
		for(int i=1,a=0;i<=n;i++){scanf("%d",&a);cnt[a]++;}
		for(int i=1;i<=n;i++)d=gcd(d,cnt[i]);
		sort(cnt+1,cnt+n+1);reverse(cnt+1,cnt+n+1);
		if(d==n){puts("1");continue;}
		for(int i=1;i<=d;i++)
		{
			f[i]=g[i]=0;
			if(d%i!=0)continue;
			g[i]=fac[n/i];
			for(int j=1;j<=n;j++)
			{
				if(cnt[j]==0)continue;
				
				f[i]=add(f[i],n*C(n/i-2,cnt[j]/i-2)%MOD*INV(C(n/i,cnt[j]/i))%MOD);
				g[i]=g[i]*invf[cnt[j]/i]%MOD;
				//printf("%lld %lld %lld\n",C(n/i-2,cnt[j]/i-2),C(n/i,cnt[j]/i),f[i]);
			}
			f[i]=f[i]*g[i]%MOD;
		}
		//printf("%lld %lld\n",f[1],f[2]);
		//for(int i=1;i<=d;i++)printf("%lld ",phi[i]);puts("");
		long long ans=0,ansg=0;for(int i=1;i<=d;i++)ans=add(ans,phi[i]*f[i]%MOD),ansg=add(ansg,phi[i]*g[i]%MOD);
		ans=ans*INV(ansg)%MOD;
		printf("%lld\n",sub(n,ans));
	}
}