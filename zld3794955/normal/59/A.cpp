#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;
char ch[200]={};
int a=0,l=0;
int main()
{	
	gets(ch);
	l=strlen(ch);
	for(int i=0;i<l;++i)
		if(isupper(ch[i]))
			++a;
		else
			--a;
	if(a<=0)
		for(int i=0;i<l;++i)
			ch[i]=tolower(ch[i]);
	else
		for(int i=0;i<l;++i)
			ch[i]=toupper(ch[i]);
	puts(ch);
	return 0;
}