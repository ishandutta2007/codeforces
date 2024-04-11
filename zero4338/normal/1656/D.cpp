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
ll n;
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		if(n&1)puts("2");
		else
		{
			ll p=1;
			while(!(n&1))p*=2,n/=2;
			p*=2;
			if(p+1<=n)printf("%lld\n",p);
			else if(n!=1)printf("%lld\n",n);
			else puts("-1");
		}
	}
	return 0;
}