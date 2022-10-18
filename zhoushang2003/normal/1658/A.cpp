#include<bits/stdc++.h>
using namespace std;
int t,n,A;
string s;
int main()
{
	cin>>t;
	while(t--&&cin>>n>>s)
	{
		s=' '+s,A=0;
		for(int i=2;i<=n;i++)
			if(s[i]=='0'&&s[i-1]=='0')
				A+=2;
			else if(s[i]=='0'&&s[i-2]=='0')
				A++;
		cout<<A<<'\n';
	}
}