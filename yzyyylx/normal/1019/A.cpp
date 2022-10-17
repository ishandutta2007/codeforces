#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define N 3010
using namespace std;

ll n,m,ans=INF,need[N],cnt;
struct Peo
{
	ll u,v,w;
	bool operator < (const Peo &u) const
	{
		return w<u.w;
	}
}peo[N];
vector<ll>num[N],qz[N];

inline ll calc(ll u)
{
	ll i,j,res=0,t=num[1].size();
	for(i=2;i<=m;i++)
	{
		if(num[i].size()>=u)
		{
			t+=need[i]=num[i].size()-u+1;
			res+=qz[i][need[i]-1];
		}
		else need[i]=0;
	}
	for(i=1;i<=cnt&&t<u;i++)
	{
		if(peo[i].v<need[peo[i].u]) continue;
		res+=peo[i].w;
		t++;
	}
	return res;
}

int main()
{
	ll i,j,p,q;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&p,&q);
		num[p].push_back(q);
	}
	for(i=2;i<=m;i++)
	{
		if(!num[i].size()) continue;
		sort(num[i].begin(),num[i].end());
		qz[i].push_back(num[i][0]);
		for(j=1;j<num[i].size();j++)
		{
			qz[i].push_back(qz[i][j-1]+num[i][j]);
		}
		for(j=0;j<num[i].size();j++)
		{
			peo[++cnt].u=i;
			peo[cnt].v=j;
			peo[cnt].w=num[i][j];
		}
	}
//	for(i=1;i<=cnt;i++) cout<<peo[i].w<<endl;
	/*
	for(i=1;i<=m;i++)
	{
		for(j=0;j<num[i].size();j++)
		{
			cout<<num[i][j]<<" ";
		}
		puts("");
	}
	puts("");
	for(i=1;i<=m;i++)
	{
		for(j=0;j<num[i].size();j++)
		{
			cout<<qz[i][j]<<" ";
		}
		puts("");
	}
	return 0;
	//*/
	sort(peo+1,peo+cnt+1);
	for(i=1;i<=(n+1)/2;i++)
	{
//		cout<<calc(i)<<endl;
		ans=min(ans,calc(i));
	}
	cout<<ans;
}