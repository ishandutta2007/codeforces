#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
int n,m;ll a[N],b[N],cnt[N];ll sum[N];
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	ll pos;	
	for(int i=1;i<=m;i++)
	{
		pos=lower_bound(sum+1,sum+n+1,b[i])-sum;
		cout<<pos<<" "<<b[i]-sum[pos-1]<<endl;
	}	
}