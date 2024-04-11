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
const int maxm=1e4+5;
int n,a[maxn],b[maxn];
bitset<maxm*2>f;
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		generate_n(a+1,n,read);
		generate_n(b+1,n,read);
		if(n==1){puts("0");continue;}
		f=0;
		f[1e4]=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>b[i])f|=f>>(2*a[i]-2*b[i]);
			else f|=f<<(2*b[i]-2*a[i]);
		}
		int dif=0;
		for(int i=1;i<=n;i++)dif+=a[i]-b[i];
		int now=dif;
		for(int i=0;i<=2e4;i++)
			if(f[i]&&abs(dif+i-1e4)<abs(now))now=dif+i-1e4;
		int sum=0;
		for(int i=1;i<=n;i++)sum+=a[i]+b[i];
		int suma=(sum+now)/2,sumb=(sum-now)/2;
		ll ans=suma*suma+sumb*sumb;
		for(int i=1;i<=n;i++)ans+=(n-2)*a[i]*a[i]+(n-2)*b[i]*b[i];
		printf("%lld\n",ans);
	}
	return 0;
}