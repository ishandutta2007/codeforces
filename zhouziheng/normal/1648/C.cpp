#include<cstdio>

using namespace std;

const long long MOD=998244353,G=3;
int add(int x,int y){return x+y>=MOD?x+y-MOD:x+y;}
int sub(int x,int y){return x>=y?x-y:x+MOD-y;}

long long fast_pow(long long b,long long p)
{
	long long ans=1;while(p){if(p&1)ans=ans*b%MOD;b=b*b%MOD;p>>=1;}
	return ans;
}
long long INV(long long x){return fast_pow(x,MOD-2);}
long long fac[300000],invf[300000];
void init_fac(int n)
{
	fac[0]=1;for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%MOD;
	invf[n]=INV(fac[n]);for(int i=n-1;i>=0;i--)invf[i]=invf[i+1]*(i+1)%MOD;
}

int s[300000],t[300000],cnt[300000];

struct BIT
{
	int num[300000];
	int n;
	int lowbit(int x){return x&-x;}
	void init(int N){n=N;}
	void add(int x,int y){while(x<=n){num[x]+=y;x+=lowbit(x);}}
	int calc(int x){int ans=0;while(x){ans+=num[x];x-=lowbit(x);}return ans;}
}B;

int main()
{
	int n=0,m=0;scanf("%d%d",&n,&m);B.init(200000);init_fac(200000);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]),cnt[s[i]]++,B.add(s[i],1);
	for(int i=1;i<=m;i++)scanf("%d",&t[i]);
	//printf("%d %d\n",B.calc(1),B.calc(2));
	long long ans=0,pro=1;for(int i=1;i<=200000;i++)pro=pro*invf[cnt[i]]%MOD;
	for(int i=1;i<=m;i++)
	{
		if(i==n+1){ans=add(ans,1);break;}
		ans=add(ans,fac[n-i]*B.calc(t[i]-1)%MOD*pro%MOD);//printf("%lld %lld %lld\n",fac[n-i],B.calc(t[i]-1),ans);
		if(cnt[t[i]]==0)break;pro=pro*cnt[t[i]]%MOD;
		cnt[t[i]]--;B.add(t[i],-1);//printf("%lld %d %d\n",ans,B.calc(1),B.calc(2));
	}
	printf("%lld",ans);
}