#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll inf=1e10;
const int N=2e6+20;
ll n,a[N],vis[N],can[N]; 
vector<int> e[N];
void solve()
{
	ll C1=0,C2=0,mx=-inf,u;
	for(int i=1;i<=n;i++)
		mx=max(a[i],mx);
	for(int i=1;i<=n;i++)
	{
		if(a[i]==mx)
			C1++,u=i;
		else if(a[i]==mx-1)
			C2++; 
	}
	ll ans=inf;
	if(C1==1)//
	{
		int cnt=0;
		for(int i=0;i<e[u].size();i++)
		{
			int v=e[u][i];
			if(a[v]==mx-1)
				cnt++;
		}
		if(cnt==C2)
			ans=mx;
	}
	if(ans==inf)
	{
		for(int i=1;i<=n&&ans==inf;i++)
		{
			ll res=0;
			if(a[i]==mx)
				res++;
			for(int j=0;j<e[i].size();j++)
			{
				int v=e[i][j];
				if(a[v]==mx)
					res++;
			}
			if(res==C1)
				ans=mx+1;
		}
	}
	if(ans==inf)
		ans=mx+2;
	cout<<ans<<endl;
}
int main()
{
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
			scanf("%I64d",&a[i]),e[i].clear();
		int u,v;
		for(int i=1;i<=n-1;i++)
		{
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		solve();
	}
	return 0;
}