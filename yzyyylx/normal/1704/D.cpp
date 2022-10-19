#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 200100
#define M 
using namespace std;

ll T,n,m,num[N];
map<ll,ll>mm;

inline void Min(ll &u,ll v){if(v<u) u=v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
int main()
{
	ll i,j,t,A,B;
	cin>>T;
	while(T--)
	{
		mm.clear();
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			ll sum=0;
			for(j=1;j<=m;j++)
			{
				scanf("%lld",&t);
				sum+=j*t;
			}
			num[i]=sum;
			mm[sum]++;
			if(mm[sum]>1) A=sum;
		}
		for(i=1;i<=n;i++)
		{
			if(num[i]!=A)
			{
				printf("%lld %lld\n",i,num[i]-A);
				break;
			}
		}
	}
}