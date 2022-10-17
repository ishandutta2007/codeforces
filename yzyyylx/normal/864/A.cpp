#include<bits/stdc++.h>
#define ll long long
#define N 110
using namespace std;

ll n,m,a,sum,dp[N],k,x,y;

int main()
{
	ll i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		dp[a]++;
	}
	for(i=1;i<=100;i++)
	{
		if(dp[i]!=0)
		{
			sum++;
			if(x==0) x=i;
			else y=i;
		} 
	}
	if(sum==2&&dp[x]==dp[y])
	{
		cout<<"YES";
		cout<<endl<<x<<" "<<y;
	}
	else cout<<"NO";
}