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
const int maxn=1e5+5,maxk=5,maxm=17,mod=998244353;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int n,m,k;
int w[maxk],a[maxn][maxk],sum[1<<maxk];
int f[1<<maxm];
int v[1<<maxm][1<<maxk];
void fwt(int lim,int *f)
{
	for(int t=lim>>1,d=1;d<lim;d<<=1,t>>=1)
		for(int i=0;i<lim;i+=(d<<1))
			for(int j=0;j<d;j++)
			{
				int tmp0=f[i+j],tmp1=f[i+j+d];
				f[i+j]=(tmp0+tmp1)%mod;
				f[i+j+d]=(tmp0-tmp1+mod)%mod;
			}
}
void ifwt(int lim,int *f)
{
	int i2=(mod+1)/2;
	for(int t=lim>>1,d=1;d<lim;d<<=1,t>>=1)
		for(int i=0;i<lim;i+=(d<<1))
			for(int j=0;j<d;j++)
			{
				int tmp0=f[i+j],tmp1=f[i+j+d];
				f[i+j]=(tmp0+tmp1)%mod;
				f[i+j+d]=(tmp0-tmp1+mod)%mod;
				f[i+j]=(ll)f[i+j]*i2%mod;
				f[i+j+d]=(ll)f[i+j+d]*i2%mod;
			}
}
int main()
{
	n=read();m=read();k=3;
	generate_n(w,k,read);
	for(int i=1;i<=n;i++)generate_n(a[i],k,read);
	for(int i=0;i<(1<<k);i++)
	{
		memset(f,0,sizeof(int)*(1<<m));
		for(int j=1;j<=n;j++)
		{
			int s=0;
			for(int l=0;l<k;l++)if((i>>l)&1)s^=a[j][l];
			f[s]++;
		}
		fwt(1<<m,f);
		for(int j=0;j<(1<<m);j++)v[j][i]=f[j];
	}
	for(int i=0;i<(1<<k);i++)
		for(int l=0;l<k;l++)
		{
			if((i>>l)&1)(sum[i]+=mod-w[l])%=mod;
			else (sum[i]+=w[l])%=mod;
		}
	memset(f,0,sizeof(int)*(1<<m));
	for(int i=0;i<(1<<m);i++)
	{
		f[i]=1;
		ifwt(1<<k,v[i]);
		for(int j=0;j<(1<<k);j++)
			f[i]=(ll)f[i]*qpow(sum[j],v[i][j])%mod;
	}
	ifwt(1<<m,f);
	for(int i=0;i<(1<<m);i++)printf("%d ",f[i]);putchar('\n');
	return 0;
}