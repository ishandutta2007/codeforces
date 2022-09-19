# include <cstdio>
# include <vector>
using namespace std;
const int MN = 1e5 + 44;
vector <int> divs[MN];
int last[MN];
int main()
{
	for (int i = 1; i < MN; ++i)
		for (int k = i; k < MN; k += i)
			divs[k].push_back(i);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		int res = 0;
		for (auto d : divs[x])
		{
			if (last[d] < i - y)
				res++;
			last[d] = i;
		}
		printf("%d\n", res);
	}
}