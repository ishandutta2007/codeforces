#include <cstdio>
#include <algorithm>
#define ll long long
#define MAXN 200001
int n, ans, idx[MAXN], stk[MAXN];
ll a[MAXN], sum;
bool cmp(int x, int y) { return  a[x]<a[y]; }
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%lld", a+i), sum+=a[i], idx[i]=i;
	std::sort(idx+1, idx+n+1, cmp);
	for(int i=1; i<n; ++i)
		if(sum-a[idx[i]]==a[idx[n]]*2) stk[++ans]=idx[i];
	if(sum-a[idx[n]]==a[idx[n-1]]*2) stk[++ans]=idx[n];
	printf("%d\n", ans);
	for(int i=1; i<=ans; ++i) printf("%d ", stk[i]);
	return 0;
}