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
int main()
{
	int T=read();
	while(T--)
	{
		ll hc=read(),dc=read(),hm=read(),dm=read(),k=read(),w=read(),a=read();
		bool flag=0;
		for(int i=0;i<=k;i++)
			if((hm-1)/(dc+i*w)<=(hc+a*(k-i)-1)/dm){flag=1;break;}
		puts(flag?"YES":"NO");
	}
	return 0;
}