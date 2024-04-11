#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MN 200
#define B1 23
#define B2 29 
#define N 100100
#define M1 1000000007
#define M2 1000000009
using namespace std;

ll T,n,m,K,num[N];

inline void work(ll u,ll v){num[u]=v,num[v]=u;}
int main()
{
	ll i,j,k,t;
	cin>>T;
	while(T--)
	{
		scanf("%lld%lld",&n,&K);
		for(i=0;i<n;i++) num[i]=-1;
		if(K==n-1)
		{
			if(n==4)
			{
				puts("-1");
				continue;
			}
			else work(n-2,n-1),work(1,3);
		}
		else work(K,n-1);
		for(i=1;i<n-1;i++)
		{
			if(num[i]!=-1) continue;
			if(num[n-i-1]==-1) work(i,n-i-1);
			else work(i,0);
		}
		for(i=0;i<n-1;i++) if(i<num[i]) printf("%lld %lld\n",i,num[i]);
	}
}