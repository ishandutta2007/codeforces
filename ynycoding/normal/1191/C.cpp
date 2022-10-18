#include <cstdio>
#define MAXN 100005
#define ll long long
ll m, n, pos[MAXN], k, cur=1, ans;
int main()
{
	scanf("%I64d%I64d%I64d", &m, &n, &k);
	for(int i=1; i<=n; ++i) scanf("%I64d", pos+i);
	for(int i=1, l; i<=n; i=l)
	{
		l=i;
		cur+=(pos[i]-cur)/k*k;
		while(pos[l]<cur+k&&l<=n) ++l;
		++ans;
		cur+=l-i;
	}
	printf("%d", ans);
	return 0;
}