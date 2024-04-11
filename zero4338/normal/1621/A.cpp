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
int n,k;
const int maxn=45;
char s[maxn][maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();k=read();
		if((n+1)/2<k)puts("-1");
		else
		{
			for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)s[i][j]='.';
			for(int i=1;i<=k;i++)
				s[2*i-1][2*i-1]='R';
			for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)putchar(s[i][j]);putchar('\n');}
		}
	}
	return 0;
}