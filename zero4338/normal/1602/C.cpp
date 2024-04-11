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
const int maxm=30;
int n,a[maxn];
int cnt[maxm];
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		for(int i=0;i<30;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<30;j++)if((a[i]>>j)&1)cnt[j]++;
		int d=0;
		for(int i=0;i<30;i++)d=__gcd(d,cnt[i]);
		if(!d)for(int i=1;i<=n;i++)printf("%d ",i);
		else for(int i=1;i<=d;i++)if(d%i==0)printf("%d ",i);
		printf("\n");
	}
	return 0;
}