#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,x,y,A,n,c;
string s,t;
signed main()
{
	cin>>T;
	while(T--&&cin>>n>>s>>t)
	{
		x=y=0,A=-1;
		for(int i=0;i<s.size();i++)
			x+=(s[i]=='1'),y+=(t[i]=='1');
		if(y==x)
		{
			c=0;
			for(int i=0;i<s.size();i++)
				if(s[i]!=t[i])
					c++;
			A=c;
		}
		if(y==n-x+1)
		{
			c=0;
			for(int i=0;i<s.size();i++)
				if(s[i]==t[i])
					c++;
			if(A==-1)
				A=c;
			A=min(A,c);
		}
		cout<<A<<'\n';
	}
}