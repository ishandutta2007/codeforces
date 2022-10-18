#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,k,a[N],s,A;
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>k)
	{
		for(int i=1;i<=k;i++)
			cin>>a[i],a[i]=n-a[i];
		sort(a+1,a+k+1),s=A=0;
		for(int i=1;i<=k;i++)
			if(s+a[i]<n)
				s+=a[i],A++;
		cout<<A<<'\n';
	}
	return 0;
}