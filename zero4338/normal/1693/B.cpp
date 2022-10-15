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
const int maxn=2e5+5;
int n;
int l[maxn],r[maxn],p[maxn];
ll val[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		generate_n(p+2,n-1,read);
		for(int i=1;i<=n;i++)l[i]=read(),r[i]=read();
		int ans=0;
		memset(val,0,sizeof(ll)*(n+1));
		for(int i=n;i>=1;i--)
		{
			if(val[i]<l[i])ans++,val[i]=r[i];
			val[i]=min(val[i],(ll)r[i]);
			val[p[i]]+=val[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}