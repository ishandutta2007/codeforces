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
		long long sum=0;bool flag=true;
		for(int i=1;i<=n;i++)
		{
			if(a[i]&&sum==0&&i!=1)flag=false;
			sum+=a[i];
			if(sum<0)flag=false;
		}
		if(sum)flag=false;
		puts(flag?"Yes":"No");
	}
	return 0;
}