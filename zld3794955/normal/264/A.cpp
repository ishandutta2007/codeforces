#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int L=1000010;
char ch[L]={};
int n,a[L]={},ans[L]={};
int main()
{	
	gets(ch+1);
	n=strlen(ch+1);
	int l=1,r=n;
	for(int i=1;i<=n;++i)
		a[i]=ch[i]=='l' ? r-- : l++;
	for(int i=1;i<=n;++i)
		ans[a[i]]=i;
	for(int i=1;i<=n;++i)
		printf("%d\n",ans[i]);
	return 0;
}