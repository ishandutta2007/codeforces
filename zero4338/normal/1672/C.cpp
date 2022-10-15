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
const int maxn=2e5+5;
int n,a[maxn];
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		int ans=0;
		int be=-1,ed=-1;
		for(int i=1;i+1<=n;i++)if(a[i]==a[i+1]){be=i;break;}
		for(int i=n-1;i>=1;i--)if(a[i]==a[i+1]){ed=i;break;}
		if(be==ed)puts("0");
		else printf("%d\n",max(1,ed-be-1));
	}
	return 0;
}