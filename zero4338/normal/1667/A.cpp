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
const int maxn=5e3+5;
int n;
ll a[maxn],b[maxn];
ll ans;
int main()
{
	generate_n(a+1,n=read(),read);
	ans=1e18;
	for(int i=1;i<=n;i++)
	{
		b[i]=0;
		ll cur=0;
		for(int j=i-1;j>=1;j--)
		{
			cur+=(b[j+1]/a[j]+1);
			b[j]=(b[j+1]/a[j]+1)*a[j];
		}
		for(int j=i+1;j<=n;j++)
		{
			cur+=(b[j-1]/a[j]+1);
			b[j]=(b[j-1]/a[j]+1)*a[j];
		}
		ans=min(ans,cur);
	}
	printf("%lld\n",ans);
	return 0;
}