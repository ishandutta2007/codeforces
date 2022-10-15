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
int n,a[maxn];
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		int ans=0;
		for(int l=1;l<=n;l++)
		{
			int pos=0;
			for(int r=l;r<=n;r++)
			{
				ans+=r-l+1;
				if(a[r]==0)pos++;
				ans+=pos;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}