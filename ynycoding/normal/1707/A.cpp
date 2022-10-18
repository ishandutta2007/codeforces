#include <cstdio>
#include <algorithm>
const int N=100005;
int T, n, q, a[N], ok[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &q);
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		for(int i=n, cur=0; i; --i)
		{
			ok[i]=0;
			if(cur<a[i])
			{
				if(cur<q) ++cur, ok[i]=1;
			}
			else ok[i]=1;
		}
		for(int i=1; i<=n; ++i) putchar('0'+ok[i]);
		puts("");
	}
	return 0;
}