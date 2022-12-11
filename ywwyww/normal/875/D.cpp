#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
int a[200010];
int f[200010];
int g[200010];
int main()
{
//	freopen("f.in","r",stdin);
//	freopen("f.out","w",stdout);
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++)
	{
		f[i]=i;
		while(f[i]>1&&(a[f[i]-1]|a[i])==a[i])
			f[i]=f[f[i]-1];
	}
	for(i=n;i>=1;i--)
	{
		g[i]=i;
		while(g[i]<n&&a[g[i]+1]!=a[i]&&(a[g[i]+1]|a[i])==a[i])
			g[i]=g[g[i]+1];
	}
	ll ans=0;
	for(i=1;i<=n;i++)
		ans+=ll(i-f[i]+1)*(g[i]-i+1);
	ans=ll(n)*(n+1)/2-ans;
	printf("%I64d\n",ans);
	return 0;
}