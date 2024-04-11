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
const int maxn=105;
int n,a[maxn];
int cnt[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)cnt[read()]++;
		for(int i=0;i<maxn;i++)
			if(cnt[i]){cnt[i]--;printf("%d ",i);}
		for(int i=0;i<maxn;i++)
			for(int j=1;j<=cnt[i];j++)printf("%d ",i);
		printf("\n");
		for(int i=0;i<maxn;i++)cnt[i]=0;
	}
	return 0;
}