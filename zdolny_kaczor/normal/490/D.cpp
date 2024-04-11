# include <cstdio>
# include <set>
using namespace std;
typedef pair <pair <int, int>, long long> Number;
int div(int &n, int p)
{
	int res = 0;
	while (n % p == 0)
	{
		n /= p;
		res ++;
	}
	return res;
}
int split(int &a, int &b, int two, int three)
{
	for (int i = 0; i < three; ++i)
		if (a % 3 == 0)
			a = a / 3 * 2;
		else
			b = b / 3 * 2;
	for (int i = 0; i < two; ++i)
		if (a % 2 == 0)
			a /= 2;
		else
			b /= 2;
}
Number make(int a, int b)
{
	Number res = make_pair(make_pair(0, 0), 0);
	res.first.first += div(a, 2);
	res.first.first += div(b, 2);
	res.first.second += div(a, 3);
	res.first.second += div(b, 3);
	res.second = a * (long long) b;
	return res;
}
int main()
{
	int a1, a2, b1, b2;
	scanf("%d%d%d%d", &a1, &b1, &a2, &b2);
	Number a = make(a1, b1);
	Number b = make(a2, b2);
	if (a.second != b.second)
		printf("-1\n");
	else
	{
		int a_two = 0, b_two = 0, a_three = 0, b_three = 0;
		int cou = 0;
		if (a.first.second > b.first.second)
		{
			int diff = a.first.second - b.first.second;
			a_three += diff;
			a.first.first += diff;
			cou += diff;
		}
		else if (a.first.second < b.first.second)
		{
			int diff = b.first.second - a.first.second;
			b_three += diff;
			b.first.first += diff;
			cou += diff;
		}
		if (a.first.first > b.first.first)
		{
			int diff = a.first.first - b.first.first;
			a_two += diff;
			cou += diff;
		}
		else if (a.first.first < b.first.first)
		{
			int diff = b.first.first - a.first.first;
			b_two += diff;
			cou += diff;
		}
		printf("%d\n", cou);
		split(a1, b1, a_two, a_three);
		split(a2, b2, b_two, b_three);
		printf("%d %d\n%d %d\n", a1, b1, a2, b2);
	}
}