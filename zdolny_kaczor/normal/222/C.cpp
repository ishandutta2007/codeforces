# include <cstdio>
# include <vector>
using namespace std;
const int MV = 1e7 + 44, MN = 1e5 + 44;
int div[MV];
int a[MN], b[MN];
vector <int> inv[MV];
void add(int x, int id)
{
	while (x > 1)
	{
		inv[div[x]].push_back(id);
		x /= div[x];
	}
}
int main()
{
	for (int p = 2; p < MV; ++p)
		if (div[p] == 0)
			for (int k = p; k < MV; k += p)
				div[k] = p;
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	for (int i = 0; i < m; ++i)
		scanf("%d", b + i);
	for (int i = 0; i < m; ++i)
		add(b[i], i);
// 	for (int i = 0; i < MV; ++i)
// 		for (auto d : inv[i])
// 			printf("%d divs sth in %d\n", i, d);
	for (int i = 0; i < n; ++i)
	{
		int x = a[i];
// 		printf("x = %d\n", x);
		while (x > 1)
		{
			int p = div[x];
// 			printf("p = %d\n", p);
			if (!inv[p].empty())
			{
				a[i] /= p;
				b[inv[p].back()] /= p;
				inv[p].pop_back();
			}
			x /= p;
		}
	}
	printf("%d %d\n", n, m);
	for (int i = 0; i < n; ++i)
		printf("%d ", a[i]);
	printf("\n");
	for (int i = 0; i < m; ++i)
		printf("%d ", b[i]);
	printf("\n");
}