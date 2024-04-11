#include <cstdio>
#include <cmath>
#include <algorithm>
int t, n, pre, cur, ans;
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		pre=-1, ans=0;
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", &cur), (abs(cur-pre)>1&&(~pre))?(ans=i):0, pre=cur;
		if(ans==0) puts("NO");
		else printf("YES\n%d %d\n", ans-1, ans);
	}
	return 0;
}