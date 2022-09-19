# include <cstdio>
# include <set>
using namespace std;
const int MV = 1e7 + 44;
int div[MV];
int cou[MV];
int main()
{
	for (int p = 2; p < MV; ++p)
		if (div[p] == 0)
			for (int k = p; k < MV; k += p)
				div[k] = p;
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int x;
		scanf("%d", &x);
		while (x > 1)
		{
			int p = div[x];
			while (x % p == 0)
				x /= p;
			cou[p] ++;
		}
	}
	for (int i = 1; i < MV; ++i)
		cou[i] += cou[i - 1];
	int m;
	scanf("%d", &m);
	while (m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", cou[min(r, MV - 1)] - cou[min(l - 1, MV - 1)]);
	}
}