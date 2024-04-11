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
int n,L,k;
int d[maxn],a[maxn];
int f[maxn][maxn];
int main()
{
	n=read();L=read();k=read();
	generate_n(d+1,n,read);
	generate_n(a+1,n,read);
	memset(f,0x3f,sizeof f);
	f[1][0]=0;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			for(int l=1;l<i;l++)
			{
				f[i][j]=min(f[i][j],f[l][j-(i-l-1)]+(d[i]-d[l])*a[l]);
			}
		}
	}
	int ans=2e9;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k-(n-i);j++)
		{
			ans=min(ans,f[i][j]+a[i]*(L-d[i]));
		}
	printf("%d\n",ans);
	return 0;
}