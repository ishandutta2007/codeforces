#include<bits/stdc++.h>
using namespace std;

string s;

bool ispalindrome(const string &s)
{
	for(int i=0;i<s.size();i++)
		if(s[i]!=s[s.size()-i-1])
			return 0;
	return 1;
}

int T;

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>s;
		if(!ispalindrome(s+'a'))
			cout<<"YES"<<endl<<s+'a'<<endl;
		else if(!ispalindrome('a'+s))
			cout<<"YES"<<endl<<'a'+s<<endl;
		else
			cout<<"NO"<<endl;
	}
}