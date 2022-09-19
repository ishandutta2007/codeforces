# include <cstdio>
const int MN=2*1000*100+53;
int per[MN];
int per2[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; ++i)
		scanf("%d", per+i);
	for (int i=1; i<=n; ++i)
	{
		int x;
		scanf("%d", &x);
		per2[x]=i;
	}
	int last=0;
	for (int i=1; i<=n; ++i)
	{
		int to = per2[per[i]];
		if (to<last)
		{
			printf("%d\n", n-i+1);
			return 0;
		}
		last = to;
	}
	printf("%d\n", 0);
}