# include <cstdio>
# include <vector>
# include <cstdlib>
# include <algorithm>
using namespace std;
const int MN = 2e5 + 44;
vector <int> graf[MN];
vector <int> order;
char state[MN];
void err()
{
	printf("-1\n");
	exit(0);
}
void adde(int a, int b)
{
// 	printf("adde %d %d\n", a, b);
	if (a == -1 || b == -1)
		return;
	graf[b].push_back(a);
}
int cou;
int makenew()
{
// 	printf("alloc %d\n", cou);
	return cou++;
}
const char in_progress = 1, done = 2;
void dfs(int x)
{
// 	printf("dfs in %d\n", x);
	if (state[x] == in_progress)
		err();
	else if (state[x] == done)
		return;
	state[x] = in_progress;
	for (auto v : graf[x])
	{
// 		printf("%d -> %d\n", x, v);
		dfs(v);
	}
	order.push_back(x);
// 	printf("dfs out %d\n", x);
	state[x] = done;
}
pair <int, int> in[MN];
int main()
{
	int n, m;
	scanf("%d%d", &m, &n);
	cou = n + 1;
	while (m--)
	{
// 		printf("next row\n");
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &in[i].first);
			in[i].second = i;
		}
		sort(in + 1, in + n + 1);
		vector <int> pre;
		int last = -1;
		int bef = -1, aft = -1;
		for (int i = 1; i <= n; ++i)
		{
// 			printf("in %d (pos = %d)\n", in[i].first, in[i].second);
			if (in[i].first != last)
			{
				bef = aft;
				aft = makenew();
				last = in[i].first;
			}
			adde(bef, in[i].second);
			adde(in[i].second, aft);
		}
	}
	for (int i = 1; i <= n; ++i)
		dfs(i);
	for (auto v : order)
		if (v <= n)
			printf("%d ", v);
	printf("\n");
}