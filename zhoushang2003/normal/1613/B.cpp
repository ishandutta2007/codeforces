#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6; 
int t,n,x;
pair<int,int>p[N];
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>p[i].first,p[i].second=i;
		sort(p+1,p+n+1),x=1;
		for(int i=2;i<n/2+2;i++)
			cout<<p[i].first<<' '<<p[1].first<<'\n';
	}
}