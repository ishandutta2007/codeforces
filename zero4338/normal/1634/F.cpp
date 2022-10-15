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
const int maxn=3e5+5;
int n,q,mod;
int a[maxn],f[maxn],cnt;
int main()
{
	n=read();q=read();mod=read();
	for(int i=1;i<=n;i++)a[i]=read();
	f[1]=1;
	for(int i=2;i<=n+1;i++)f[i]=(f[i-1]+f[i-2])%mod;
	for(int i=1;i<=n;i++)a[i]=(a[i]-read()+mod)%mod;
	for(int i=n;i>=2;i--)a[i]=((ll)a[i]-a[i-1]-a[i-2]+2*mod)%mod;
	for(int i=1;i<=n;i++)if(a[i])cnt++;
	while(q--)
	{
		char opt;scanf(" %c",&opt);
		int l=read(),r=read();
		if(a[l])cnt--;
		if(r+1<=n&&a[r+1])cnt--;
		if(r+2<=n&&a[r+2])cnt--;
		if(opt=='A')
		{
			(a[l]+=1)%=mod;
			(a[r+1]+=mod-f[r-l+2])%=mod;
			(a[r+2]+=mod-f[r-l+1])%=mod;
		}
		else
		{
			(a[l]+=mod-1)%=mod;
			(a[r+1]+=f[r-l+2])%=mod;
			(a[r+2]+=f[r-l+1])%=mod;
		}
		if(a[l])cnt++;
		if(r+1<=n&&a[r+1])cnt++;
		if(r+2<=n&&a[r+2])cnt++;
		puts(cnt?"NO":"YES");
	}
	return 0;
}