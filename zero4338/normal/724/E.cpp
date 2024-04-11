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
const int maxn=1e4+5;
int n,c;
int p[maxn],s[maxn];
ll f[maxn],g[maxn];
int main()
{
	n=read();c=read();generate_n(p+1,n,read);generate_n(s+1,n,read);
	memset(f,0x3f,sizeof f);
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		memset(g,0x3f,sizeof g);
		for(int j=0;j<=i;j++)
		{
			if(j)g[j]=min(g[j],f[j-1]+s[i]);
			g[j]=min(g[j],f[j]+(ll)c*j+p[i]);
		}
		memcpy(f,g,sizeof g);
	}
	ll ans=1e18;
	for(int i=0;i<=n;i++)ans=min(ans,f[i]);
	printf("%lld\n",ans);
	return 0;
}