# include <cstdio>
# include <set>
using namespace std;
const long long MR = 1e15 + 44;
const int MN = 1e5 + 44;
const int inf = 7e7 + 44;
const pair <int, int> neutral = make_pair(-inf, 0);
struct vertex
{
	vertex * left, * right;
	pair <int, int> value;
	vertex()
	{
		left = right = NULL;
		value = neutral;
	}
	void show()
	{
		printf("value = (%d, %d)\nl = %016llx r = %016llx\n", value.first, value.second, (long long) left, (long long) right);
	}
};
vertex root;
pair <int, int> read(long long l, long long r, vertex *wh = &root, long long lb = 0, long long rb = MR - 1)
{
// 	if (wh == &root)
// 		printf("read %I64d - %I64d\n", l, r);
	if (wh == NULL || l > rb || r < lb)
		return neutral;
	else if (l <= lb && r >= rb)
		return wh -> value;
	else
		return max(read(l, r, wh -> left, lb, (lb + rb) / 2), read(l, r, wh -> right, (lb + rb) / 2 + 1, rb));
}
void write(long long pos, pair <int, int> val, vertex *wh = &root, long long lb = 0, long long rb = MR - 1)
{
// 	if (wh == &root)
// 	{
// 		printf("write (%d, %d) in %I64d <%I64d, %I64d>\n", val.first, val.second, pos, lb, rb);
// 		wh -> show();
// 	}
	wh -> value = max(wh -> value, val);
	if (lb == rb)
		return;
	if (pos <= (lb + rb) / 2)
	{
		if (wh -> left == NULL)
			wh -> left = new vertex;
		write(pos, val, wh -> left, lb, (lb + rb) / 2);
	}
	else
	{
		if (wh -> right == NULL)
			wh -> right = new vertex;
		write(pos, val, wh -> right, (lb + rb) / 2 + 1, rb);
	}
}
pair <int, int> dp[MN];
long long arr[MN];
int main()
{
	int n, d;
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; ++i)
		scanf("%I64d", arr + i);
	for (int i = n; i > 0; i--)
	{
		pair <int, int> data = max(read(0, arr[i] - d), read(arr[i] + d, MR));
		data = max(data, make_pair(0, -1));
		dp[i] = make_pair(data.first + 1, data.second);
		write(arr[i], make_pair(data.first + 1, i));
	}
	pair <int, int> res = neutral;
	int wh = -1;
	for (int i = 1; i <= n; ++i)
		if (dp[i] > res)
		{
			res = dp[i];
			wh = i;
		}
	printf("%d\n%d", res.first, wh);
	int pos = res.second;
	while (pos != -1)
	{
		printf(" %d", pos);
		pos = dp[pos].second;
	}
	printf("\n");
}