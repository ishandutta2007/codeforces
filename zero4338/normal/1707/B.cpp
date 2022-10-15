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
const int maxn=1e5+5;
int n,a[maxn];
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		for(int i=1;i<=n-1;i++)
		{
			int be=0;
			for(int j=n-i;j>=1;j--)
			{
				be=j;
				if(a[j]==0)break;
			}
			for(int j=be;j<=n-i;j++)a[j]=a[j+1]-a[j];
			sort(a+be,a+n-i+1);
		}
		printf("%d\n",a[1]);
	}
	return 0;
}