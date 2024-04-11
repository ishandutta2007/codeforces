#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 200005
int T, n, k, h[N], l, r;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &k);
		for(int i=1; i<=n; ++i) scanf("%d", h+i);
		l=r=h[1];
		for(int i=2; i<=n; ++i)
		{
			l=std::max(h[i], l-k+1);
			r=std::min(h[i]+k-1, r+k-1);
			if(l>r) { puts("NO"); goto out; }
		}
		if(l>h[n]) puts("NO");
		else puts("YES");
		out:;
	}
	return 0;
}