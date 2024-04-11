#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a[999999],s,c,A;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=2;i<n;i++)
			s+=a[i],c+=(a[i]>0),A+=(a[i]+1)/2;
		cout<<(s==c||c==1&&s&1?-1:A)<<'\n',s=c=A=0;
	}
}