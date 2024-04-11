# include <cstdio>
# include <cassert>
# define ld long double
const int MN = 2e5 + 44;
const ld inf = 1e22;
ld dp[2][MN];
int input[MN];
long long presum[MN]; //suma od 0 do i - 1
ld invsum[MN];
ld tr1sum[MN], tr2sum[MN];
ld rescou(int l, int r) //na przedziale <l, r>
{
	return tr1sum[l] + tr2sum[r + 1] - invsum[r + 1] * presum[l];
}
void update(ld pre[], ld curr[], int ledge, int redge, int lsplbound = 0, int rsplbound = MN)
{
	if (ledge > redge)
		return;
	int mid = (ledge + redge) / 2;
	ld res = inf;
	int where = -1;
	for (int i = lsplbound; i <= rsplbound && i <= mid; ++i)
	{
		ld val = pre[i] + rescou(i, mid - 1);
		if (val < res)
		{
			res = val;
			where = i;
		}
	}
	assert(where != -1);
	curr[mid] = res;
	update(pre, curr, ledge, mid - 1, lsplbound, where);
	update(pre, curr, mid + 1, redge, where, rsplbound);
}
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", input + i);
	for (int i = 0; i < n; ++i)
	{
		presum[i + 1] = presum[i] + input[i];
		invsum[i + 1] = invsum[i] + 1 / (long double) input[i];
	}
	long long allsum = 0;
	ld invsumvar = 0;
	tr1sum[0] = tr2sum[0] = invsum[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		tr1sum[i + 1] = tr1sum[i] + invsumvar * input[i];
		allsum += input[i];
		invsumvar += 1 / (long double) input[i];
		tr2sum[i + 1] = tr2sum[i] + allsum / (long double) input[i];
	}
// 	for (int i = 0; i <= n; ++i)
// 		for (int k = i - 1; k <= n; ++k)
// 			printf("%d %d -> %lf\n", i, k, (double) rescou(i, k));
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i)
		dp[0][i] = inf;
	for (int i = 0; i < k; ++i)
	{
		update(dp[i % 2], dp[(i + 1) % 2], 0, n);
// 		printf("with %d segments\n", i + 1);
// 		for (int x = 0; x <= n; ++x)
// 			printf("%d -> %lf\n", x, (double)dp[(i + 1) % 2][x]);
	}
	printf("%.6lf\n", (double) dp[k % 2][n]);
}