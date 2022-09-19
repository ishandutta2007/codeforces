# include <cstdio>
# include <vector>
using namespace std;
const int MN = 111;
vector <int> graph[MN];
pair <int, int> furthest(int x, int y = -1)
{
	pair <int, int> ret = make_pair(0, x);
	for (auto v : graph[x])
		if (v != y)
			ret = max(ret, furthest(v, x));
	if (y != -1)
		ret.first++;
	return ret;
}
int main()
{
	FILE * in = fopen("input.txt", "r"), *out = fopen("output.txt", "w");
	int t;
	fscanf(in, "%d", &t);
	int res = 0;
	while (t--)
	{
		int n;
		fscanf(in, "%d", &n);
		for (int i = 0; i < n - 1; ++i)
		{
			int a, b;
			fscanf(in, "%d%d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		res += furthest(furthest(1).second).first;
		for (int i = 1; i <= n; ++i)
			graph[i].clear();
	}
	fprintf(out, "%d\n", res);
	fclose(in);
	fclose(out);
}