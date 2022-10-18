#include<bits/stdc++.h>
using namespace std;
const int N=1e4;
int t,n,x,c[N],A,p;
string s[N];
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		p=A=0;
		for(int i=1;i<=n;i++)
			cin>>s[i],s[i]=' '+s[i],c[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				x=s[i][j]-'0',c[(j-i+n)%n+1]+=x,A+=x;
		for(int i=1;i<=n;i++)
			p=max(p,c[i]);
		cout<<A-p+n-p<<'\n';
	}
}