#include <cstdio>
#include <algorithm>
const int N=200005;
int T, n, a[N], z;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		int ct=0;
		int is=0;
		for(int i=1; i<=n; ++i)
		{
			scanf("%d", a+i);
			if(!a[i]) ct+=is;
			is=a[i]>0;
		}
		ct+=is;
		printf("%d\n", std::min(2, ct));
	}
	return 0;
}