#include <algorithm>
#include <cstdio>
#include <functional>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXN=100005;
int n,k;
int s[26];
void init()
{
	static char a[MAXN];
	scanf("%d%d%s",&n,&k,a);
	for (int i=0;i<n;++i) ++s[a[i]-'A'];
}
void solve()
{
	long long ans=0;
	std::sort(s,s+26,std::greater<int>());
	for (int i=0;i<26;++i)
		if (k>s[i])
		{
			ans+=(long long)s[i]*s[i];
			k-=s[i];
		}
		else
		{
			ans+=(long long)k*k;
			break;
		}
	printf(LLFORMAT"d\n",ans);
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