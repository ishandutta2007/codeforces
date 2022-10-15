#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll read()
{
	ll ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
ll k,n;
ll ans;
int main()
{
	T=read();
	while(T--)
	{
		n=read();k=read();
		ll now=1;n-=now;ans=0;
		while(now<=n&&now<=k){n-=now;now<<=1;ans++;}
		ans+=ceil(1.0*n/k);
		printf("%lld\n",ans);
	}
	return 0;
}