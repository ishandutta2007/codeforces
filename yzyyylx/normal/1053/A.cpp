#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 
#define M 
using namespace std;

ll n,m,k,t,a,b;

inline ll gcd(ll u,ll v)
{
	for(;u&&v&&u!=v;)
	{
		swap(u,v);
		u%=v;
	}
	return max(u,v);
}

int main()
{
	ll i,j;
	cin>>n>>m>>k;
	t=gcd(n,k);
	a=n/t,k/=t;
	t=gcd(m,k);
	b=m/t,k/=t;
	if(k>2)
	{
		puts("NO");
		return 0;
	}
	if(k==1)
	{
		if(a*2<=n) a*=2;
		else if(b*2<=m) b*=2;
		else
		{
			puts("NO");
			return 0;
		}
	}
	printf("YES\n0 0\n%lld 0\n0 %lld",a,b);
}