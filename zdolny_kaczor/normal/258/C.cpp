# include <cstdio>
# include <vector>
using namespace std;
const int MN = 1e5 + 44;
const int MOD = 1e9 + 7;
vector <int> divs[MN];
void div_init()
{
	for (int i = 1; i < MN; ++i)
		for (int k = i; k < MN; k += i)
			divs[k].push_back(i);
}
long long pow(int base, int exp)
{
	if (exp == 0)
		return 1;
	else if (exp % 2 == 0)
	{
		long long half = pow(base, exp / 2);
		return half * half % MOD;
	}
	else
		return pow(base, exp - 1) * base % MOD;
}
int not_greater_than[MN];
int main()
{
	int n;
	scanf("%d", &n);
	div_init();
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		not_greater_than[x]++;
	}
	for (int i = 1; i < MN; ++i)
		not_greater_than[i] += not_greater_than[i - 1];
	long long res = 0;
	for (int m = 1; m < MN; ++m)
	{
		long long mul = 1;
		int already_found = 0;
		for (int i = 0; i < divs[m].size(); ++i) //includes positions which can have only first i divisors of m
		{
			mul *= pow(i, not_greater_than[divs[m][i] - 1] - already_found);
			mul %= MOD;
			already_found = not_greater_than[divs[m][i] - 1];
		}
		int with_all_possible = n - not_greater_than[m - 1];
		mul *= (pow(divs[m].size(), with_all_possible) - pow(divs[m].size() - 1, with_all_possible));
		mul %= MOD;
		res = (res + mul) % MOD;
	}
	if (res < 0)
		res += MOD;
	printf("%d\n", (int) res);
}