#include <bits/stdc++.h>

using namespace std;

string conv(string s)
{
	string res;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='u') res+="oo";
		else if(s[i]=='h')
		{
			while(res.size()&&res.back()=='k') res.pop_back();
			res+=s[i];
		}
		else res+=s[i];
	}
	return res;
}

set<string> ss;
int n;

int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		ss.insert(conv(s));
	}
	printf("%d\n",(int)ss.size());
}