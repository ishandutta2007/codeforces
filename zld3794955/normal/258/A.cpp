#include<bits/stdc++.h>
using namespace std;
const int L=100010;
char ch[L]={};
int n;
int main()
{
	gets(ch+1);
	n=strlen(ch+1);
	int p=find(ch+1,ch+n+1,'0')-ch;
	if(p==n+1)
		p=n;
	for(int i=1;i<=n;++i)
		if(i!=p)
			putchar(ch[i]);
	putchar('\n');
	return 0;
}