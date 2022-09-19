# include <cstdio>
# include <algorithm>
const int MN = 1 << 19;
const int INF = 1 << 24;
const int NONE = -1;
using namespace std;
pair <int, int> poses[MN];
pair <int, int> dpt[MN * 2];
void init()
{
	for (int i = 0; i < MN; ++i)
		dpt[i + MN] = make_pair (-INF, 0);
	for (int i = MN - 1; i > 0; --i)
		dpt[i] = max(dpt[i * 2], dpt[i * 2 + 1]);
}
void edit(int pos, int val)
{
	dpt[pos + MN] = make_pair(val, pos);
	pos += MN;
	pos /= 2;
	while (pos)
	{
		dpt[pos] = max(dpt[pos * 2], dpt[pos * 2 + 1]);
		pos /= 2;
	}
}
pair <int, int> read(int l, int r, int wh = 1, int lb = 0, int rb = MN - 1)
{
// 	if (wh == 1)
// 		printf ("read %d %d\n", l, r);
	if (r < lb || l > rb)
		return make_pair(-INF, 0);
	if (l <= lb && r >= rb)
	{
// 		printf("include %d %d (%d = MN + %d) [%d %d]\n", lb, rb, wh, wh - MN, dpt[wh].first, dpt[wh].second);
		return dpt[wh];
	}
	return max(read(l, r, wh * 2, lb, (lb + rb) / 2), read(l, r, wh * 2 + 1, (lb + rb) / 2 + 1, rb));
}
int nextsame[MN];
int jump[MN];
int main()
{
	init();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &poses[i].first);
	for (int i = 0; i < n; ++i)
		poses[i].second = i;
	sort(poses, poses + n);
	for (int i = 0; i < n - 1; ++i)
		if (poses[i].first == poses[i + 1].first)
			nextsame[poses[i].second] = poses[i + 1].second;
		else
			nextsame[poses[i].second] = INF;
	nextsame[poses[n - 1].second] = INF;
// 	for (int i = 0; i < n; ++i)
// 		printf("N[%d] = %d\n", i, nextsame[i]);
	edit(n, 0);
	int minl = n + 1;
	for (int i = n - 1; i >= 0; --i)
	{
		minl = min(minl, nextsame[i] + 1);
// 		printf("%d.%d \n", i, minl);
		pair <int, int> ans = read(minl, n);
// 		printf("read %d %d\n", ans.first, ans.second);
		edit(i, ans.first + 1);
		jump[i] = ans.second;
	}
	if (dpt[MN].first < 0)
		printf("-1\n");
	else
	{
		printf("%d\n", dpt[MN].first);
		int pos = 0;
		while (pos < n)
		{
			int next = jump[pos];
			printf("%d %d\n", pos + 1, next);
			pos = next;
		}
	}
}