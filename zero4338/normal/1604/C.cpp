#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
int T;
const int maxn=1e5+5;
int n,a[maxn];
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		bool flag=1;
		for(int i=1;i<=n;i++)
		{
			flag=0;
			for(int j=2;j<=i+1;j++)if(a[i]%j){flag=1;break;}
			if(!flag)break;
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}