#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define N 200100
#define M
using namespace std;

ll T,n,m,ans[N],A[N],B[N],C[N],fa[N];
bool gg,vis[N];
vector<P>to[N];

inline ll calc(ll u){ll i,res=0;for(i=0;i<=30;i++) if((1 << i)&u) res++;return res;}
void dfs(ll now)
{
	vis[now]=1;
	ll i,t;
	for(i=0;i<to[now].size();i++)
	{
		t=to[now][i].fi;
		if(!vis[t])
		{
			ans[t]=ans[now];
			if(to[now][i].se) ans[t]^=1;
			dfs(t);
		}
		else
		{
			if(to[now][i].se && ans[now]==ans[t]) gg=1;
			else if(!to[now][i].se && (ans[now]^ans[t])) gg=1;
		}
	}
}

int main()
{
	ll i,j,t,p,q;
	cin>>T;
	while(T--)
	{
		gg=0;
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++) to[i].clear(),vis[i]=0;
		for(i=1;i<n;i++)
		{
//			cout<<" "<<i<<endl;
			scanf("%lld%lld%lld",&A[i],&B[i],&C[i]);
			if(C[i]==-1) continue;
//			cout<<" "<<i<<" "<<calc(C[i])<<endl;
			p=A[i],q=B[i];
			if(calc(C[i])&1)
			{
				to[p].push_back(mp(q,1ll));
				to[q].push_back(mp(p,1ll));
			}
			else
			{
				to[p].push_back(mp(q,0ll));
				to[q].push_back(mp(p,0ll));
			}
		}
		for(i=1;i<=m;i++)
		{
			scanf("%lld%lld%lld",&p,&q,&t);
			to[p].push_back(mp(q,t));
			to[q].push_back(mp(p,t));
		}
		for(i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			dfs(i);
		}
		if(gg) puts("NO");
		else
		{
			puts("YES");
			for(i=1;i<n;i++)
			{
				printf("%lld %lld ",A[i],B[i]);
				if(C[i]!=-1) printf("%lld\n",C[i]);
				else printf("%lld\n",ans[A[i]]==ans[B[i]]?0:1);
			}
		}
	}
}