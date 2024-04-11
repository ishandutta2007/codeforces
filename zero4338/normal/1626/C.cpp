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
const int maxn=105;
int n,k[maxn],h[maxn];
ll f[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		generate_n(k+1,n,read);
		generate_n(h+1,n,read);
		memset(f,0x3f,sizeof f);
		f[0]=0;
		for(int i=1;i<=n;i++)
		{
			int mi=1e9;
			for(int j=i;j>=1;j--)
			{
				mi=min(mi,k[j]-h[j]+1);
				if(mi>k[j-1])f[i]=min(f[i],f[j-1]+(ll)(k[i]-mi+2)*(k[i]-mi+1)/2);
			}
		}
		printf("%lld\n",f[n]);
	}
	return 0;
}