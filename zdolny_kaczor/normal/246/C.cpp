# include <cstdio>
# include <map>
using namespace std;
map <int, long long> poss;
map <int, long long> poss2;
const int MN = 55;
int a[MN];
int main()
{
	int n, count;
	scanf("%d%d", &n, &count);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	poss[0] = 0;
	for (int i = 0; i < n; ++i)
	{
		poss2 = poss;
		for (auto x : poss2)
			poss[x.first + a[i]] = x.second | (1ll << i);
		if (poss.size() > count)
			for (auto x : poss)
				if (x.first)
				{
					printf("%d", __builtin_popcountll(x.second));
					for (int k = 0; k <= i; ++k)
						if (x.second & (1ll << k))
							printf(" %d", a[k]);
					printf("\n");
					count--;
					if (count == 0)
						return count;
				}
	}
}