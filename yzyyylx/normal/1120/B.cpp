#include<bits/stdc++.h>
#define ll long long
#define N 100100
using namespace std;

ll n,ans,cnt,a[N],b[N],num[N];

void dfs(ll now,ll u)
{
    num[now]+=u,num[now+1]+=u;
    if(num[now+1]>9) dfs(now+1,9-num[now+1]);
    if(num[now+1]<0) dfs(now+1,-num[now+1]);
    ll i;
    for(i=1;i<=abs(u);i++)
    {
	printf("%lld %lld\n",now,u/abs(u));
	cnt++;
	if(cnt==100000) exit(0);
    }
}

int main()
{
    ll i,j,t;
    cin>>n;
    for(i=1;i<=n;i++) scanf("%1lld",&a[i]),num[i]=a[i];
    for(i=1;i<=n;i++) scanf("%1lld",&b[i]);
    for(i=1;i<n;i++)
    {
	t=b[i]-a[i];
	a[i]+=t,a[i+1]+=t;
	ans+=abs(t);
    }
    if(a[n]!=b[n])
    {
	puts("-1");
	return 0;
    }
    cout<<ans<<endl;
    for(i=1;i<n;i++)
    {
	dfs(i,b[i]-num[i]);
    }
}