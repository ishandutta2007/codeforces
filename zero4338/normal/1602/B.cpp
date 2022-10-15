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
const int maxn=2e3+5;
int n,q;
int a[maxn][maxn];
int cnt[maxn];
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a[0]+1,n=read(),read);
		for(int i=0;i<n;i++)
		{
			for(int j=1;j<=n;j++)cnt[a[i][j]]++;
			for(int j=1;j<=n;j++)a[i+1][j]=cnt[a[i][j]];
			for(int j=1;j<=n;j++)cnt[a[i][j]]--;
		}
		q=read();
		while(q--)
		{
			int x=read(),k=min(n,read());
			printf("%d\n",a[k][x]);
		}
	}
	return 0;
}