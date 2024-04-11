#include<iostream>
using namespace std;
int c,A;
string s;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='(')
			c++;
		else if(c)
			c--,A+=2;
	cout<<A;
	return 0;
}