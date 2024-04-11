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

ll n,h,ans,num[N],tmp[N];

inline bool judge(ll u,ll v)
{
	ll i,j,sum=0;
	for(i=u;i<=v;i++)
	{
		tmp[i]=num[i];
	}
	sort(tmp+1,tmp+v+1);
	for(i=v;i>=1;i-=2) sum+=tmp[i];
	return sum<=h;
}

int main()
{
	ll i,j,t;
	cin>>n>>h;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
	}
	for(i=1;i<=n;i++)
	{
		if(!judge(1,i)) break;
	}
	cout<<i-1;
}