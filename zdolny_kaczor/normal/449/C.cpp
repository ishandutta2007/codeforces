# include <cstdio>
# include <vector>
# include <set>
const int MN = 1e5 + 44;
int div[MN];
std::set <int> muls[MN];
bool included[MN];
std::vector <std::pair <int, int> > answer;
void erase(int a)
{
	included[a] = true;
	muls[div[a]].erase(a);
}
void ans(int a, int b)
{
	answer.push_back(std::make_pair(a, b));
	erase(a);
	erase(b);
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int p = 2; p <= n; ++p)
		for (int k = p; k <= n; k += p)
			if (div[k] == 0)
				div[k] = p;
	for (int i = n; i >= 2; --i)
		muls[div[i]].insert(i);
	for (int p = n; p >= 2; --p)
	{
		if (muls[p].size() == 0)
			continue;
		if (muls[p].size() == 1)
		{
			if (p * 2 <= n)
				ans(p, p * 2);
		}
		else
		{
			if (muls[p].size() % 2 == 1 && p != 2)
				ans(p, p * 2);
			while (muls[p].size() >= 2)
			{
				auto a = muls[p].begin();
				int x = *a;
				a ++;
				int y = *a;
				ans(x, y);
			}
		}
	}
	printf("%d\n", (int) answer.size());
	for (auto x : answer)
		printf("%d %d\n", x.first, x.second);
}