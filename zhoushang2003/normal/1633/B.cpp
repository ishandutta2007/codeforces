#include<bits/stdc++.h>
using namespace std;
int t,x,y;
string s;
int main()
{
	cin>>t;
	while(t--&&cin>>s)
	{
		for(int i=0;i<s.size();i++)
			s[i]=='0'?x++:y++;
		cout<<(x==y?x-1:min(x,y))<<'\n',x=y=0;
	}
}