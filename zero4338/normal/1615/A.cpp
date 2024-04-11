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
int n;
ll sum;
int main()
{
	T=read();
	while(T--)
	{
		n=read();sum=0;
		for(int i=1;i<=n;i++)sum+=read();
		if(sum%n)puts("1");
		else puts("0");
	}
	return 0;
}