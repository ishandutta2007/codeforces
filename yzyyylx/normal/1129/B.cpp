#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 5010
#define M 20010
using namespace std;

ll n,K,a,b;

inline void out(ll u,ll v)
{
	ll i;
	for(i=1; i<=u; i++)
	{
		if(v<=1000000) printf("%lld ",v),v=0;
		else printf("1000000 "),v-=1000000;
	}
}

int main()
{
	ll i,j,p,q,t;
	cin>>K;
	for(a=1; a<2000; a++)
	{
		for(b=1; a+b<2000; b++)
		{
			if((K+a+b+1)%(b+1)) continue;
			t=(K+a+b+1)/(b+1);
			if(a*1000000<t) continue;
			printf("%lld\n",a+b+1);
			out(b,0);
			printf("-1 ");
			out(a,t);
			return 0;
		}
		if(a+b<2000) break;
	}
	puts("-1");
}