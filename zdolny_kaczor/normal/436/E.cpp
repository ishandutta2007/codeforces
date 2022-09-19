# include <cstdio>
# include <set>
# include <cstring>
using namespace std;
const int MN = 3e5 + 44;
const int inf = 1e9 + 44;
class mapwithmax
{
private: 
	int fun[MN];
	set <pair <int, int> > finv;
public:
	mapwithmax()
	{
		memset(fun, 0, MN);
	}
	pair <int, int> min()
	{
		return make_pair(finv.begin() -> second, finv.begin() -> first);
	}
	void edit(int a, int b)
	{
		finv.erase(make_pair(fun[a], a));
		fun[a] = b;
		finv.insert(make_pair(fun[a], a));
	}
	void remove(int a)
	{
		finv.erase(make_pair(fun[a], a));
	}
	bool empty()
	{
		return finv.empty();
	}
};
mapwithmax plus1, plus2, minus1;
int one[MN], two[MN];
int state[MN];
void insert(int x)
{
	switch(state[x])
	{
		case 0:
			plus1.edit(x, one[x]);
			plus2.edit(x, two[x]);
		break;
		case 1:
			minus1.edit(x, -one[x]);
			plus1.edit(x, two[x] - one[x]);
		break;
		case 2:
			minus1.edit(x, -two[x] + one[x]);
		break;
	}
}
void remove(int x)
{
	plus1.remove(x);
	plus2.remove(x);
	minus1.remove(x);
}
int main()
{
	int n, w;
	long long res = 0;
	scanf("%d%d", &n, &w);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", one + i, two + i);
	for (int i = 0; i < n; ++i)
	{
		plus1.edit(i, one[i]);
		plus2.edit(i, two[i]);
	}
	for (int i = 0; i < w; ++i)
	{
		pair <int, int> addval = plus1.min();
		pair <int, pair <int, int> > addandremval;
		bool poss = !(plus2.empty() || minus1.empty());
		pair <int, int> add2 = plus2.empty() ? make_pair(inf, inf) : plus2.min();
		pair <int, int> del = minus1.empty() ? make_pair(inf, inf) : minus1.min();
		if (!poss || (add2.second + del.second > addval.second))
		{
			res += addval.second;
			remove(addval.first);
			state[addval.first]++;
			insert(addval.first);
		}
		else
		{
			res += add2.second + del.second;
			remove(add2.first);
			state[add2.first] += 2;
			insert(add2.first);
			remove(del.first);
			state[del.first]--;
			insert(del.first);
		}
	}
	printf("%I64d\n", res);
	for (int i = 0; i < n; ++i)
		printf("%d", state[i]);
	printf("\n");
}