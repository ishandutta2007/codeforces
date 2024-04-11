#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1;
int T,A,n,a[N];
string s,t;
signed main()
{
	cin>>T;
	while(T--&&cin>>n>>s>>t)
	{
		A=0;
		for(int i=0;i<n;i++)
			a[i]=s[i]-'0'+t[i]-'0';
		for(int i=0;i<n;i++)
			if(a[i]==1)
				A+=2;
			else if(a[i]==0)
				A++;
		for(int i=0;i<n-1;i++)
			if(a[i]*a[i+1]==0&&a[i]+a[i+1]==2)
				A++,i++;
		cout<<A<<'\n';
	}
	return 0;
}