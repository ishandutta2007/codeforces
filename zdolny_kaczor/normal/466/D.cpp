# include <cstdio>
# include <cstdlib>
const int MN = 2e3 + 44;
const int MOD = 1e9 + 7;
void err()
{
	printf("0\n");
	exit(0);
}
int main()
{
	int n, h;
	scanf("%d%d", &n, &h);
	int last = h;
	int left = 0;
	long long res = 1;
	for (int i = 0; i <= n; ++i)
	{
		int curr;
		if (i == n)
			curr = h;
		else
			scanf("%d", &curr);
		if (last == curr)
			res = res * (1 + left) % MOD;
		else if (last == curr - 1) //arrow pointing left
		{
			res = res * left % MOD;
			left--;
		}
		else if (last == curr + 1) //arrow pointing right
			left++;
		else
			err();
		last = curr;
	}
	printf("%d\n", (int) res);
}