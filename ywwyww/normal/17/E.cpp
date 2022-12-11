#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
typedef long long ll;
//	 
ll mod=51123987;
char s[4000010];
int f[4000010];
int g[4000010];// 
ll r[4000010];//i
ll l[4000010];
//ll h[4000010];//r[i]*i 
//ll t[4000010];//r[i]
//r[i-g[i]+1]*1+r[i-g[i]+2]*2+...+r[i-1]*(g[i]-1)+
//r[i]*g[i]+r[i+1]*(g[i]-1)+...+r[i+g[i]-2]*2+r[i+g[i]-1]*1
//-r[i]*2
//ll sumh(int l,int r)
//{
//	return (h[r]-h[l-1]+mod)%mod;
//}
//ll sumt(int l,int r)
//{
//	return (t[r]-t[l-1]+mod)%mod;
//}
int main()
{
//	freopen("cf.in","r",stdin);
//	freopen("cf.out","w",stdout);
//	memset(r,0,sizeof r);
//	memset(h,0,sizeof h);
//	memset(t,0,sizeof t);
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	int n;
	scanf("%d",&n);
	scanf("%s",s+1);
	int i,j;
	for(i=n;i>=1;i--)
	{
		s[2*i+1]='*';
		s[2*i]=s[i];
	}
	s[1]='*';
	int m=2*n+1;
	int k,p=0;
	for(i=1;i<=m;i++)
	{
		if(i<=p)
			f[i]=min(f[2*k-i],p-i+1);
		else
			f[i]=1;
		while(i+f[i]<=m&&i-f[i]>=1&&s[i+f[i]]==s[i-f[i]])
			f[i]++;
		if(i+f[i]-1>p)
		{
			k=i;
			p=i+f[i]-1;
		}
	}
	for(i=1;i<=m;i++)
	{
		j=i/2;
		int ss=f[i]-1;
		if(i&1)
		{
			ss>>=1;
			l[j-ss+1]++;
			l[j+1]--;
			r[j+1]++;
			r[j+ss+1]--;
		}
		else
		{
			ss=(ss+1)>>1;
			l[j-ss+1]++;
			l[j+1]--;
			r[j]++;
			r[j+ss]--;
		}
		g[i]=ss;
	}
	for(i=1;i<=n;i++)
	{
		l[i]=(l[i-1]+l[i])%mod;
		r[i]=(r[i-1]+r[i])%mod;
	}
	for(i=1;i<=n;i++)
	{
		l[i]=(l[i-1]+l[i])%mod;
		r[i]=(r[i-1]+r[i])%mod;
	}
	ll ans=r[n]*(r[n]-1)/2%mod;
	for(i=1;i<n;i++)
		ans=(ans-r[i]*(l[i+1]-l[i])%mod+mod)%mod;
//	for(i=1;i<=n;i++)
//	{
//		r[i]=(r[i]%mod+r[i-1]+mod)%mod;
//		h[i]=(r[i]*i+h[i-1])%mod;
//		t[i]=(r[i]+t[i-1])%mod;
//	}
//	ll ans=0;
//	for(i=1;i<=m;i++)
//	{
//		j=i/2;
//		if(i&1)
//		{
//			ans=(ans+sumh(j-g[i]+1,j)-sumt(j-g[i]+1,j)*(j-g[i])%mod+mod)%mod;
//			ans=(ans-sumh(j+1,j+g[i])+sumt(j+1,j+g[i])*(j+g[i]+1)%mod+mod)%mod;
//		}
//		else
//		{
//			ans=(ans+sumh(j-g[i]+1,j)-sumt(j-g[i]+1,j)*(j-g[i])%mod+mod)%mod;
//			ans=(ans-sumh(j+1,j+g[i]-1)+sumt(j+1,j+g[i]-1)*(j+g[i])%mod+mod)%mod;
//		}
//	}
//	for(i=1;i<=n;i++)
////		ans=(ans-r[i]*r[i]%mod+mod)%mod;
//		ans=(ans-(r[i]+1)*r[i]/2%mod+mod)%mod;
	printf("%I64d\n",ans);
	return 0;
}