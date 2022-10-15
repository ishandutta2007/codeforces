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
const int maxn=1e5+5,maxm=2e6+5,mod=998244353;
int n,a[maxn],ans;
int fac[maxm],inv[maxm];
void prework()
{
	int n=2e6;
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=(ll)fac[i-1]*i%mod;
	inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++)inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<=n;i++)inv[i]=(ll)inv[i-1]*inv[i]%mod;
}
int C(int n,int m)
{
	if(n<m||n<0||m<0)return 0;
	return (ll)fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int dif[maxn];
int main()
{
	generate_n(a+1,n=read(),read);
	prework();
	sort(a+1,a+n+1);
	int pos=-1;
	for(int i=1;i<n;i++)
		if(a[i+1]<i){pos=i;break;}
	if(pos!=-1)
	{
		int cnt=0;
		for(int i=0;i<=pos;i++)
		{
			while(cnt<n&&a[cnt+1]<i)cnt++;
			(ans+=C(i-cnt+n-1,n-1))%=mod;
		}
		printf("%d\n",ans);
		return 0;
	}
	for(int i=1;i<=n;i++)
		dif[a[i]%n+1]++;
	int bas=0;
	for(int i=1;i<=n;i++)bas-=a[i]/n;
	for(int i=0;i<n;i++)
	{
		bas+=dif[i];
		int del=0;
		int now=i-bas;
		(ans+=C(now+n-1,n-1))%=mod;
	}
	printf("%d\n",ans);
	return 0;
}