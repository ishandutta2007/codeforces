#include<bits/stdc++.h>
#define ll long long
#define N 300100
using namespace std;
 
ll n,m,fa[N],ds[N];
bool bla[N],ans[N];
vector<ll>to[N];
queue<ll>que;
 
ll ff(ll u){return u==fa[u]?u:fa[u]=ff(fa[u]);}
int main()
{
	ll i,j,p,q,t;
	cin>>n;
	for(i=1;i<=n;i++) scanf("%lld",&bla[i]),fa[i]=i;
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&p,&q);
		to[p].push_back(q);
		to[q].push_back(p);
		ds[p]++,ds[q]++;
	}
	for(i=1;i<=n;i++)
	{
		if(bla[i] || ds[i]>1) continue;
		que.push(i);
	}
	for(;!que.empty();)
	{
		ll i,t,now=que.front();
		que.pop();
		for(i=0;i<to[now].size();i++)
		{
			t=to[now][i];
			fa[ff(now)]=ff(t);
			ds[t]--;
			if(ds[t]==1 && !bla[t]) que.push(t);
		}
	}
	for(i=1;i<=n;i++) if(bla[i] && ds[i]>1) break;
	if(i<=n)
	{
		for(i=1;i<=n;i++) printf("1 ");puts("");
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		if(!bla[i]) continue;
		ans[i]=1;
		for(j=0;j<to[i].size();j++)
		{
			ans[to[i][j]]=1;
			if(ds[to[i][j]]>2) break;
		}
		if(j<to[i].size()) break;
	}
	if(i<=n)
	{
		for(i=1;i<=n;i++) printf("1 ");puts("");
		return 0;
	}
	for(i=1;i<=n;i++) printf("%lld ",(ll)ans[ff(i)]);
}