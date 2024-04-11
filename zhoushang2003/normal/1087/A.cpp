#include<iostream>
using namespace std;
string s,l,r;
int m;
int main()
{
	cin>>s;
	m=(s.size()-1)/2;
	for(int i=m;i>=0;i--)
		l+=s[i];
	for(int i=m+1;i<s.size();i++)
		r+=s[i];
	for(int i=0;i<r.size();i++)
		cout<<l[i]<<r[i];
	if(l.size()>r.size())
		cout<<l[l.size()-1];
	cout<<endl;
	return 0;
}