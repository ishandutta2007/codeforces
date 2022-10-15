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
const int maxn=5e4+5;
int n,m,k;
int a[maxn],b[maxn];
pair<int,int>av[maxn],bv[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();m=read();
		generate_n(a+1,n,read);
		k=read();
		generate_n(b+1,k,read);
		for(int i=1;i<=n;i++)
		{
			av[i].second=1;
			while(a[i]%m==0)
			{
				a[i]/=m;
				av[i].second*=m;
			}
			av[i].first=a[i];
		}
		for(int i=1;i<=k;i++)
		{
			bv[i].second=1;
			while(b[i]%m==0)
			{
				b[i]/=m;
				bv[i].second*=m;
			}
			bv[i].first=b[i];
		}
		int p1=1,p2=1;
		bool flag=true;
		while(p1<=n&&p2<=k)
		{
			if(av[p1].first!=bv[p2].first)
			{
				flag=false;
				break;
			}
			int del=min(av[p1].second,bv[p2].second);
			av[p1].second-=del;
			if(!av[p1].second)p1++;
			bv[p2].second-=del;
			if(!bv[p2].second)p2++;
		}
		if(p1!=n+1||p2!=k+1)flag=false;
		puts(flag?"Yes":"No");
	}
	return 0;
}