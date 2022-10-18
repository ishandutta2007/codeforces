#include<bits/stdc++.h>
using namespace std;
int n,c,x,y;
string s;
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)
		if(s[i]=='(')
			c++;
	if(n&1||c>n/2)
	{
		cout<<":(";
		return 0;
	}
	for(int i=0;i<n;i++)
		if(s[i]=='?'&&c<n/2)
			s[i]='(',c++;
	for(int i=0;i<n;i++)
		if(s[i]=='?')
			s[i]=')';
	for(int i=0;i<n-1;i++)
	{
		if(s[i]=='(')
			x++;
		else
			y++;
		if(y>=x)
		{
			cout<<":(";
			return 0;
		}
	}
	cout<<s;
	return 0;
}