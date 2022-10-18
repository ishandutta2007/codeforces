#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,n,a[N],s[N],A;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		A=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+(!a[i]);
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				A+=j-i+1+s[j]-s[i-1];
		cout<<A<<'\n';
	}
}