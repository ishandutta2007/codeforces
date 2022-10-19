#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 300100
#define M 
using namespace std;

ll n,m,sum,num[N];

int main()
{
	ll i,j,p;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		sum+=num[i];
	}
	sort(num+1,num+n+1);
	reverse(num+1,num+n+1);
	cin>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&p);
		printf("%lld\n",sum-num[p]);
	}
}