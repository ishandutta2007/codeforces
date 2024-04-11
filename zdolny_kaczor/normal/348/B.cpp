# include <cstdio>
# include <vector>
using namespace std;
const long long MA = 1e8 + 44;
const long long LLINF = 1LL << 62;
const int MN = 2e5 + 44;
vector <int> graf[MN];
long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
int lcm(int a, int b)
{
	if (a == 0 || b == 0)
		return 0;
	long long ret = a / gcd(a, b) * b;
	if (ret > MA)
		return 0;
	else
		return ret;
}
int a[MN];
int div[MN];
long long bound[MN];
long long maxcou(int div, long long bound)
{
	if (div == 0)
		return 0;
	else
		return bound / div * div;
}
void dfs(int x, int y = -1)
{
	if (a[x])
	{
		div[x] = 1;
		bound[x] = a[x];
	}
	else
	{
		long long currdiv = 1;
		long long currbound = LLINF;
		int deg = 0;
		for (auto v : graf[x])
			if (v != y)
			{
				deg++;
				dfs(v, x);
				currdiv = lcm(currdiv, div[v]);
				currbound = min(currbound, bound[v]);
			}
// 		printf("in %d currdiv = %I64d currbound = %I64d\n", x, currdiv, currbound);
		div[x] = currdiv * deg;
		if (div [x] > MA)
			div[x] = 0;
		bound[x] = maxcou(currdiv, currbound) * deg;
			//is bounded by sum of a[v] over all vertices v so won't overflow
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < n - 1; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		graf[x].push_back(y);
		graf[y].push_back(x);
	}
	dfs(1);
	long long sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += a[i];
	printf("%I64d\n", sum -= bound[1]);
}