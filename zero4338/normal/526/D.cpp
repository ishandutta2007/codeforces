#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e6+5;
int n,k;
char s[maxn];
int nxt[25][maxn];
int main()
{
	n=read();k=read();
	scanf("%s",s+1);
	if(k==1)
	{
		for(int i=1;i<=n;i++)putchar('1');
		putchar('\n');
		return 0;
	}
	for(int i=2,j=0;i<=n;i++)
	{
		while(j&&s[j+1]!=s[i])j=nxt[0][j];
		if(s[j+1]==s[i])j++;
		nxt[0][i]=j;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<25;j++)nxt[j][i]=nxt[j-1][nxt[j-1][i]];
		int now=i;
		for(int j=24;j>=0;j--)
			if(i>=(ll)k*(i-nxt[j][now]))now=nxt[j][now];
		putchar(i<=(ll)(k+1)*(i-now)?'1':'0');
	}
	putchar('\n');
	return 0;
}