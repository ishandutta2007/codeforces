#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,k,a[N],A;
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>k)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1),A=0;
		for(int i=1;i<=n;i+=k)
			if(a[i]<0)
				A-=a[i];
		for(int i=n;i>0;i-=k)
			if(a[i]>0)
				A+=a[i];
		cout<<A*2-max(abs(a[1]),abs(a[n]))<<'\n';
	}
	return 0;
}