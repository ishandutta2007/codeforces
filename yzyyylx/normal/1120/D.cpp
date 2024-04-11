#include<bits/stdc++.h>
#define ll long long
#define N 200100
using namespace std;

ll n,num[N],dp[N][2],S[N],R[N],cnt[N];
bool vis[N][2];
vector<ll>to[N];
set<ll>ans;
set<ll>::iterator it;

void dfs(ll now,ll last)
{
    ll i,t,sum,res;
    sum=0;
    for(i=0;i<to[now].size();i++)
    {
	t=to[now][i];
	if(t==last) continue;
	dfs(t,now);
	sum+=dp[t][0];
    }
    res=sum;
    for(i=0;i<to[now].size();i++)
    {
	t=to[now][i];
	if(t==last) continue;
	if(sum-dp[t][0]+dp[t][1]<res) res=sum-dp[t][0]+dp[t][1],cnt[now]=1;
	else if(sum-dp[t][0]+dp[t][1]==res) cnt[now]++;
    }
    S[now]=sum,R[now]=res;
    if(to[now].size()>1 || now==1)
    {
	dp[now][1]=res;
	if(sum<res+num[now]) dp[now][0]=sum;
	else dp[now][0]=res+num[now];
    }
    else
    {
	dp[now][1]=0;
	dp[now][0]=num[now];
    }
//    cout<<" "<<now<<" "<<use[now]<<endl;
}

void out(ll now,ll last,bool all)
{
//    cerr<<" "<<now<<" "<<all<<endl;
    ll i,t;
    if(vis[now][all]) return;
    vis[now][all]=1;
    if(to[now].size()==1 && now!=1)
    {
	if(all) ans.insert(now);
	return;
    }
    if(all&&R[now]+num[now]<=S[now]) ans.insert(now);
    for(i=0;i<to[now].size();i++)
    {
	t=to[now][i];
	if(t==last) continue;
	if(all&&R[now]+num[now]<=S[now] || !all)
	{
	    if(S[now]-dp[t][0]+dp[t][1]==R[now])
	    {
		out(t,now,0);
		if(cnt[now]>1 || all&&R[now]+num[now]==S[now]) out(t,now,1);
	    }
	    else out(t,now,1);
	}
	else out(t,now,1);
    }
}

int main()
{
    ll i,j,p,q;
    cin>>n;
    for(i=1;i<=n;i++) scanf("%lld",&num[i]);
    for(i=1;i<n;i++)
    {
	scanf("%lld%lld",&p,&q);
	to[p].push_back(q);
	to[q].push_back(p);
    }
    dfs(1,-1);
    out(1,-1,1);
    cout<<dp[1][0]<<" "<<ans.size()<<endl;
    for(it=ans.begin();it!=ans.end();it++) printf("%lld ",*it);
}