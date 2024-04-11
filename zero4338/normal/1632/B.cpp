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
int n;
int main()
{
	T=read();
	while(T--)
	{
		n=read()-1;
		int to=1<<((int)log2(n));
		for(int i=to-1;i>=0;i--)printf("%d ",i);
		for(int i=to;i<=n;i++)printf("%d ",i);
		putchar('\n');
	}
	return 0;
}