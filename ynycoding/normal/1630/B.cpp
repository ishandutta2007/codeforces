#include <cstdio>
#include <algorithm>
const int N=200005;
int T, n, k, a[N], cnt[N], pos[N], top;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &k);
		std::fill(cnt+1, cnt+n+1, 0);
		for(int i=1; i<=n; ++i) scanf("%d", a+i), ++cnt[a[i]];
		top=0;
		int mn=0x3f3f3f3f, x, y;
		for(int l=1, r=1, cur=0; r<=n; ++r)
		{
			cur+=cnt[r];
			while(2*(cur-cnt[l])>=n+k) cur-=cnt[l], ++l;
			if(cur*2>=n+k&&r-l<mn) mn=r-l, x=l, y=r;
		}
		int p=0, cur=0;
		while(top<k-1)
		{
			cur=0;
			while(cur<=0) ++p, cur+=(a[p]>=x&&a[p]<=y)?1:-1;
			pos[++top]=p;
		}
		pos[++top]=n;
		printf("%d %d\n", x, y);
		for(int i=1; i<=top; ++i) printf("%d %d\n", pos[i-1]+1, pos[i]);
	}
	return 0;
}