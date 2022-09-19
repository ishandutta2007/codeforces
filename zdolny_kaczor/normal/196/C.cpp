# include <cstdio>
# include <vector>
# include <algorithm>
using namespace std;
const int MN = 1515;
typedef pair <pair <int, int>, int> point;
# define x first.first
# define y first.second
# define nr second
vector <int> graph[MN];
int size[MN];
void sizecou(int o, int e = -1)
{
	size[o] = 1;
	for (auto v : graph[o])
		if (v != e)
		{
			sizecou(v, o);
			size[o] += size[v];
		}
}
int ans[MN];
point pivot;
bool angcmp(point a, point b)
{
	return (long long) (a.x - pivot.x) * (b.y - pivot.y) - (long long) (a.y - pivot.y) * (b.x - pivot.x) > 0;
}
void show(point arr[], int len)
{
	for (int i = 0; i < len; ++i)
		printf("((%d, %d), %d)\n", arr[i].first.first, arr[i].first.second, arr[i].second);
	printf("\n");
}
void paint(int root, int forbidden, point arr[], int len)
{
// 	printf("enter %d (%d)\n", root, forbidden);
// 	printf("at first\n");
// 	show(arr, len);
	for (int i = 1; i < len; ++i)
		if (arr[i] < arr[0])
			swap(arr[i], arr[0]);
// 	printf("after choosing leftmost\n");
// 	show(arr, len);
	ans[arr[0].nr] = root;
	pivot = arr[0];
	sort(arr + 1, arr + len, angcmp);
// 	printf("after angsort\n");
// 	show(arr, len);
	int pos = 1;
	for (auto next : graph[root])
		if (next != forbidden)
		{
			paint(next, root, arr + pos, size[next]);
			pos += size[next];
		}
}
point coos[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i)
	{
		int xx, yy;
		scanf("%d%d", &xx, &yy);
		coos[i] = make_pair(make_pair(xx, yy), i);
	}
	sizecou(1, -1);
	paint(1, -1, coos + 1, n);
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	printf("\n");
}