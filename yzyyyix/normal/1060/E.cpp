#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<int,int>
#define mp make_pair
#define fi fisrt
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 200100
#define M 
using namespace std;

ll m,n,dp[N][2],ans,deep[N];
vector<ll>son[N];

void dfs(ll now,ll last)
{
	ll i,j,t,cnt=0,res=1,tmp;
	dp[now][0]=1;
	for(i=0;i<son[now].size();i++)
	{
		t=son[now][i];
		if(t==last) continue;
		dfs(t,now);
		dp[now][0]+=dp[t][1];
		dp[now][1]+=dp[t][0];
	}
}

ll Dfs(ll now,ll last)
{
	ll i,j,t,res=1,tmp,cnt=0;
	for(i=0;i<son[now].size();i++)
	{
		t=son[now][i];
		if(t==last) continue;
		deep[t]=deep[now]+1;
		tmp=Dfs(t,now);
		cnt+=res*tmp;
		res+=tmp;
	}
	ans+=deep[now]*(n-1-cnt*2);
	return res;
}

int main()
{
	ll i,j,p,q;
	cin>>n;
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&p,&q);
		son[p].push_back(q);
		son[q].push_back(p);
	}
	deep[1]=1;
	Dfs(1,-1);
	dfs(1,-1);
	cout<<(ans+dp[1][0]*dp[1][1])/2;
}