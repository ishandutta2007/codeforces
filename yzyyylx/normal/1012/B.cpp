#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define N 400100
using namespace std;

ll m,n,num[N],ans,fa[N];
bool vis[N];

ll ff(ll u){return u==fa[u]?u:fa[u]=ff(fa[u]);}

int main()
{
	ll i,j,t,p,q;
	cin>>m>>n>>t;
	for(i=1;i<=m+n;i++) fa[i]=i;
	for(i=1;i<=t;i++)
	{
		scanf("%lld%lld",&p,&q);
		fa[ff(p)]=fa[ff(q+m)];
	}
	for(i=1;i<=m+n;i++)
	{
		if(!vis[ff(i)])
		{
			ans++;
			vis[ff(i)]=1;
		}
	}
	cout<<ans-1;
}