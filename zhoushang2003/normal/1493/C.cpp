#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,k,c[130],p,l,r,z;
string s,t;
int C(int x,int y)
{
	for(int i='a';i<='z';i++)
		c[i]=0;
	for(int i=0;i<x;i++)
		c[s[i]]++;
	p=0;
	for(int i='a';i<='z';i++)
		z=(c[i]+k-1)/k*k,p+=z,c[i]=z-c[i];
	if(p>n)
		return 0;
	t="";
	for(int i=0;i<x;i++)
		t+=s[i];
	if(y)
	{
		c['z']+=n-p;
		for(char i='z';i>='a';i--)
			for(int j=1;j<=c[i];j++)
				t+=i;
	}
	else
	{
		c['a']+=n-p;
		for(char i='a';i<='z';i++)
			for(int j=1;j<=c[i];j++)
				t+=i;
	}
	return t>=s;
}
signed main()
{
	cin>>T;
	while(T--&&cin>>n>>k>>s)
	{
		if(n%k!=0)
		{
			cout<<-1<<'\n';
			continue;
		}
		l=0,r=n;
		while(l<r)
			if(C((l+r+1)/2,1))
				l=(l+r+1)/2;
			else
				r=(l+r-1)/2;
		if(l==n)
		{
			cout<<s<<'\n';
			continue;
		}
		for(int i=l+1;i<n;i++)
			s[i]='a';
		for(int i=s[l]+1;i<='z';i++)
		{
			s[l]=i;
			if(C(l+1,0))
				break;
		}
		cout<<t<<'\n';
	}
	return 0;
}