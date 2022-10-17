#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 100100
#define M 
using namespace std;
 
ll T,n,m,ans[N],ds[N];
vector<P>to[N];
 
void dfs(ll now,ll last,bool gg)
{
	ll i,t;
	for(i=0;i<to[now].size();i++)
	{
		t=to[now][i].fi;
		if(t==last) continue;
		ans[to[now][i].se]=(gg?2ll:3ll);
		dfs(t,now,gg^1);
	}
}
 
int main()
{
	ll i,j,a,b,p,q;
	cin>>T;
	while(T--)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++) ds[i]=0,to[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%lld%lld",&p,&q);
			to[p].push_back(mp(q,i));
			to[q].push_back(mp(p,i));
			ds[p]++,ds[q]++;
		}
		for(i=1;i<=n;i++) if(ds[i]>=3) break;
		if(i<=n)
		{
			puts("-1");
			continue;
		}
		for(i=1;i<=n;i++) if(ds[i]==1) break;
		dfs(i,-1,0);
		for(i=1;i<n;i++) printf("%lld ",ans[i]);
		puts("");
	}
}