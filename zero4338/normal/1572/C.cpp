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
int T;
const int maxn=3e3+5;
int n;
int a[maxn];
vector<int>p[maxn];
int f[maxn][maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)p[i].clear();
		for(int i=1;i<=n;i++)p[a[i]=read()].push_back(i);
		for(int len=2;len<=n;len++)
		{
			for(int l=1;l+len-1<=n;l++)
			{
				int r=l+len-1;
				f[l][r]=f[l+1][r];
				for(int k:p[a[l]])if(k>l&&k<=r)f[l][r]=max(f[l][r],f[l+1][k-1]+f[k][r]+1);
			}
		}
		printf("%d\n",n-1-f[1][n]);
	}
	return 0;
}