# include <cstdio>
const int MN = 1e6 + 44;
int cou[MN];
int arr[MN];
int divcou[MN];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", arr + i);
		if (arr[i] <= m)
			cou[arr[i]]++;
	}
	for (int i = 1; i < MN; ++i)
		for (int k = i; k < MN; k += i)
			divcou[k] += cou[i];
	int M = 0, wh = 1;
	for (int i = 1; i <= m; ++i)
		if (divcou[i] > M)
		{
			M = divcou[i];
			wh = i;
		}
	printf("%d %d\n", wh, M);
	for (int i = 0; i < n; ++i)
		if (wh % arr[i] == 0)
			printf("%d ", i + 1);
}