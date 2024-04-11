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
const int maxm=1e7+5;
int n,k;
int ans;
int a[maxn];
int p[maxm],cnt;bool vis[maxm];int sq[maxm];
void prework()
{
	sq[1]=1;
	for(int i=2;i<maxm;i++)
	{
		if(!vis[i]){p[++cnt]=i;sq[i]=i;}
		for(int j=1;j<=cnt&&p[j]*i<maxm;j++)
		{
			vis[p[j]*i]=1;
			if(sq[i]%p[j])sq[i*p[j]]=sq[i]*p[j];
			else sq[i*p[j]]=sq[i]/p[j];
			if(i%p[j]==0)break;
		}
	}
}
bool exi[maxm];
int main()
{
	T=read();prework();
	while(T--)
	{
		n=read();k=read();
		generate_n(a+1,n,read);
		for(int i=1;i<=n;i++)a[i]=sq[a[i]];
		ans=1;int ls=0;
		for(int i=1;i<=n;i++)
		{
			if(!exi[a[i]])exi[a[i]]=1;
			else
			{
				ans++;
				for(int j=ls+1;j<=i-1;j++)exi[a[j]]=0;
				exi[a[i]]=1;
				ls=i-1;
			}
		}
		for(int i=ls+1;i<=n;i++)exi[a[i]]=0;
		printf("%d\n",ans);
	}
	return 0;
}