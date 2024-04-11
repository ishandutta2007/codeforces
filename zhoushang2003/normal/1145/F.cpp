#include<bits/stdc++.h>
using namespace std;
int A;
string s;
map<char,bool>p;
int main()
{
	p['A']=p['E']=p['F']=p['H']=p['I']=p['K']=p['L']=p['M']=p['N']=p['T']=p['V']=p['W']=p['X']=p['Y']=p['Z']=1;
	cin>>s;
	for(int i=0;i<s.size();i++)
		A+=p[s[i]];
	if(A==s.size()||!A)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}