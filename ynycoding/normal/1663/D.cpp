#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	int x;
	cin>>s>>x;
	if(s=="ABC")
		cout<<((x<2000)?"YES":"NO");
	if(s=="ARC")
		cout<<((x<2800)?"YES":"NO");
	if(s=="AGC")
		cout<<((x>=1200)?"YES":"NO");
	return 0;
}