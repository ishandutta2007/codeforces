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
const int maxn=1e7+5;
const int mod=998244353;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int n,k,x;
int ans;
int pow2[maxn],pow2n[maxn],pre[maxn];
int main()
{
	T=read();
	pow2[0]=1;for(int i=1;i<=1e7;i++)pow2[i]=pow2[i-1]*2%mod;
	while(T--)
	{
		n=read();k=read();x=read();
		if(!x)
		{
			if(n>k)printf("0\n");
			else
			{
				ans=1;
				for(int i=0;i<=n-1;i++)ans=(ll)ans*(pow2[k]-pow2[i]+mod)%mod;
				printf("%d\n",ans);
			}
		}
		else
		{
			if(k==0){printf("1\n");continue;}
			pre[0]=pow2[k-1]-1;for(int i=1;i<=k-1;i++)pre[i]=(ll)pre[i-1]*(pow2[k-i-1]-1)%mod;
			pow2n[0]=1;pow2n[1]=qpow(2,n);for(int i=2;i<k;i++)pow2n[i]=(ll)pow2n[i-1]*pow2n[1]%mod;
			ans=0;
			for(int i=0;i<k;i++)
			{
				int val=(ll)pow2n[k-1-i]*pow2[k-i-1]%mod;
				if(i)val=(ll)val*pre[i-1]%mod;
				if(i&1)ans=(ans-val+mod)%mod;
				else ans=(ans+val)%mod;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
//orz cbx ak ioi