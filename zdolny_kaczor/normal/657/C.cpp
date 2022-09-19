# include <cstdio>
# include <set>
# include <algorithm>
using namespace std;
# define div aoenth
const int MOD = 5;
const int MN = 2e5 + 44;
const long long llinf = 1LL << 61;
multiset <long long> poss[MOD];
long long sum[MOD];
int n, k, add1, add5;
int modulo(int a, int b)
{
	if (a % b < 0)
		return a % b + b;
	else
		return a % b;
}
int div(int a, int b)
{
	if (a % b < 0)
		return a / b - 1;
	else
		return a / b;
}
void add(int x)
{
// 	printf("add %d\n", x);
	for (int i = 0; i < MOD; ++i)
	{
		long long ins = modulo(i - x, MOD) * add1 - (div(x - i,  MOD) + (((x - i) % MOD == 0) ? 0 : 1)) * (long long) add5;
// 		printf("i = %d ins = %d\n", i, ins);
		if (poss[i].size() < k)
		{
			poss[i].insert(ins);
			sum[i] += ins;
		}
		else
		{
			auto del = poss[i].end();
			del--;
// 			printf("rem %d\n", *del);
			sum[i] -= *del;
			poss[i].erase(del);
			sum[i] += ins;
			poss[i].insert(ins);
		}
// 		printf("leave sum = %I64d\n", sum[i]);
	}
}
long long dist(int a)
{
// 	printf("dist %d\n", a);
	if (poss[modulo(a ,MOD)].size() < k)
		return llinf;
	else
		return sum[modulo(a, MOD)] + div(a, MOD) * ((long long) add5) * k;
}
pair <int, bool> todo[MN * (MOD + 1)];
int main()
{
// 	printf("%d\n", div(-1, 2));
	scanf("%d%d%d%d", &n, &k, &add5, &add1);
	add5 = min(add5, 5 * add1);
	//increment all by 100
	for (int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		todo[i * (MOD + 1)] = make_pair(x, false);
		for (int k = 0; k < MOD; ++k)
			todo[i * (MOD + 1) + k + 1] = make_pair(x + k, true);
	}
	sort(todo, todo + n * (MOD + 1));
	long long res = llinf;
	for (int i = 0; i < n * (MOD + 1); ++i)
		if (todo[i].second)
			res = min(res, dist(todo[i].first));
		else
			add(todo[i].first);
	printf("%I64d\n", res);
}