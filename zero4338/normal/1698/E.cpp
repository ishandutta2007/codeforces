#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=2e5+5,mod=998244353;
int n,s,a[maxn],b[maxn],to[maxn];
bool exi[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();s=read();
		for(int i=1;i<=n;i++)a[read()]=i;
		memset(to,0,sizeof(int)*(n+1));
		for(int i=1;i<=n;i++)
		{
			b[i]=read();
			if(b[i]!=-1)to[i]=b[i];
		}
		bool flag=true;
		for(int i=1;i<=n;i++)
		{
			a[i]=to[a[i]];
			if(a[i]&&i>a[i]+s)flag=false;
		}
		if(!flag){puts("0");continue;}
		memset(exi,0,sizeof(bool)*(n+1));
		for(int i=1;i<=n;i++)exi[a[i]]=true;
		int emp=0,ans=1;
		for(int i=1;i<=s;i++)if(a[i]==0)emp++;
		for(int i=1;i<=n;i++)
		{
			if(i+s<=n&&a[i+s]==0)emp++;
			if(!exi[i])
			{
				ans=(ll)ans*emp%mod;
				emp--;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}