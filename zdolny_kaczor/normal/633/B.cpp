# include <cstdio>
# include <vector>
int aoe(int x)
{
	int res = 0;
	while (x % 5 == 0)
	{
		res ++;
		x /= 5;
	}
	return res;
}
int main()
{
	int n;
	scanf("%d", &n);
	std::vector <int> res;
	int cou = 0;
	for (int i = 1; cou <= n; ++i)
	{
		cou += aoe(i);
		if (cou == n)
			res.push_back(i);
	}
	printf("%d\n", (int) res.size());
	for (auto x : res)
		printf("%d ", x);
}