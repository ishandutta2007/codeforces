# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 1 << 19;
int segments[MN][2];
pair <int, int> temp[MN];
int tree[MN * 2];
void add(int pos, int val)
{
	pos += MN;
	while (pos)
	{
		tree[pos] += val;
		pos /= 2;
	}
}
int read(int l, int r, int wh = 1, int lb = 0, int rb = MN - 1)
{
	if (l > rb || r < lb)
		return 0;
	else if (l <= lb && r >= rb)
		return tree[wh];
	else
		return read(l, r, wh * 2, lb, (lb + rb) / 2) + read(l, r, wh * 2 + 1, (lb + rb) / 2 + 1, rb);
}
void rnr(int arr[], int len)
{
	for (int i = 0; i < len; ++i)
		temp[i] = make_pair(arr[i], i);
	sort(temp, temp + len);
	int nr = 0;
	for (int i = 0; i < len; ++i)
	{
		if (i && temp[i].first != temp[i - 1].first)
			nr++;
		arr[temp[i].second] = nr;
	}
}
pair <pair <int, int>, int> segments2[MN];
int ans[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &segments[i][0], &segments[i][1]);
	rnr(segments[0], n * 2);
	for (int i = 0; i < n; ++i)
		segments2[i] = make_pair(make_pair(segments[i][0], segments[i][1]), i);
	sort(segments2, segments2 + n);
	for (int i = n - 1; i >= 0; --i)
	{
		ans[segments2[i].second] = read(0, segments2[i].first.second);
		add(segments2[i].first.second, +1);
	}
	for (int i = 0; i < n; ++i)
		printf("%d\n", ans[i]);
}