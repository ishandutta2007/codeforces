#include<bits/stdc++.h>
#define ll long long
#define db double
#define N 100100
using namespace std;

ll n,a,b,num[N];
db sum,ans;

int main()
{
	ll i,j,t;
	cin>>n>>a>>b;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		sum+=num[i];
	}
	sort(num+1,num+n+1);
	for(i=0;i<=min(n-1,b);i++)
	{
		sum-=num[i];
		t=min(b-i,a*(n-i));
		ans=max(ans,(sum+t)/(db)(n-i));
	}
	printf("%.10f",ans);
}