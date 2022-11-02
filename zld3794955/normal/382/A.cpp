#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
using namespace std;
char ch[101]={},c[101]={};
int l1,l2,pos=0,l,r;
int main()
{	
	gets(ch);
	gets(c);
	l1=strlen(ch);
	l2=strlen(c);
	for(int i=0;i<l1;++i)
		if(ch[i]=='|')
		{
			pos=i;
			break;
		}
	l=pos;
	r=l1-pos-1;
	if(l+l2<r || r+l2<l)
		puts("Impossible");
	else
	{
		if((l+l2+r)%2)
			puts("Impossible");
		else
		{
			int k;
			for(k=1;k<=(l+l2+r)/2-l;++k)
				putchar(c[k-1]);
			for(int i=0;i<l1;++i)
				putchar(ch[i]);
			for(;k<=l2;++k)
				putchar(c[k-1]);
			putchar('\n');
		}
	}
	return 0;
}