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
const int maxn=20;
int n,a[maxn];
int main()
{
	int T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			int now=__builtin_ctz(a[i]);
			cnt+=now;a[i]>>=now;
		}
		int *mx=max_element(a+1,a+n+1);
		ll ans=0;
		for(int i=1;i<=n;i++)ans+=a[i];
		ans-=*mx;
		ans+=(ll)*mx<<cnt;
		printf("%lld\n",ans);
	}
	return 0;
}