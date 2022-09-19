# include <cstdio>
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n - k; ++i)
		printf("%d ", i);
	int l = n - k, h = n;
	bool down = true;
	while (l <= h)
	{
		if (down)
		{
			printf("%d ", l);
			l++;
			down = false;
		}
		else
		{
			printf("%d ", h);
			h--;
			down = true;
		}
	}
}