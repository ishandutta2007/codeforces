#include<bits/stdc++.h>
using namespace std;
int t,x,y,v;
string s;
int main()
{
	cin>>t;
	while(t--&&cin>>s)
	{
		x=0,y=0,v=false;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='0')
				x++;
			if((s[i]-'0')%2==0)
				v++;
			y+=s[i]-'0';
		}
		if(!x)
		{
			cout<<"cyan"<<'\n';
			continue;
		}
		if(x==s.size()||(y%3==0&&v>1))
		{
			cout<<"red"<<'\n';
			continue;
		}
		cout<<"cyan"<<'\n';
	}
	return 0;
}