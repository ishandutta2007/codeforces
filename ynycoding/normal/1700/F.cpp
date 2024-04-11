#include <cstdio>
#include <algorithm>
#define ll long long
const int N=200005;
int n, a[2][N], c[2], tot;
ll ans;
int main()
{
	scanf("%d", &n);
	for(int t:{0, 1}) for(int i=1; i<=n; ++i) scanf("%d", a[t]+i);
	for(int t:{0, 1}) for(int i=1, x; i<=n; ++i) scanf("%d", &x), a[t][i]-=x;
	for(int i=1; i<=n; ++i)
	{
		for(int t:{0, 1}) if(((a[t][i]>0)^(tot<0))&&a[t][i]) c[t]+=a[t][i], tot+=a[t][i], a[t][i]=0, ans-=i;
		for(int t:{0, 1}) if(((a[t][i]<0)^(tot<0))&&c[t]&&a[t][i]) c[t]+=a[t][i], tot+=a[t][i], a[t][i]=0, ans+=i;
		for(int t:{0, 1}) if(((a[t][i]<0)^(tot<0))&&tot&&a[t][i]) ans+=i+1, c[t^1]+=a[t][i], tot+=a[t][i], a[t][i]=0;
		for(int t:{0, 1}) if(a[t][i]) ans-=i, tot+=a[t][i], c[t]+=a[t][i], a[t][i]=0;
	}
	if(tot) return puts("-1"), 0;
	printf("%lld\n", ans);
	return 0;
}