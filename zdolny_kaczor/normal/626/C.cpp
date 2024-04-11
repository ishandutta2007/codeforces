# include <cstdio>
int n, m;
bool poss(int h)
{
	int two = h / 2;
	int thr = h / 3;
	int both = h / 6;
	return two >= n && thr >= m && two + thr - both >= m + n;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; ; ++i)
		if (poss(i))
		{
			printf("%d\n", i);
			return 0;
		}
}