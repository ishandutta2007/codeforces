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
int n,m,t[5]={},ans[1010][1010]={};
char ch[3030]={};
void init()
{
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;++i)
	{
		gets(ch+1);
		int l=strlen(ch+1);
		for(int j=1;j<=l;j+=3)
			++t[(ch[j]-'0')+(ch[j+1]-'0')];
	}
}
void work()
{
	int a[1010]={},p=0;
	for(int i=1;i<=n && t[2];++i)
		for(int j=1;j<=m && t[2];++j)
		{
			ans[i][j]=2;
			--t[2];
			++a[j];
		}
	for(p=2;a[p]==a[p-1];++p);
	if(p>m)
		p=1;
	bool b=true;
	int l=p,r=a[p]+1;
	while(t[1]) 
	{
		if(b)
		{
			for(int i=l;i<=m && t[1];++i)
			{
				--t[1];
				ans[r][i]=1;
			}
			b=!b;
			l=m;
			++r;
		}
		else
		{
			for(int i=l;i>=1 && t[1];--i)
			{
				--t[1];
				ans[r][i]=1;
			}
			b=!b;
			l=1;
			++r;
		}
	}
}
void print()
{
	bool b[1010]={};
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			if(ans[i][j]==2)
			{
				putchar('1');
				putchar('1');
				putchar(' ');
			}
			if(ans[i][j]==1)
			{
				if(b[j])
				{
					putchar('1');
					putchar('0');
					putchar(' ');
				}
				else
				{
					putchar('0');
					putchar('1');
					putchar(' ');
				}
				b[j]=!b[j];
			}
			if(ans[i][j]==0)
			{
				putchar('0');
				putchar('0');
				putchar(' ');
			}
		}
		putchar('\n');
	}
}
int main()
{	
	init();
	work();
	print();
	return 0;
}