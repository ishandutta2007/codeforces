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
const int maxn=5e3+5;
int n,tag[maxn],s[maxn];
ll ans=0;
ll f[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		generate_n(tag+1,n,read);generate_n(s+1,n,read);
		for(int i=1;i<=n;i++)f[i]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i-1;j>=1;j--)
			{
				if(tag[i]!=tag[j])
				{
					int del=abs(s[i]-s[j]);
					ll vi=f[i],vj=f[j];
					f[j]=max(f[j],vi+del);
					f[i]=max(f[i],vj+del);
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++)ans=max(ans,f[i]);
		printf("%lld\n",ans);
	}
	return 0;
}