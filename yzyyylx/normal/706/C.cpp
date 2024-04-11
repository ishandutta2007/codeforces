#include<bits/stdc++.h>
#define ll long long
#define N 100005
#define M 1000000000000000
using namespace std;

string a[N],b[N];
ll cost[N],n,ans[N][2];

int main()
{
	ll i,j,l,k;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&cost[i]);
	}
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
		reverse(b[i].begin(),b[i].end());
	}
/*	if(a[2]>=a[1]) cout<<1;
	if(b[2]>=a[1]) cout<<2;
	if(a[2]>=b[1]) cout<<3;
	if(b[2]>=b[1]) cout<<4;
*/	for(i=2;i<=n;i++)
	{
		ans[i][0]=ans[i][1]=M;
	}
	ans[1][0]=0;
	ans[1][1]=cost[1];
//	cout<<ans[2][0]<<endl;
	for(i=2;i<=n;i++)
	{
		if(a[i]>=a[i-1])
		{
			ans[i][0]=min(ans[i][0],ans[i-1][0]);
//			cout<<ans[i][0]<<endl;
		}
		if(b[i]>=a[i-1])
		{
			ans[i][1]=min(ans[i][1],ans[i-1][0]+cost[i]);
//			cout<<ans[i][1]<<endl;
		}
		if(a[i]>=b[i-1])
		{
			ans[i][0]=min(ans[i][0],ans[i-1][1]);
//			cout<<ans[i][0]<<endl;
		}
		if(b[i]>=b[i-1])
		{
			ans[i][1]=min(ans[i][1],ans[i-1][1]+cost[i]);
//			cout<<ans[i][1]<<endl;
		}
	}
	k=min(ans[n][0],ans[n][1]);
	if(k==M) cout<<-1;
	else cout<<k;
}