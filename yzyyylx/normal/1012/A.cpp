#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define N 200100
using namespace std;

ll n,num[N],ans=5e18;

int main()
{
	ll i,j;
	cin>>n;
	for(i=1;i<=2*n;i++)
	{
		scanf("%lld",&num[i]);
	}
	sort(num+1,num+n*2+1);
	for(i=1;i<=n+1;i++)
	{
		ans=min(ans,(num[2*n]-num[1])*(num[i+n-1]-num[i]));
	}
	cout<<min(ans,(num[n]-num[1])*(num[2*n]-num[n+1]));
}