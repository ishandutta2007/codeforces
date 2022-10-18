#include<bits/stdc++.h>
using namespace std;
int t;
string s;
int main()
{
	cin>>t;
	while(t--&&cin>>s)
	{
		while(s.find(s[0],1)!=-1)
			s.erase(s.begin());
		cout<<s<<'\n';
	}
}