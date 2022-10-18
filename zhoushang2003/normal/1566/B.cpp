#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,c,A;
string s;
signed main()
{
	cin>>t;
	while(t--&&cin>>s)
	{
		c=A=0;
		for(int i=0;i<s.size();i++)
			if(s[i]=='1')
				c++;
		if(c==s.size())
		{
			cout<<0<<'\n';
			continue;
		}
		if(s[0]=='0')
			A++;
		for(int i=1;i<s.size();i++)
			if(s[i]=='0'&&s[i-1]!='0')
				A++;
		cout<<min(A,2ll)<<'\n';
	}
	return 0;
}