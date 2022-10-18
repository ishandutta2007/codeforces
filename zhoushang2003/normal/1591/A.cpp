#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6,I=1e9;
int t,n,a[N],A;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		A=a[1]+1;
		for(int i=2;i<=n;i++)
			if(!a[i]&&!a[i-1])
				A=-I;
			else if(a[i]&&!a[i-1])
				A++;
			else if(a[i]&&a[i-1])
				A+=5;
		if(A<0)
			cout<<"-1\n";
		else
			cout<<A<<'\n';
	}
}