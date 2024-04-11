#include<bits/stdc++.h>
using namespace std;
string s,t;
int main()
{
	cin>>s>>t;
	for(int i=0;i<s.size();i++)
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
			s[i]='a';
		else
			s[i]='b';
	for(int i=0;i<t.size();i++)
		if(t[i]=='a'||t[i]=='e'||t[i]=='i'||t[i]=='o'||t[i]=='u')
			t[i]='a';
		else
			t[i]='b';
	if(s==t)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}