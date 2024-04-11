#include<iostream>
using namespace std;
int n=-1;
string s;
int main()
{	
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]!='/')
			n=i;
	if(n<0)
	{
		cout<<'/';
		return 0;
	}
	cout<<s[0];
	for(int i=1;i<=n;i++)
		if(s[i]!='/'||s[i]!=s[i-1])
			cout<<s[i];
	return 0;
}