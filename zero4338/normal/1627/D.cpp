#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e6+5;
int n,a[maxn],mx;
bool vis[maxn];
int ans;
int main()
{
	generate_n(a+1,n=read(),read);
	sort(a+1,a+n+1);n=unique(a+1,a+n+1)-(a+1);
	for(int i=1;i<=n;i++)vis[a[i]]=1;
	for(int i=1;i<=n;i++)mx=max(mx,a[i]);
	for(int i=1;i<=mx;i++)
	{
		int d=0;
		for(int j=i;j<=mx;j+=i)
			if(vis[j])d=__gcd(d,j);
		ans+=(d==i);
	}
	ans-=n;
	printf("%d\n",ans);
	return 0;
}