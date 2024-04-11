#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,a[N],x,A;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		x=a[n],A=0;
		for(int i=n;i;i--)
			if(a[i]>x)
				x=a[i],A++;
		cout<<A<<'\n';
	}
}