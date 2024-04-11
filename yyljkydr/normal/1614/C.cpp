#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,P=1e9+7;

int T,n,m;

int l,r,x;

int qpow(int a,int b)
{
	int ret=1;
	while(b)
	{
		if(b&1)
			ret=1ll*ret*a%P;
		b>>=1;
		a=1ll*a*a%P;
	}
	return ret;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		int OR=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&l,&r,&x);
			OR|=x;
		}
		long long ans=0;
		for(int i=29;i>=0;i--)
			if(OR>>i&1)
				ans=(ans+1ll*qpow(2,n-1)*(1ll<<i))%P;
		printf("%lld\n",ans);
	}	
}