#include<bits/stdc++.h>
#define ll long long
#define N 
using namespace std;

ll n,d,num[2010],ans;

int main()
{
	ll i,j;
	cin>>n>>d;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
	}
	
	for(i=2;i<=n;i++)
	{
		if(num[i]<=num[i-1])
		{
			ans+=(num[i-1]-num[i])/d+1;
			num[i]+=((num[i-1]-num[i])/d+1)*d;
		}
	}
	cout<<ans;
	return 0;
}