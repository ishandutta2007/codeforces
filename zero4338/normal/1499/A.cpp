#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
int n,k1,k2,w,b;
int main()
{
	T=read();
	while(T--)
	{
		n=read();k1=read();k2=read();w=read();b=read();
		puts(k1+k2>=2*w&&2*n-k1-k2>=2*b?"YES":"NO");
	}
	return 0;
}