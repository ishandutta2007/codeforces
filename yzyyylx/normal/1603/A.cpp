#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MN 
#define N 100100
#define M 
using namespace std;

ll T,n,m,num[N];

ll gcd(ll u,ll v){return v?gcd(v,u%v):u;}
int main()
{
	ll i,j,t;
	cin>>T;
	while(T--)
	{
		t=1;
		scanf("%lld",&n);
		for(i=1;i<=n;i++) scanf("%lld",&num[i]);
		for(i=1;i<=n;i++)
		{
			t=t*(i+1)/gcd(t,i+1);
			if(num[i]%t==0) break;
			if(t>1e9)
			{
				i=n+1;
				break;
			}
		}
		if(i<=n) puts("NO");
		else puts("YES");
	}
}