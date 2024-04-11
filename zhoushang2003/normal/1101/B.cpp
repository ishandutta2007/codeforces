#include<iostream>
using namespace std;
string s;
int x,y,A;
int main()
{
	cin>>s;
	x=s.size();
	for(int i=0;i<s.size();i++)
		if(s[i]=='[')
			x=i,A++,i=s.size();
	for(int i=x;i<s.size();i++)
		if(s[i]==':')
			x=i,A++,i=s.size();
	for(int i=s.size()-1;i>=0;i--)
		if(s[i]==']')
			y=i,A++,i=0;
	for(int i=y;i>=0;i--)
		if(s[i]==':')
			y=i,A++,i=0;
	if(x>=y||A!=4)
	{
		cout<<-1;
		return 0;
	}
	for(int i=x;i<=y;i++)
		if(s[i]=='|')
			A++;
	cout<<A;
	return 0;
}