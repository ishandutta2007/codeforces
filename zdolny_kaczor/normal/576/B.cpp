# include <cstdio>
# include <vector>
using namespace std;
const int MN = 1e5 + 44;
int p[MN];
vector <vector <int> > cycles;
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", p + i);
	for (int i = 1; i <= n; ++i)
		if (p[i])
		{
			int wh = i;
			cycles.push_back(vector <int> ());
			do
			{
				int next = p[wh];
				cycles.back().push_back(wh);
				p[wh] = 0;
				wh = next;
			}
			while (wh != i);
		}
	bool odd = false;
	for (auto x : cycles)
	{
		if (x.size() % 2 == 1)
			odd = true;
		if (x.size() == 1)
		{
			printf("YES\n");
			int a = x[0];
			for (int i = 1; i <= n; ++i)
				if (i != a)
					printf("%d %d\n", a, i);
			return 0;
		}
	}
	if (!odd)
		for (auto x : cycles)
			if (x.size() == 2)
			{
				printf("YES\n");
				printf("%d %d\n", x[0], x[1]);
				for (auto y : cycles)
					if (x != y)
					{
						int pos = 0;
						for (auto z : y)
						{
							printf("%d %d\n", x[pos], z);
							pos^= 1;
						}
					}
				return 0;
			}
	printf("NO\n");
}