#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,k;

int main()
{
	ll i;
	cin>>n>>k;
	if(n==k||k==0)
	{
		cout<<0<<" "<<0;
		return 0;
	}
	
	cout<<1<<" ";
	if(k<=n/3)
	{
		cout<<k*2;
		return 0;
	}
	else cout<<n-k;
}