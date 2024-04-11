#import<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6;
int n,m,s,a[N];
main()
{
	for(cin>>n;cin>>n>>m;)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1),s=0;
		for(int i=1;i<n;i++)
			s+=max(a[i],a[i+1]);
		puts(s+max(a[1],a[n])+n>m?"NO":"YES");
	}
}