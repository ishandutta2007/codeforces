#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int t,n,c[N],a[N],A,s,x,p;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			c[i]=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		c[a[1]]++,c[a[n]]++,A=s=0,x=2,p=1;
		for(int i=1;i<n;i++)
			if(a[i]==a[i+1])
				c[a[i]]+=2,x+=2,A++;
		for(int i=1;i<=n;i++)
			if(c[i]>c[p])
				p=i;
		if(c[p]<=x/2+1)
		{
			cout<<A<<'\n';
			continue;
		}
		for(int i=1;i<n;i++)
			if(a[i]!=p&&a[i+1]!=p&&a[i]!=a[i+1])
				s++;
		if(c[p]-x/2-1>s)
			cout<<-1<<'\n';
		else
			cout<<c[p]-x/2-1+A<<'\n';
	}
	return 0;
}