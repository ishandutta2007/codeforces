#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+1;
pair<int,int>p[N];
int n,A,B;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second,A+=p[i].second,p[i].second+=p[i].first;
	sort(p+1,p+n+1),B=p[1].first;
	for(int i=1;i<=n;i++)
		A+=max(0ll,p[i].first-B),B=max(B,p[i].second);
	cout<<A;
	return 0;
}