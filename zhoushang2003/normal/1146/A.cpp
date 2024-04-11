#include<bits/stdc++.h>
using namespace std;
int c;
string s;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='a')
			c++;
	cout<<min(2*c-1,(int)s.size());
	return 0;
}