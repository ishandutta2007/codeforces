#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 1e13
#define N 100100
#define M 1000100
using namespace std;

ll n,m,k,dp[M][2],ti,ans=INF;
vector<P>to[N],back[N];

inline bool cmp(P u,P v){return u>v;}

int main()
{
	ll i,j,o,p,q,z;
	cin>>n>>m>>k;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld%lld",&o,&p,&q,&z);
		if(p) to[p].push_back(mp(o,z));
		else back[q].push_back(mp(o,z));
		ti=max(ti,o);
	}
	for(i=1;i<=n;i++)
	{
		sort(to[i].begin(),to[i].end());
		sort(back[i].begin(),back[i].end(),cmp);
		if(!to[i].size() || !back[i].size())
		{
			puts("-1");
			return 0;
		}
	}
	for(i=1,o=0;i<=n;i++) o=max(o,to[i][0].fi);
	for(i=o-1;i>=1;i--) dp[i][0]=INF;
	for(i=1;i<=n;i++)
	{
		p=INF;
		for(j=0;j<to[i].size()&&to[i][j].fi<=o;j++) p=min(p,to[i][j].se);
		dp[o][0]+=p;
//		cout<<p<<" ";
		for(;j<to[i].size();j++)
		{
			q=to[i][j].se;
			if(q<p)
			{
				dp[to[i][j].fi][0]-=p-q;
				p=q;
			}
		}
	}
	for(i=o+1;i<=ti;i++) dp[i][0]+=dp[i-1][0];
//	puts("");for(i=o;i<=ti;i++) cout<<i<<":"<<dp[i][0]<<endl;puts("");
	
	for(i=1,o=ti;i<=n;i++) o=min(o,back[i][0].fi);dp[o][1]=0;
	for(i=o+1;i<=ti;i++) dp[i][1]=INF;
	for(i=1;i<=n;i++)
	{
		p=INF;
		for(j=0;j<back[i].size()&&back[i][j].fi>=o;j++) p=min(p,back[i][j].se);
		dp[o][1]+=p;
//		cout<<" "<<p<<endl;
		for(;j<back[i].size();j++)
		{
			q=back[i][j].se;
			if(q<p)
			{
				dp[back[i][j].fi][1]-=p-q;
				p=q;
			}
		}
	}
	for(i=o-1;i>=1;i--) dp[i][1]+=dp[i+1][1];
//	for(i=o;i>=1;i--) cout<<i<<":"<<dp[i][1]<<endl;
	
	for(i=1;i+k+1<=ti;i++) ans=min(ans,dp[i][0]+dp[i+k+1][1]);
//	cout<<ans<<' ';
	if(ans>=INF) puts("-1");
	else cout<<ans;
}