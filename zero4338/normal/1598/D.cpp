#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define int long long
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
int T;
const int maxn=2e5+5;
int n;
int ans;
int cnta[maxn],cntb[maxn],a[maxn],b[maxn];
signed main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n;i++)cnta[i]=cntb[i]=0;ans=0;
		for(int i=1;i<=n;i++){cnta[a[i]=read()]++;cntb[b[i]=read()]++;}
		for(int i=1;i<=n;i++)ans-=(cnta[a[i]]-1)*(cntb[b[i]]-1);
		ans=ans+n*(n-1)*(n-2)/6;
		printf("%lld\n",ans);
	}
	return 0;
}