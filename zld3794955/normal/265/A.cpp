#include<bits/stdc++.h>
using namespace std;
const int L=1000010;
char s[L]={},t[L]={};
int n,m;
int main()
{
	gets(s+1);
	gets(t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	int p=1;
	for(int i=1;i<=m;++i)
		p+=s[p]==t[i];
	cout<<p<<endl;
	return 0;
}