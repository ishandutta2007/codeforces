#include<bits/stdc++.h>
using namespace std; 
int t,v;
string s;
signed main()
{
	cin>>t;
	while(t--&&cin>>s)
	{
		v=0;
		for(int i=0;i<s.size();i++)
			v+=(s[i]%2==0);
		if(s[s.size()-1]%2==0)
			cout<<0<<'\n';
		else if(s[0]%2==0)
			cout<<1<<'\n';
		else if(v)
			cout<<2<<'\n';
		else
			cout<<-1<<'\n';
	}
}