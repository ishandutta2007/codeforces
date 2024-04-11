#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 100100
#define M 
using namespace std;

ll n,L,a,num[N],len[N],ans;

int main()
{
	ll i,j;
	cin>>n>>L>>a;
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&num[i],&len[i]);
	}
	num[n+1]=L;
	for(i=0;i<=n;i++)
	{
		ans+=max(0ll,(num[i+1]-num[i]-len[i])/a);
	}
	cout<<ans;
}