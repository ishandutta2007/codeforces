#include <cstdio>
#include <algorithm>
const int N=10005;
int n, k, a0[N], a1[N];
int a[N];
inline int ask(int x, int y, int tp)//0 and 1 or
{
	int ret;
	printf("%s %d %d\n", (tp?"or":"and"), x, y);
	fflush(stdout);
	scanf("%d", &ret);
	return ret;
}
int main()
{
	scanf("%d%d", &n, &k);
	for(int i=2; i<=n; ++i) a0[i]=ask(1, i, 0);
	for(int i=2; i<=n; ++i) a1[i]=ask(1, i, 1);
	int t0=ask(2, 3, 0), t1=ask(2, 3, 1);
	a[1]=(t1|a1[2])^t1^(a0[2]|a0[3]);
	for(int i=2; i<=n; ++i) a[i]=a[1]^a0[i]^a1[i];
	std::sort(a+1, a+n+1);
	printf("finish %d\n", a[k]);
	return 0;
}