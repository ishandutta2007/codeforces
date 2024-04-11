#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
const int maxn=1e6+5;
int n,m,q;
vector<bool>a[maxn];
char s[maxn];
int pre[maxn];
int main()
{
	n=read();m=read();
	a[0].resize(m+1);
	for(int i=1;i<=n;i++)
	{
		a[i].resize(m+1);
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)a[i][j]=s[j]=='X';
	}
	for(int i=1;i<m;i++)
		for(int j=1;j<=n;j++)
			if(a[j][i]&&a[j-1][i+1]){pre[i]=1;break;}
	for(int i=1;i<=m;i++)pre[i]+=pre[i-1];
	q=read();
	while(q--)
	{
		int l=read(),r=read();
		if(pre[r-1]-pre[l-1])printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}