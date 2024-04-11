# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 1 << 17;
const int ME = 4e5 + 44;
const int inf = 1 << 24;
int tree[MN * 2];
void reset()
{
// 	printf("reset\n");
	for (int i = 0; i < MN * 2; ++i)
		tree[i] = 0;
}
int read(int l, int r, int wh = 1, int lb = 0, int rb = MN - 1)
{
// 	if (wh == 1)
// 		printf("read %d - %d\n", l, r);
	if (l > rb || r < lb)
		return inf;
	else if (l <= lb && r >= rb)
		return tree[wh];
	else
		return min(read(l, r, wh * 2, lb, (lb + rb) / 2), read(l, r, wh * 2 + 1, (lb + rb) / 2 + 1, rb));
}
void edit(int pos, int val)
{
// 	printf("edit %d %d\n", pos, val);
	pos += MN;
	tree[pos] = val;
	pos /= 2;
	while (pos)
	{
		tree[pos] = min(tree[pos * 2], tree[pos * 2 + 1]);
		pos /= 2;
	}
}
const bool add = false, query = true;
struct event
{
	int row;
	bool type;
	union
	{
		struct query_t
		{
			int l, r, bound;
			int nr;
		}
		query;
		struct insert_t
		{
			int pos;
		}
		insert;
	}
	data;
	void invert()
	{
		if (type == add)
			swap(row, data.insert.pos);
		else
		{
			swap(data.query.r, row);
			swap(data.query.l, data.query.bound);
		}
	}
	void show()
	{
		if (type == add)
			printf("ADD %d %d\n", row, data.insert.pos);
		else
			printf("QUERY (%d, %d) x (%d, %d)\n", data.query.bound, row, data.query.l, data.query.r);
	}
};
bool operator< (event a, event b)
{
	return make_pair(a.row, a.type) < make_pair(b.row, b.type);
}
event events[ME];
bool ans[ME];
void serve(int len)
{
	reset();
	sort(events, events + len);
	for (int i = 0; i < len; ++i)
	{
		event curr = events[i];
// 		curr.show();
		if (curr.type == add)
			edit(curr.data.insert.pos, curr.row);
		else
		{
			int readed = read(curr.data.query.l, curr.data.query.r);
// 			printf("readed %d\n", readed);
			ans[curr.data.query.nr] |= (readed >= curr.data.query.bound);
		}
	}
}
int main()
{
	int k, q;
	scanf("%*d%*d%d%d", &k, &q);
	for (int i = 0; i < k; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		events[i].type = add;
		events[i].row = x;
		events[i].data.insert.pos = y;
	}
	for (int i = 0; i < q; ++i)
	{
		int x1, x2, y1, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		events[i + k].type = query;
		events[i + k].row = x2;
		events[i + k].data.query.l = y1;
		events[i + k].data.query.r = y2;
		events[i + k].data.query.bound = x1;
		events[i + k].data.query.nr = i;
	}
	serve(k + q);
	for (int i = 0; i < k + q; ++i)
		events[i].invert();
	serve(k + q);
	for (int i = 0; i < q; i++)
		if (ans[i])
			printf("YES\n");
		else
			printf("NO\n");
}