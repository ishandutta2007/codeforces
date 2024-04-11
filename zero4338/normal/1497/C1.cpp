#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
int T;
int n,k;
int main()
{
	T=read();
	while(T--)
	{
		n=read();k=read();
		if(n%4==0)printf("%d %d %d\n",n/2,n/4,n/4);
		else if(n%2==1)printf("%d %d %d\n",1,(n-1)/2,(n-1)/2);
		else printf("%d %d %d\n",2,(n-2)/2,(n-2)/2);
	}
	return 0;
}