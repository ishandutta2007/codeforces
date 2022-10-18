#import<bits/stdc++.h>
using namespace std;
int x,v;
string s;
main()
{
	for(cin>>s;cin>>s;)
	{
		v=0;
		for(int i=s.size()-1;i;i--)
			if((x=s[i]-'0'+s[i-1]-'0')>9)
				cout<<s.substr(0,i-1)<<x<<s.substr(i+1,s.size()-1-i)<<'\n',i=1,v=1;
		if(!v)
			cout<<s[0]-'0'+s[1]-'0'<<s.substr(2,s.size()-2)<<'\n';
	}
}