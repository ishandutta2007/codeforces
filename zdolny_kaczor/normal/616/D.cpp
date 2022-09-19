# include <cstdio>
const int MN = 1e6 + 44;
int cou[MN];
int arr[MN];
int amo = 0;
void add(int x, int val)
{
	if (cou[x])
		amo --;
	cou[x] += val;
	if (cou[x])
		amo ++;
}
int diffamo()
{
	return amo;
}
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
	int res = -13, l, r;
	int head = 0;
	for (int i = 0; i < n; ++i) //<i, head) is k-good but <i, head> isn't or doesn't exist, cou stores segment <i, head)
	{
		while (head < n)
		{
			if (diffamo() == k && cou[arr[head]] == 0)
				break;
			add(arr[head], +1);
			head ++;
		}
		if (head - i >= res)
		{
			res = head - i;
			l = i + 1;
			r = head;
		}
		add (arr[i], -1);
	}
	printf("%d %d\n", l, r);
}