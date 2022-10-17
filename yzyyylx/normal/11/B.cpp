#include<bits/stdc++.h>
#define ll long long
#define N 
using namespace std;

ll n,d,ans;

int main()
{
	ll i,j;
	cin>>n;
	if(n<0) n=-n;
	for(i=1;;i++)
	{
		if(i<=n)
		{
			n-=i;
			ans++;
		}
		else break;
	}
	if(n==0)
	{
		cout<<ans;
		return 0;
	}
	ans++;
	d=i-n;
	if(d%2==0)
	{
		cout<<ans;
		return 0;
	}
	else if((i+1)%2==1)
	{
		cout<<ans+1;

		return 0;
	}
	else cout<<ans+2;
	return 0;
	
}