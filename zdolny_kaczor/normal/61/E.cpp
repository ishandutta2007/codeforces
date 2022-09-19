# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 1e6 + 44;
int tree[MN];
void add(int x)
{
// 	printf("add %d\n", x);
	x++;
	while (x < MN)
	{
		tree[x] ++;
		x += x & -x;
	}
}
int read(int x)
{
// 	printf("read %d ", x);
	x++;
	int res = 0;
	while (x)
	{
		res += tree[x];
		x -= x & -x;
	}
// 	printf(" = %d\n", res);
	return res;
}
void reset()
{
// 	printf("reset\n");
	for (int i = 0; i < MN; ++i)
		tree[i] = 0;
}
pair <int, int> arr[MN];
int bef[MN], aft[MN];
void calc(int n, int res[])
{
	sort(arr, arr + n);
	for (int i = 0; i < n; ++i)
	{
		res[arr[i].second] = read(arr[i].second);
		add(arr[i].second);
	}
	reset();
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		arr[i] = make_pair(-x, i);
	}
	calc(n, bef);
	for (int i = 0; i < n; ++i)
	{
		arr[i].second = n - 1 - arr[i].second;
		arr[i].first *= -1;
	}
	calc(n, aft);
	long long res = 0;
	for (int i = 0; i < n; ++i)
	{
// 		printf("%d * %d\n", bef[i], aft[n - i - 1]);
		res += bef[i] * (long long) aft[n - i - 1];
	}
	printf("%I64d\n", res);
}