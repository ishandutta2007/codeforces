# include <cstdio>
# include <set>
using namespace std;
typedef pair <long long, long long> range;
pair <long long, long long> none = make_pair(-1, -1);
long long make_res(range a, range b, long long bound)
{
	return min(min(a.second, b.second), bound - 1) + min(min(a.first, b.first), bound - 1) + 1;
}
pair <range, range> check(long long l, long long r, long long rem, long long mod)
{
	l += mod - rem;
	r += mod - rem;
// 	printf("check %d-%d with mod = %d\n", l, r, mod);
	long long down = (l + mod - 1) / mod, up = r / mod;
// 	printf("up = %d down = %d\n", down, up);
	if (down > up)
	{
// 		printf("case 0\n");
		return make_pair(none, none);
	}
	else if (down == up)
	{
// 		printf("case 1\n");
		pair <long long, long long> all = make_pair(up * mod - l, r - up * mod);
		return make_pair(all, all);
	}
	else if (down + 1 == up)
	{
// 		printf("case 2\n");
		return make_pair(make_pair(down * mod - l, mod - 1), make_pair(mod - 1, r - up * mod));
	}
	else
	{
// 		printf("case 3+\n");
		pair <long long, long long> whole = make_pair(mod - 1, mod - 1);
		return make_pair(whole, whole);
	}
}
void show(pair <range, range> a)
{
	printf("(%d, %d) or (%d, %d)\n", a.first.first, a.first.second, a.second.first, a.second.first);
}
int main()
{
	long long l1, r1, l2, r2;
	scanf("%I64d%I64d%I64d%I64d", &l1, &r1, &l2, &r2);
	long long res = 0;
	for (int i = 0; i < 30; ++i)
	{
		pair <range, range> a = check(l1, r1, (1 << i), (1 << i) << 1);
		pair <range, range> b = check(l2, r2, (1 << i), (1 << i) << 1);
// 		printf("in i = %d\n", i);
// 		show(a);
// 		show(b);
		res = max(res, make_res(a.first, b.first, (1 << i)));
		res = max(res, make_res(a.second, b.second, (1 << i)));
// 		printf("new res = %d\n", res);
	}
	printf("%d\n", res);
}