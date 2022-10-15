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
const int maxn=1e5+5;
int n;ll x,y;
int a[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();x=read();y=read();
		generate_n(a+1,n,read);
		bool now=x&1;
		for(int i=1;i<=n;i++)now^=(a[i]&1);
		puts(now==(y&1)?"Alice":"Bob");
	}
	return 0;
}