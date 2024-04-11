#include <algorithm>
#include <cstdio>
#include <functional>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXN=300005;
int n;
int a[MAXN];
void init()
{
	scanf("%d",&n);
	for (int i=0;i<n;++i) scanf("%d",&a[i]);
}
void solve()
{
	long long ans=0;
	long long sum=0;
	std::sort(a,a+n,std::greater<int>());
	for (int i=0;i<n;++i)
	{
		sum+=a[i];
		if (i>0) ans+=sum;
		if (i==n-1) ans+=sum;
	}
	printf(LLFORMAT"d\n",ans);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}