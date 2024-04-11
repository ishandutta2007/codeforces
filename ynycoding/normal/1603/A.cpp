#include <cstdio>
#include <algorithm>
const int N=300005;
int T, n, a[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		for(int i=1; i<=n; ++i)
		{
			for(int j=1; j<=i; ++j) if(a[i]%(j+1)) goto out;
			puts("NO");
			goto out1;
			out:;
		}
		puts("YES");
		out1:;
	}
	return 0;
}