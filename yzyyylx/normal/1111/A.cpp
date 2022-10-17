#include<bits/stdc++.h>
using namespace std;

string s,t;

inline bool yy(char u)
{
	return u=='a' || u=='e' || u=='i' || u=='o' || u=='u';
}

int main()
{
	int i,j;
	cin>>s>>t;
	if(s.size()!=t.size())
	{
		puts("No");
		return 0;
	}
	for(i=0;i<s.size();i++)
	{
		if(yy(s[i])==yy(t[i])) continue;
		puts("No");
		return 0;
	}
	puts("Yes");
}