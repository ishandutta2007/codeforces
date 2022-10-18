#import<bits/stdc++.h>
using namespace std;
int p[999],A;
string s,t;
main()
{
	for(cin>>s;cin>>s>>t;)
	{
		for(int i=0;i<s.size();i++)
			p[s[i]]=i;
		for(int i=1;i<t.size();i++)
			A+=abs(p[t[i]]-p[t[i-1]]);
		cout<<A<<'\n',A=0;
	}
}