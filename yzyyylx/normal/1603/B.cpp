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
	ll i,j,t,a,b;
	cin>>T;
	while(T--)
	{
		scanf("%lld%lld",&a,&b);
		if(a>b) printf("%lld\n",a+b);
		else if(a==b) printf("%lld\n",a);
		else printf("%lld\n",((b-1)/a*a+b)/2);
	}
}