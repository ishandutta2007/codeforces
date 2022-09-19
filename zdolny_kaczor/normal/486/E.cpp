# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 1 << 17;
int tree[MN * 2];
void reset()
{
	for (int i = 0; i < MN * 2; ++i)
		tree[i] = 0;
}
void edit(int pos, int val)
{
	pos += MN;
	tree[pos] = val;
	pos /= 2;
	while (pos)
	{
		tree[pos] = max(tree[pos * 2], tree[pos * 2 + 1]);
		pos /= 2;
	}
}
int read(int l, int r, int wh = 1, int lb = 0, int rb = MN - 1)
{
	if (l > rb || r < lb)
		return 0;
	if (l <= lb && r >= rb)
		return tree[wh];
	return max(read(l, r, wh * 2, lb, (lb + rb) / 2), read(l, r, wh * 2 + 1, (lb + rb) / 2 + 1, rb));
}
pair <int, int> temp[MN];
int lis(int arr[], int len, int res[], bool inv)
{
	for (int i = 0; i < len; ++i)
		temp[i] = make_pair(arr[i], i);
	reset();
	sort(temp, temp + len, inv ?
		[](pair <int, int> a, pair <int, int> b){return a.first == b.first ? a.second < b.second : a.first > b.first;}
	:
		[](pair <int, int> a, pair <int, int> b){return a.first == b.first ? a.second > b.second : a.first < b.first;}
	);
	for (int i = 0; i < len; ++i)
	{
		int pos = temp[i].second;
// 		printf("in %d\n", pos);
		int dpval = inv ? read(pos, MN - 1) : read(0, pos);
		edit(pos, dpval + 1);
		res[pos] = dpval + 1;
	}
// 	printf("done\n");
}
int arr[MN];
int back[MN], forw[MN];
int cou[MN];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
	lis(arr, n, back, false);
	lis(arr, n, forw, true);
// 	for (int i = 0; i < n; ++i)
// 		printf("%d. b = %d f = %d\n", i, back[i], forw[i]);
	int len = 0;
// 	printf("len = %d\n", len);
	for (int i = 0; i < n; ++i)
		len = max(len, back[i]);
	for (int i = 0; i < n; ++i)
		if (back[i] + forw[i] - 1 == len)
			cou[back[i]] ++;
	for (int i = 0; i < n; ++i)
		if (back[i] + forw[i] - 1 < len)
			printf("1");
		else if (cou[back[i]] == 1)
			printf("3");
		else
			printf("2");
	printf("\n");
}