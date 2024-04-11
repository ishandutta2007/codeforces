# include <cstdio>
# include <algorithm>
const int MN = 1e5 + 44;
int a[MN];
std::pair <int, int> pos[MN];
int main()
{
	int n;
	long long k;
	scanf("%d%I64d", &n, &k);
	long long sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", a + i);
		pos[i] = std::make_pair(a[i], i);
		sum += a[i];
	}
	if (sum < k)
	{
		printf("-1\n");
		return 0;
	}
	if (sum == k)
		return 0;
	std::sort(pos + 1, pos + n + 1);
	int currentturn = 0;
	int i = 1;
	int left = n;
	while (k >= 0)
	{
		int nextturn = pos[i].first;
// 		printf("nextturn = %d\n", nextturn);
		if ((nextturn - currentturn) * (long long)left > k)
		{
			int turnsleft = k / left;
			int lastturn = k % left;
			int start;
			for (start = 1; lastturn > 0; ++start)
			{
				if (a[start] != -1)
					lastturn--;
				if (a[start] == currentturn + turnsleft + 1)
					a[start] = -1;
			}
			int i = start;
			do
			{
				if (a[i] != -1)
					printf("%d ", i);
				i = i % n + 1;
			}
			while (i != start);
			return 0;
		}
		k -= (nextturn - currentturn) * (long long) left;
		currentturn = nextturn;
		for (; i <= n && pos[i].first == nextturn; ++i, left--)
		{
// 			printf("i = %d\n", i);
			a[pos[i].second] = -1;
		}
	}
}