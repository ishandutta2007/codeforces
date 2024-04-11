#include<bits/stdc++.h>
using namespace std;
const int L=1000010;
char ch[L]={};
int l,nxt[L]={};
bool exist[L]={};
int main()
{
	gets(ch+1);
	l=strlen(ch+1);
	int p=0;
	nxt[1]=0;
	for(int i=2;i<=l;++i)
	{
		while(p && ch[p+1]!=ch[i])
			p=nxt[p];
		if(ch[p+1]==ch[i])
			++p;
		nxt[i]=p;
	}
	for(int i=1;i<l;++i)
		exist[nxt[i]]=true;
	p=l;
	while(p)
	{
		if(exist[p])
		{
			ch[p+1]=0;
			puts(ch+1);
			break;
		}
		p=nxt[p];
	}
	if(!p)
		puts("Just a legend");
}