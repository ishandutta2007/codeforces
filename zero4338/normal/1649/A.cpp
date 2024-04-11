#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=105;
int T;
int n,a[maxn];
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		int pos0=1,pos1=n;
		for(int i=1;i<=n;i++)if(a[i])pos0=i;else break;
		for(int i=n;i>=1;i--)if(a[i])pos1=i;else break;
		printf("%d\n",max(0,pos1-pos0));
	}
	return 0;
}