#include<bits/stdc++.h>
#define ll long long
#define N 400000
using namespace std;

ll n,ans;

int main()
{
	ll i,j,x,y,t;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&t);
		ans+=t;
	}
	cout<<ans;
}