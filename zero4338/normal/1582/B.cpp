#include<iostream>
#include<cstdio>
#include<algorithm>
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
const int maxn=65;
int n,a[maxn];
ll ans;
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		ans=0;
		for(int i=1;i<=n;i++)if(a[i]==1)ans++;
		for(int i=1;i<=n;i++)if(a[i]==0)ans*=2;
		printf("%lld\n",ans);
	}
	return 0;
}