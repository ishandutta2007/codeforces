#include<bits/stdc++.h>
using namespace std;
int n,k,p;
string s;
int main()
{
	cin>>n>>s;
	while(k<n)
		cout<<s[k],k+=++p;
	return 0;
}