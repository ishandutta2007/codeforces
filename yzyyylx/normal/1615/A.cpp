#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define N 100100
#define M
using namespace std;

ll T,n,m,sum,ans,num[N];

int main()
{
	ll i,j,t;
	cin>>T;
	while(T--)
	{
		sum=0;
		scanf("%lld",&n);
		for(i=1; i<=n; i++)
		{
			scanf("%lld",&num[i]);
			sum+=num[i];
		}
		if(sum%n==0) puts("0");
		else puts("1");
	}
}