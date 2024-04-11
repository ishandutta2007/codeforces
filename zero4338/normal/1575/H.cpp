#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=505;
int n,m;
char a[maxn],b[maxn];
int nxt[maxn],to[maxn][2];
int f[maxn][maxn][maxn];
int main()
{
	n=read();m=read();scanf("%s%s",a+1,b+1);
	for(int i=2,j=0;i<=m;i++)
	{
		while(j&&b[i]!=b[j+1])j=nxt[j];
		if(b[i]==b[j+1])j++;
		nxt[i]=j;
	}
	for(int i=0;i<=m;i++)
	{
		if(i<m)to[i][b[i+1]-'0']=i+1;
		to[i][0]=max(to[i][0],to[nxt[i]][0]);
		to[i][1]=max(to[i][1],to[nxt[i]][1]);
	}
	memset(f,0x3f,sizeof f);
	f[0][0][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=n-m+1;j++)
		{
			for(int k=0;k<=m;k++)
			{
				f[i+1][j+(to[k][a[i+1]-'0']==m)][to[k][a[i+1]-'0']]=min(f[i+1][j+(to[k][a[i+1]-'0']==m)][to[k][a[i+1]-'0']],f[i][j][k]);
				f[i+1][j+(to[k][!(a[i+1]-'0')]==m)][to[k][!(a[i+1]-'0')]]=min(f[i+1][j+(to[k][!(a[i+1]-'0')]==m)][to[k][!(a[i+1]-'0')]],f[i][j][k]+1);
			}
		}
	}
	for(int i=0;i<=n-m+1;i++)
	{
		int ans=1e9;
		for(int j=0;j<=m;j++)ans=min(ans,f[n][i][j]);
		printf("%d ",ans==1e9?-1:ans);
	}
	return 0;
}