#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,a[N],A;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1),A=0;
		for(int i=1;i<=(n+1)/2;i++)
			A-=a[i];
		for(int i=n/2+2;i<=n;i++)
			A+=a[i];
		A>0?puts("YES"):puts("NO");
	}
}