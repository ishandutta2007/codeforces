#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,x,y;
string s,t;
signed main()
{
	cin>>T;
	while(T--&&cin>>s>>t)
	{
		x=y=0;
		if(s.size()%2!=t.size()%2)
			x=1;
		while(x<s.size()&&y<t.size())
			if(s[x]==t[y])
				x++,y++;
			else
				x+=2;
		if(x<=s.size()&&y==t.size())
			cout<<"YES"<<'\n';
		else
			cout<<"NO"<<'\n';
	}
	return 0;
}