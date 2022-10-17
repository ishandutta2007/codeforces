#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 200100
using namespace std;

ll n,m,h[N],d[N],a,b,mx,mm,ans,k;
bool in[N];
priority_queue<P>pq;

int main()
{
	ll i,j,tmp;
	cin>>n>>a>>b;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&h[i],&d[i]);
		ans+=d[i];
		pq.push(mp(h[i]-d[i],i));
	}
	if(!b)
	{
		cout<<ans;
		return 0;
	}
	for(i=1;i<b&&!pq.empty()&&pq.top().fi>0;i++)
	{
		ans+=pq.top().fi;
		in[pq.top().se]=1;
		pq.pop();
	}
	if(!pq.empty()&&pq.top().fi>0)
		k=pq.top().fi;
	for(i=1;i<=n;i++)
	{
		tmp=h[i]*(1 << a)-in[i]*(h[i]-d[i])-d[i]+in[i]*k;
		mx=max(mx,tmp);
	}
	cout<<mx+ans;
}