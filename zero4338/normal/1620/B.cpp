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
int w,h;
int main()
{
	T=read();
	while(T--)
	{
		w=read();h=read();
		ll ans=0;
		int k=read();int mi=1e9,mx=0;
		for(int i=1;i<=k;i++)
		{
			int a=read();
			mi=min(mi,a);
			mx=max(mx,a);
		}
		ans=max(ans,(ll)(mx-mi)*h);
		k=read();mi=1e9,mx=0;
		for(int i=1;i<=k;i++)
		{
			int a=read();
			mi=min(mi,a);
			mx=max(mx,a);
		}
		ans=max(ans,(ll)(mx-mi)*h);
		k=read();mi=1e9,mx=0;
		for(int i=1;i<=k;i++)
		{
			int a=read();
			mi=min(mi,a);
			mx=max(mx,a);
		}
		ans=max(ans,(ll)(mx-mi)*w);
		k=read();mi=1e9,mx=0;
		for(int i=1;i<=k;i++)
		{
			int a=read();
			mi=min(mi,a);
			mx=max(mx,a);
		}
		ans=max(ans,(ll)(mx-mi)*w);
		printf("%lld\n",ans);
	}
	return 0;
}