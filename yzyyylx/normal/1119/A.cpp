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
	ll i,j,t;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
	}
	for(i=n-1;i>=1;i--) if(num[i]!=num[i+1]) break;t=i;
	for(i=1;i<=n;i++)
	{
		if(num[i]!=num[t]) break;
	}
	ans=max(ans,t-i);
	for(i=1;i<=n;i++)
	{
		if(num[i]==num[n]) continue;
		ans=max(ans,n-i);
	}
	cout<<ans;
}