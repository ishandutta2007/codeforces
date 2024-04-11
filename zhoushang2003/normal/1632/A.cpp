#include<bits/stdc++.h>
using namespace std;
int n;
string s;
main()
{
	for(cin>>n;cin>>n>>s;)
		puts(s[0]==s[1]||n>2?"NO":"YES");
}