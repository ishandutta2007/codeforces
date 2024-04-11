#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MN 
#define N 200100
#define M 
using namespace std;

ll T,n,m,num[N],ds[N],ans[N];
vector<ll>to[N];

inline void Max(ll &u,ll v){if(v>u) u=v;}
inline void Min(ll &u,ll v){if(v<u) u=v;}
void dfs(ll now,ll last,ll sum,ll out)
{
//	cout<<now<<" "<<last<<endl;
	ll i,t;
	ans[now]=sum-(to[now].size()-1)*out;
	for(i=0;i<to[now].size();i++)
	{
		t=to[now][i];
		if(t==last) continue;
		dfs(t,now,out,sum);
	}
}

int main()
{
	ll i,j,p,q,t;
	cin>>T;
	while(T--)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++) ds[i]=0,to[i].clear();
		for(i=1;i<n;i++)
		{
			scanf("%lld%lld",&p,&q);
			to[p].push_back(q);
			to[q].push_back(p);
			ds[p]++,ds[q]++;
		}
		for(i=1;i<=n;i++) if(ds[i]==1) break;
		t=to[i][0];
		ans[i]=1,ans[t]=-(ll)to[t].size();
		for(j=0;j<to[t].size();j++)
		{
			if(to[t][j]==i) continue;
			dfs(to[t][j],t,ans[i],-1ll);
		}
		for(i=1;i<=n;i++) printf("%lld ",ans[i]);
		puts("");
	}
}