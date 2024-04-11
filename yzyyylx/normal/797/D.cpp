#include<bits/stdc++.h>
#define ll long long
#define N 200020
#define MX 1000000009
using namespace std;

struct Tree
{
	ll l,r,v;
}tree[N];

ll n,root,cnt;
bool rt[N];
map<ll,ll>mp,vis;

void dfs(ll u,ll p,ll q)
{
	if(u==-1)
		return;
	if(tree[u].v>=p&&tree[u].v<=q)
	{
		if(mp[tree[u].v])
			mp[tree[u].v]=0;
	}
	dfs(tree[u].l,p,min(q,tree[u].v));
	dfs(tree[u].r,max(p,tree[u].v),q);
}

int main()
{
	while(cin>>n)
	{
		ll i,num;
		memset(rt,true,sizeof(rt));
		mp.clear();
		num=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&tree[i].v,&tree[i].l,&tree[i].r);
			if(tree[i].l!=-1)
				rt[tree[i].l]=false;
			if(tree[i].r!=-1)
				rt[tree[i].r]=false;
			mp[tree[i].v]++;
		}
		cnt=0;
		for(i=1;i<=n;i++)
			if(rt[i]!=0)
				root=i;
		dfs(root,-MX,MX);
		for(i=1;i<=n;i++)
		{
			cnt+=mp[tree[i].v];
			mp[tree[i].v]=0;
		}
		cout<<cnt<<endl;
	}
}