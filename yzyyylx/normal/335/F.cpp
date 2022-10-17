#include<bits/stdc++.h>
#define ll long long
#define N 500100
using namespace std;

ll n,sum,bb,top,ans,num[N],cnt[N],b[N],sta[N];
priority_queue<ll,vector<ll>,greater<ll> >pq;

inline bool cmp(ll u,ll v){return u>v;}
int main()
{
    ll i,j,t,mx;
    cin>>n;
    for(i=1;i<=n;i++) scanf("%lld",&num[i]),ans+=num[i];
    sort(num+1,num+n+1,cmp);
    for(i=1;i<=n;i++)
    {
	if(i==1 || num[i]!=num[i-1]) b[++bb]=num[i];
	cnt[bb]++;
    }
    for(i=1;i<=bb;i++)
    {
	top=0;
	mx=min(sum-(ll)pq.size()*2,cnt[i]);
	for(j=1;j<=mx;j++) sta[++top]=b[i];
	mx=min(sum,cnt[i])-mx;
	for(j=1;j<=mx;j+=2)
	{
	    t=pq.top();pq.pop();
	    if(t<b[i])
	    {
		sta[++top]=b[i];
		if(j<mx) sta[++top]=b[i];
	    }
	    else
	    {
		sta[++top]=t;
		if(j<mx && 2*b[i]>t) sta[++top]=2*b[i]-t;
	    }
	}
	for(j=1;j<=top;j++) pq.push(sta[j]);
	sum+=cnt[i];
    }
    for(;!pq.empty();pq.pop()) ans-=pq.top();
    cout<<ans;
}