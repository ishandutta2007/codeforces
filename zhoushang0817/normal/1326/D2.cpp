#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+2,P=19260817,D=1e9+7;
long long T,l,r,t,f[N],g[N],x,y,d;
string s,A;
long long Q(long long a,long long b)
{
	t=1;
	while(b)
	{
		if(b&1)
			(t*=a)%=D;
		(a*=a)%=D,b/=2;
	}
	return t;
}
bool C(int l,int r)
{
	if(l==r)
		return true;
	d=l+(r-l+1)/2-1;
	if(l==0)
		x=f[d];
	else
		x=((f[d]-Q(P,d-l+1)*f[l-1])%D+D)%D;
	d=r-(r-l+1)/2+1;
	y=((g[d]-Q(P,r-d+1)*g[r+1])%D+D)%D;
	return x==y;
}
int main()
{
	cin>>T;
	while(T--&&cin>>s)
	{
		f[0]=s[0];
		for(int i=1;i<s.size();i++)
			f[i]=(P*f[i-1]+s[i])%D;
		g[s.size()]=0;
		for(int i=s.size()-1;i>=0;i--)
			g[i]=(P*g[i+1]+s[i])%D;
		if(C(0,s.size()-1))
		{
			cout<<s<<'\n';
			continue;
		}
		l=0,r=s.size()-1;
		while(l<r&&s[l]==s[r])
			l++,r--;
		A="";
		for(int i=r-l;i>=1;i--)
			if(C(l,l+i-1))
				A=s.substr(l,i),i=1;
			else if(C(r-i+1,r))
				A=s.substr(r-i+1,i),i=1;
		for(int i=0;i<l;i++)
			cout<<s[i];
		cout<<A;
		for(int i=r+1;i<s.size();i++)
			cout<<s[i];
		cout<<'\n';
	}
	return 0;
}