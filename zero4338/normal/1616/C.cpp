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
const int maxn=75;
int n,a[maxn];
int calc(int p1,int p2)
{
	auto val=[&](int pos)
	{
		if(((a[p2]-a[p1])*(pos-p1))%(p2-p1))return -1000;
		return a[p1]+(a[p2]-a[p1])*(pos-p1)/(p2-p1);
	};
	int ret=0;
	for(int i=1;i<=n;i++)
		if(val(i)!=a[i])ret++;
	return ret;
}
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		if(n==1){puts("0");continue;}
		int ans=1e9;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)ans=min(ans,calc(i,j));
		printf("%d\n",ans);
	}
	return 0;
}