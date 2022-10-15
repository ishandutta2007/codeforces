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
const int maxn=1e4+5;
int n,a[maxn],pre[maxn],suf[maxn];
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		for(int i=1;i<=n;i++)pre[i]=max(pre[i-1],a[i]);
		suf[n+1]=2e9;
		for(int i=n;i>=1;i--)suf[i]=min(suf[i+1],a[i]);
		bool flag=0;
		for(int i=1;i<n;i++)if(pre[i]>suf[i+1])flag=1;
		puts(flag?"YES":"NO");
	}
	return 0;
}