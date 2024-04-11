# include <cstdio>
# include <cstdlib>
# include <vector>
using namespace std;
const int MN = 3e5 + 44;
int u[MN];
int size_[MN];
int cou;
int left[MN];
int pos[MN];
int find(int a)
{
	if (u[a] == a)
		return a;
	else
		return u[a] = find(u[a]);
}
void unite(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
	{
		size_[a] += size_[b];
		u[b] = a;
		left[pos[b]] = left[cou];
		pos[left[cou]] = pos[b];
		cou --;
	}
}
void init(int n)
{
	cou = n;
	for (int i = 1; i <= n; ++i)
	{
		u[i] = pos[i] = left[i] = i;
		size_[i] = 1;
	}
}
int size(int x)
{
	return size_[find(x)];
}
void err()
{
	printf("impossible\n");
	exit(0);
}
vector <int> graph[MN];
int connections[MN];
int connections_with_one[MN];
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	init(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	if (n - 1 - graph[1].size() < k)
		err();
	for (int i = 2; i < n; ++i)
	{
		for (auto x : graph[i])
			connections[find(x)]++;
		vector <int> to_unite;
		for (int k = 1; k <= cou; ++k)
		{
			int x = left[k];
			if (x != 1 && size(x) != connections[x])
				to_unite.push_back(x);
			connections[x] = 0;
		}
		for (auto x : to_unite)
			unite(x, i);
	}
	if (cou > k + 1)
		err();
	for (int i = 2; i <= n; ++i)
		if (find(i) == i)
			connections_with_one[i] = size(i);
	for (auto v : graph[1])
		connections_with_one[find(v)] --;
	for (int i = 2; i <= n; ++i)
		if (find(i) == i && connections_with_one[i] == 0)
			err();
	printf("possible\n");
}