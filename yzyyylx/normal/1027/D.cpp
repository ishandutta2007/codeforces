#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 400100
using namespace std;

ll T,n,m,c[N],to[N],id[N],num[N],ans,fa[N];
bool vis[N];

ll ff(ll u)
{
	return u==fa[u]?u:fa[u]=ff(fa[u]);
}

int main()
{
	ll i,j,p,q,t;
	cin>>n;
	for(i=1; i<=n; i++)
	{
		scanf("%lld",&c[i]);
		fa[i]=i;
	}
	for(i=1; i<=n; i++)
	{
		scanf("%lld",&to[i]);
		fa[ff(i)]=ff(to[i]);
	}
	for(j=1; j<=n; j++)
	{
		if(vis[ff(j)]) continue;
		vis[ff(j)]=1;
		t=N;
		for(p=j,i=1; !id[p]; p=to[p],i++)
		{
			id[p]=i;
			num[i]=p;
		}
		for(i--; i>=id[p]; i--)
		{
			t=min(t,c[num[i]]);
		}
		ans+=t;
	}
	cout<<ans;
}