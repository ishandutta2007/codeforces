#include <cstdio>
#include <algorithm>
#define MAXN 200001
int n, k, a[MAXN], cnt[MAXN], mid, mx;
bool check(void)
{
	int ans=0;
	for(int i=1; i<=mx; ++i) ans+=(cnt[i]/mid);
	if(ans>=k) return 1;
	return 0;
}
void query(int ans)
{
	for(int i=1, cur=0; i<=mx; ++i)
	{
		int ti=cnt[i]/ans;
		for(int j=cur+1; j<=cur+ti&&j<=k; ++j) printf("%d ", i);
		cur+=ti;
		if(cur>=k) return;
	}
}
int main()
{
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), mx=std::max(a[i], mx), ++cnt[a[i]];
	int l=0, r=n;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(check()) l=mid;
		else r=mid-1;
	}
	query(l);
	return 0;
}