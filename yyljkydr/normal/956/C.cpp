#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

int n,a[N],f[N],g[N];

long long ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)
		f[i]=max(f[i+1]-1,a[i]+1);
	for(int i=1;i<=n;i++)
		g[i]=max(g[i-1],f[i]),ans+=g[i]-a[i]-1;
	printf("%lld",ans);
}