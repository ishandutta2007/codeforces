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
int cnt[31];
int n,l;
int main()
{
	T=read();
	while(T--)
	{
		n=read();l=read();
		for(int i=0;i<l;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)
		{
			int x=read();
			for(int j=0;j<l;j++)cnt[j]+=(x>>j)&1;
		}
		int ans=0;
		for(int i=0;i<l;i++)
			if(cnt[i]>=(n+1)/2)ans|=(1<<i);
		printf("%d\n",ans);
	}
	return 0;
}