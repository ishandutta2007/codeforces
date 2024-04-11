#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=55;
int n,m,r,c;
char s[maxn][maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();m=read();r=read();c=read();
		for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
		bool flag0=0,flag1=0;
		if(s[r][c]=='B')puts("0");
		else
		{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
				{
					if((i==r||j==c)&&s[i][j]=='B')flag0=1;
					if(s[i][j]=='B')flag1=1;
				}
			if(flag0)puts("1");
			else if(flag1)puts("2");
			else puts("-1");
		}
	}
	return 0;
}