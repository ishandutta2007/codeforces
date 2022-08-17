#include <cstdio>
#include <cstring>
using namespace std;

const int N = 150;

char buf[N];

const int MOD = 1000*1000*1000 + 7;

typedef long long llong;

llong pow2(int n)
{
	if (n == 0)
		return 1;
	llong ans = 1;
	for (int i = 0; i < n; i++)
		ans = (ans * 2) % MOD;
	return ans;
}

llong C(int q)
{
	return pow2(q - 1) * (pow2(q) - 1) % MOD;
}

int main()
{
	int n;
	gets(buf);
	n = strlen(buf);
	int s = 0;
	for (int i = 0; i < n; i++)
		s += buf[i] == '0';
	int ans = 0;
	if (s == n)
		ans = 0;
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (buf[i] == '1')
			{
				ans = (ans + pow2(i) * pow2(2 * n - 2 * i - 2)) % MOD;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}