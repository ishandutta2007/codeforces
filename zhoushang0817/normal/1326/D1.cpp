#include<bits/stdc++.h>
using namespace std;
int t,l,r;
string s,A;
bool C(string s)
{
	for(int i=0;i<s.size()/2;i++)
		if(s[i]!=s[s.size()-1-i])
			return false;
	return true;
}
int main()
{
	cin>>t;
	while(t--&&cin>>s)
	{
		if(C(s))
		{
			cout<<s<<'\n';
			continue;
		}
		l=0,r=s.size()-1;
		while(l<r&&s[l]==s[r])
			l++,r--;
		A="";
		for(int i=1;i<=r-l;i++)
			if(C(s.substr(l,i)))
				A=s.substr(l,i);
			else if(C(s.substr(r-i+1,i)))
				A=s.substr(r-i+1,i);
		for(int i=0;i<l;i++)
			cout<<s[i];
		cout<<A;
		for(int i=r+1;i<s.size();i++)
			cout<<s[i];
		cout<<'\n';
	}
	return 0;
}