#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+2;
int x,y,n,a[N],p[N],q[N],c,k,t,A;
string s;
signed main()
{
	cin>>s>>x>>y,n=s.size(),s="0"+s;
	for(int i=1;i<=s.size();i++)
		if(s[i]=='1')
			a[i]=1;
	for(int i=n;i>=1;i--)
		p[i]=p[i+1]+(a[i]==0),q[i]=q[i+1]+(a[i]==1);
	for(int i=1;i<=n;i++)
		if(a[i]==0)
			k+=q[i+1]*x;
		else
			k+=p[i+1]*y;
	A=k,t=k;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
			c++;
		if(s[i]=='?')
			c--,t-=q[i+1]*x+(i-1-c)*y,t+=p[i+1]*y+c*x,A=min(A,t);
	}
	c=0;
	for(int i=1;i<=n;i++)
		p[i]=p[i-1]+(a[i]==0),q[i]=q[i-1]+(a[i]==1);
	for(int i=n;i>=1;i--)
	{
		if(a[i]==1)
			c++;
		if(s[i]=='?')
			k-=q[i-1]*y+c*x,k+=p[i-1]*x+(n-i-c)*y,A=min(A,k),c++;
	}
	cout<<A;
	return 0;
}