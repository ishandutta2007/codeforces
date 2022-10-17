#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define LG 18
#define N 100100
#define M 
using namespace std;

ll n,num[N],L,S,ans,sum[N][20],fa[N][20],deep[N],up[N];
vector<ll>son[N];

void dfs(ll now,ll last)
{
	ll i,j,t;
	for(i=0;i<son[now].size();i++)
	{
		t=son[now][i];
		if(t==last) continue;
		deep[t]=deep[now]+1;
		fa[t][0]=now;
		sum[t][0]=num[now];
		dfs(t,now);
	}
}

void Dfs(ll now,ll last)
{
	ll i,j,t,sy;
	up[now]=N;
	for(i=0;i<son[now].size();i++)
	{
		t=son[now][i];
		if(t==last) continue;
		Dfs(t,now);
		up[now]=min(up[now],up[t]);
	}
	if(up[now]>deep[now])
	{
		ans++;
		sy=S-num[now];
		for(i=LG,t=now;i>=0;i--)
		{
			if(!fa[t][i]) continue;
			if(sum[t][i]<=sy)
			{
				sy-=sum[t][i];
				t=fa[t][i];
			}
		}
		up[now]=max(deep[t],deep[now]-L+1);
	}
}

int main()
{
	ll i,j,p,q;
	cin>>n>>L>>S;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		if(num[i]>S)
		{
			puts("-1");
			return 0;
		}
	}
	for(i=2;i<=n;i++)
	{
		scanf("%lld",&p);
		son[i].push_back(p);
		son[p].push_back(i);
	}
	deep[1]=1;
	dfs(1,-1);
	for(i=1;i<=LG;i++)
	{
		for(j=1;j<=n;j++)
		{
			fa[j][i]=fa[fa[j][i-1]][i-1];
			sum[j][i]=sum[j][i-1]+sum[fa[j][i-1]][i-1];
		}
	}
	Dfs(1,-1);
	cout<<ans;
}