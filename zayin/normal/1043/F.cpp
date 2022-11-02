#include<bits/stdc++.h>
#define maxm 10
#define maxn 300050
#define modu 998244353
using namespace std;
typedef long long LL;

int g;
int cnt[maxn];

LL F[maxn]={1},I[maxn]={1};

int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}

void init()
{
	int n;
	scanf("%d",&n);
	for (int a,i=0;i<n;++i)
	{
		scanf("%d",&a);
		g=gcd(g,a);
		++cnt[a];
	}
}

int mu[maxn];

bool noprime[maxn];
int pnum,p[maxn];

LL pw(LL a,LL k)
{
	LL ans=1;
	for (;k;k>>=1)
	{
		if (k&1)
			ans=ans*a%modu;
		a=a*a%modu;
	}
	return ans;
}

void filchar()
{
	for (int i=1;i<maxn;++i)
		F[i]=F[i-1]*i%modu;
	I[maxn-1]=pw(F[maxn-1],modu-2);
	for (int i=maxn-1;i>1;--i)
		I[i-1]=I[i]*i%modu;

	for (int i=1;i<maxn;++i)
		for (int j=i<<1;j<maxn;j+=i)
			cnt[i]+=cnt[j];

	mu[1]=1;
	for (int i=2;i<maxn;++i)
	{
		if (!noprime[i])
			p[pnum++]=i,mu[i]=-1;
		for (int j=0;j<pnum&&p[j]*i<maxn;++j)
		{
			noprime[i*p[j]]=1;
			if (i%p[j]==0)	break;
			mu[i*p[j]]=-mu[i];
		}
	}

}

LL C(int n,int m)
{
	return n<m?0:F[n]*I[m]%modu*I[n-m]%modu;
}

void solve()
{
	int ans;
	for (ans=1;ans<=8;++ans)
	{
		LL sum=0;
		for (int i=1;i<maxn;++i)
			if (C(cnt[i],ans))
			sum+=mu[i]*C(cnt[i],ans)+modu,sum%=modu;
		if (sum)	break;
	}
	cout<<ans<<endl;
}

int main()
{
	// freopen("c.in","r",stdin);
	init();
	filchar();
	if (g==1)
		solve();
	else
		puts("-1");
	return 0;
}