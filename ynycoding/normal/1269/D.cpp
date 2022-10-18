#include <cstdio>
#define ll long long
#define MAXN 300005
int n, a[MAXN], cur, p=1;
ll ans;
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", a+i);
	for(int i=1; i<=n; ++i)
	{
		int idx=cur*2+p-1;
		if(idx>=a[i]) cur=(a[i]+1-p)/2;
		idx=cur*2+p-1;
		ans+=(a[i]-idx)/2;
		ans+=cur;
		if((a[i]-idx)%2==0) cur?(p?(--p):(--cur, ++p)):(0);
		else cur?(p?(--p, ++cur):(++p)):(cur=1, p=0);
		// printf("%d %d %d %d %lld\n", i, cur, p, idx, ans);
	}
	printf("%lld\n", ans);
	return 0;
}