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
char a[310]={},b[110]={},c[110]={};
int main()
{	
	gets(a);
	int i,j,k;
	for(i=0;a[i]!='+';++i);
	a[i]=0;
	for(j=i+1;a[j]!='=';++j);
	a[j]=0;
	for(k=i+1;k<j;++k)
		b[k-i-1]=a[k];
	for(k=j+1;a[k];++k)
		c[k-j-1]=a[k];
	int la=strlen(a);
	int lb=strlen(b);
	int lc=strlen(c);
	if(la+lb==lc)
		printf("%s+%s=%s\n",a,b,c);
	else
	{
		if(lc-la-lb==2)
		{
			c[lc-1]='\0';
			printf("%s|+%s=%s\n",a,b,c);
		}
		else if(lc-la-lb==-2)
		{
			if(la>1)
				a[la-1]='\0';
			else
				b[lb-1]='\0';
			printf("%s+%s=%s|\n",a,b,c);
		}
		else
			puts("Impossible");
	}
	return 0;
}