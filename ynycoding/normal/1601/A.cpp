#include <cstdio>
#include <cstring>
#include <algorithm>
int T, n, d, ans, cnt[30];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		d=0;
		memset(cnt, 0, sizeof(cnt));
		for(int i=1, x; i<=n; ++i)
		{
			scanf("%d", &x);
			for(int i=0; i<30; ++i) cnt[i]+=(x>>i)&1;
		}
		for(int i=0; i<30; ++i) d=std::__gcd(d, cnt[i]);
		for(int i=1; i<=(d==0?n:d); ++i) if(d%i==0) printf("%d ", i);
		puts("");
	}
	return 0;
}