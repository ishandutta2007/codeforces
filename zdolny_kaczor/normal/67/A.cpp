# include <cstdio>
# include <set>
using namespace std;
const int MN = 1e3 + 14;
int res[MN];
char diff[MN];
int main()
{
	int n;
	scanf("%d%s", &n, diff);
	for (int x = 0; x < n; ++x)
	{
		for (int i = 0; i < n - 1; ++i)
			if (diff[i] == 'R')
				res[i + 1] = max(res[i + 1], res[i] + 1);
			else if (diff[i] == '=')
				res[i + 1] = max(res[i + 1], res[i]);
		for (int i = n - 1; i >= 0; --i)
			if (diff[i] == 'L')
				res[i] = max(res[i], res[i + 1] + 1);
			else if (diff[i] == '=')
				res[i] = max(res[i], res[i + 1]);
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", res[i] + 1);
}