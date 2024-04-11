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
			cin>>x,p[i]={x,i};
		sort(p+1,p+n+1);
		cout<<p[1].second<<' '<<p[n].second<<'\n';
	}
}