#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7,P=1e9+7;

ll a,b;

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

int main()
{
	scanf("%lld%lld",&a,&b);
	printf("%lld",qpow((qpow(2,b)-1+P)%P,a));
}