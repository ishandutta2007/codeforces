#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int a[N],t,A;
string s;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(t>0&&a[t-1]==s[i])
			A++,t--;
		else
			a[t++]=s[i];
	if(A&1)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}