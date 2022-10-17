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

inline void Min(ll &u,ll v){if(v<u) u=v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
int main()
{
	ll i,j,mn,mx;
	cin>>T;
	while(T--)
	{
		ll ans=0,cnt=0;
		priority_queue<ll>pq;
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=m;i++) scanf("%lld",&num[i]);
		sort(num+1,num+m+1);
		for(i=1;i<m;i++)
		{
			if(num[i+1]-num[i]-1)
				pq.push(num[i+1]-num[i]-1);
		}
		if(num[1]+n-num[m]-1) pq.push(num[1]+n-num[m]-1);
		for(;!pq.empty();)
		{
			ll now=pq.top();
			pq.pop();
			now-=cnt*2;
			if(now>1) now--;
			if(now<=0) break;
			ans+=now;
			cnt+=2;
		}
		printf("%lld\n",n-ans);
	}
}