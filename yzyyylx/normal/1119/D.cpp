#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 100100
#define M 
using namespace std;

ll n,Q,sum,num[N],cf[N],ans[N],cnt;
P que[N];

int main()
{
	ll i,j,p,q,t;
	cin>>n;
	for(i=1;i<=n;i++) scanf("%lld",&num[i]);
	sort(num+1,num+n+1);
	for(i=1;i<n;i++) cf[i]=num[i+1]-num[i];
	sort(cf+1,cf+n);
	cin>>Q;
	for(i=1;i<=Q;i++)
	{
		scanf("%lld%lld",&p,&q);
		que[i]=mp(q-p+1,i);
	}
	sort(que+1,que+Q+1);
	cnt=n-1;
	for(i=j=1;i<=Q;i++)
	{
		for(;j<n&&que[i].fi>=cf[j];j++) sum+=cf[j],cnt--;
		ans[que[i].se]=sum+que[i].fi*(cnt+1);
	}
	for(i=1;i<=Q;i++) printf("%lld ",ans[i]);
}