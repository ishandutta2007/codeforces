# include <cstdio>
# include <set>
# include <vector>
using namespace std;
const int MN = 2e5 + 44;
int u[MN];
void init()
{
	for (int i = 0; i < MN; ++i)
		u[i] = i;
}
int find(int x)
{
	if (u[x] == x)
		return x;
	else
		return u[x] = find(u[x]);
}
void unite(int a, int b)
{
	u[find(a)] = find(b);
}
set <int> left;
int main()
{
	int n, q;
	scanf("%d%d", &n, &q);
	init();
	for (int i = 1; i < n; ++i)
		left.insert(i);
	for (int i = 0; i < q; ++i)
	{
		int t, a, b;
		scanf("%d%d%d", &t, &a, &b);
		if (t == 1)
		{
			unite(a, b);
		}
		else if (t == 2)
		{
			vector <int> done;
			for (auto it = left.lower_bound(a); it != left.end() && *it < b; it++)
			{
				unite(*it, *it + 1);
				done.push_back(*it);
			}
			for (int x : done)
				left.erase(x);
		}
		else if (t == 3)
		{
			if (find(a) == find(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}