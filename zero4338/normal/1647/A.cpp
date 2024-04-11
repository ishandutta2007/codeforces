#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T,n;
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		if(n%3==0)for(int i=1;i<=n/3;i++)printf("21");
		if(n%3==1){for(int i=1;i<=n/3;i++)printf("12");putchar('1');}
		if(n%3==2){for(int i=1;i<=n/3;i++)printf("21");putchar('2');}
		putchar('\n');
	}
	return 0;
}