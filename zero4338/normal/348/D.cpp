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
const int mod=1e9+7,maxn=3e3+5;
int n,m;
char s[maxn][maxn];
int calc(int x1,int y1,int x2,int y2)
{
	static int f[maxn][maxn];
	if(s[x1][y1]=='#')return 0;
	memset(f,0,sizeof f);
	f[x1][y1]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='.')f[i][j]=((ll)f[i][j]+f[i-1][j]+f[i][j-1])%mod;
	return f[x2][y2];
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	printf("%lld\n",((ll)calc(1,2,n-1,m)*calc(2,1,n,m-1)%mod-(ll)calc(1,2,n,m-1)*calc(2,1,n-1,m)%mod+mod)%mod);
	return 0;
}