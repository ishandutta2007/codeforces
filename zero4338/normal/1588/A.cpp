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
const int maxn=105;
int n;
int a[maxn],b[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();generate_n(a+1,n,read);generate_n(b+1,n,read);
		sort(a+1,a+n+1);sort(b+1,b+n+1);
		bool flag=1;
		for(int i=1;i<=n;i++)
			if(a[i]!=b[i]&&a[i]!=b[i]-1)flag=0;
		puts(flag?"YES":"NO");
	}
	return 0;
}