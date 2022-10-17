#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7,P=998244353;

typedef long long ll;

int T,n;

char s[N];

ll qpow(ll a,ll b)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%P;
		b>>=1;
		a=a*a%P;
	}
	return ret;
}

ll fac[N],inv[N];

void pre(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%P;
	inv[n]=qpow(fac[n],P-2);
	for(int i=n-1;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%P;
}

int main()
{
	pre(100000);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		int t=n,m=0;
		for(int i=1,j;i<=n;i=j)
		{
			j=i;
			if(s[i]=='0')
			{
				j++;
				continue;
			}
			while(j<=n&&s[j]=='1')
				j++;
			int k=j-i;
			t-=k&1;
			m+=k/2;
		}
		printf("%lld\n",fac[t-m]*inv[m]%P*inv[t-m*2]%P);
	}
}