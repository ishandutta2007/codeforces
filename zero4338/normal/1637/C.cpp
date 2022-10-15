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
int T;
const int maxn=1e5+5;
int n,a[maxn];
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		bool flag=0;
		ll ans=0;
		for(int i=2;i<=n-1;i++)if(a[i]%2==0)flag=1;
		if(flag)
		{
			for(int i=2;i<=n-1;i++)ans+=(a[i]+1)/2;
			printf("%lld\n",ans);
		}
		else
		{
			if(n==3)puts("-1");
			else
			{
				for(int i=2;i<=n-1;i++)if(a[i]>1)flag=1;
				if(!flag)puts("-1");
				else
				{
					for(int i=2;i<=n-1;i++)ans+=(a[i]+1)/2;
					printf("%lld\n",ans);
				}
			}
		}
	}
	return 0;
}