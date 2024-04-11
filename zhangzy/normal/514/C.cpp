#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#define xxx 700000
#define yyy 10000000
using namespace std;
struct tree{
	int v,ch[4],alright;
}a[yyy];
int n,m,cnt=1,cg;
char s[xxx];

int realcheck(int p,int j)
{
	for (int i=j;i<strlen(s);i++)
	{
		p=a[p].ch[s[i]-cg];
		if (!p) return 0;
	}
	return a[p].alright;
}

int check()
{
	int p=1;
	for (int i=0;i<strlen(s);i++)
	{
		for (int j=1;j<=3;j++)
			if (a[p].ch[j]&&j!=s[i]-cg)
				if (realcheck(a[p].ch[j],i+1))
					return 1;
		p=a[p].ch[s[i]-cg];
		if (!p) return 0;
	}
	return 0;
}

int main()
{
	cg='a'-1;
	scanf("%d%d\n",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%s",s);
		int p=1;
		for (int i=0;i<strlen(s);i++)
		{
			if (a[p].ch[s[i]-cg]==0)
			{
				a[p].ch[s[i]-cg]=++cnt;
				p=cnt;
			}
			else
			{
				p=a[p].ch[s[i]-cg];
			}
		}
		a[p].alright=1;
	}
	for (int i=1;i<=m;i++)
	{
		scanf("%s",s);
		if (check())
			printf("YES\n");
		else
			printf("NO\n");
	}
}