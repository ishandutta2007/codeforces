#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 300100
#define M 
using namespace std;

ll n,ans,num[N];

int main()
{
	ll i,j,k,p,q,t,now;
	cin>>n;
	for(i=1;i<=n;i++) scanf("%lld",&num[i]);
	now=0;
	for(i=1;i<=n;i++)
	{
		t=min(num[i]/2,now);
		num[i]-=2*t;
		now-=t;
		ans+=t;
		ans+=num[i]/3;
		now+=num[i]%3;
	}
	cout<<ans;
}