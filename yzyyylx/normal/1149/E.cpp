#include<bits/stdc++.h>
#define ll long long
#define N 200100
using namespace std;

ll n,m,num[N],sy[N],ds[N],bj[N],sum[N];
vector<ll>to[N],pre[N];
queue<ll>que;

int main()
{
    ll i,j,t,p,q;
    cin>>n>>m;
    for(i=1;i<=n;i++) scanf("%lld",&num[i]);
    for(i=1;i<=m;i++)
    {
	scanf("%lld%lld",&p,&q);
	pre[q].push_back(p);
	to[p].push_back(q);
	ds[p]++;
    }
    for(i=1;i<=n;i++) if(!ds[i]) que.push(i);
    for(;!que.empty();)
    {
	q=que.front();
	que.pop();
	for(i=0;i<pre[q].size();i++)
	{
	    t=pre[q][i];
	    ds[t]--;
	    if(!ds[t]) que.push(t);
	}
	for(i=0;i<to[q].size();i++)
	{
	    t=to[q][i];
	    bj[sy[t]]=q;
	}
	for(i=0;bj[i]==q;i++);
	sy[q]=i;
	sum[sy[q]]^=num[q];
    }
    for(i=n;i>=0;i--)
    {
	if(!sum[i]) continue;
	puts("WIN");
	for(j=1;j<=n;j++) if(sy[j]==i&&(num[j]^sum[i])<num[j]) break;
	q=j,num[q]^=sum[i];
//	cout<<" "<<q<<" "<<sum[i]<<endl;
	for(j=0;j<to[q].size();j++)
	{
	    t=to[q][j];
	    if(sum[sy[t]]&&bj[sy[t]]!=-1)
	    {
		bj[sy[t]]=-1;
		num[t]^=sum[sy[t]];
	    }
	}
	for(i=1;i<=n;i++) printf("%lld ",num[i]);
	return 0;
    }
    puts("LOSE");
}