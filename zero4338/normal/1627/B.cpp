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
const int maxn=1e5+5;
int n,m;
int val[maxn],cnt;
int main()
{
	T=read();
	while(T--)
	{
		n=read();m=read();
		cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				val[++cnt]=max(max(i+j-2,n-i+j-1),max(i-1+m-j,n-i+m-j));
		sort(val+1,val+cnt+1);
		for(int i=1;i<=cnt;i++)printf("%d ",val[i]);putchar('\n');
	}
	return 0;
}