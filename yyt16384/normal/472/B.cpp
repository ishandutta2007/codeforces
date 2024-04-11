#include <algorithm>
#include <cstdio>
#include <functional>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXN=2005;
int n,k;
int f[MAXN];
void init()
{
	scanf("%d%d",&n,&k);
	for (int i=0;i<n;++i)
	{
		scanf("%d",&f[i]);
		--f[i];
	}
}
void solve()
{
	int ans=0;
	std::sort(f,f+n,std::greater<int>());
	for (int i=0;i<n;i+=k)
		ans+=2*f[i];
	printf("%d\n",ans);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}