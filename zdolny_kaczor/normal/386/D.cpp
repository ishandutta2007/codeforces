# include <cstdio>
# include <queue>
using namespace std;
const int MN = 75;
char mat[MN][MN];
int n;
struct pos
{
	int a[3];
	pos(int x = 0, int y = 0, int z = 0)
	{
		a[0] = x;
		a[1] = y;
		a[2] = z;
	}
	vector <pair <pos, pair <int, int> > > gen()
	{
// 		for (int i = 0; i < 3; ++i)
// 			printf("%d ", a[i]);
// 		printf("\n");
		vector <pair <pos, pair <int, int> > > res;
		for (int i = 0; i < 3; ++i)
			for (int x = 1; x <= n; ++x)
				if (mat[x][a[i]] == mat[a[(i + 1) % 3]][a[(i + 2) % 3]] && x != a[(i + 1) % 3] && x != a[(i + 2) % 3])
				{
// 					printf("mat[%d][%d] == mat[%d][%d]\n", x, a[i], a[(i + 1) % 3], a[(i + 2) % 3]);
// 					printf("move %d -> %d\n", x, a[i]);
					pos next = *this;
					next.a[i] = x;
					res.push_back(make_pair(next, make_pair(x, a[i])));
				}
		return res;
	}
};
pair <pos, pair <int, int> > via[MN][MN][MN];
queue <pos> kol;
pair <pos, pair <int, int> > & get(pos y)
{
	return via[y.a[0]][y.a[1]][y.a[2]];
}
void ins(pos a)
{
	kol.push(a);
	get(a) = make_pair(pos(), make_pair(-1, -1));
}
int main()
{
	scanf("%d", &n);
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	for (int i = 1; i <= n; ++i)
		scanf("%s", mat[i] + 1);
	ins(pos(1, 2, 3));
	ins(pos(1, 3, 2));
	ins(pos(3, 2, 1));
	ins(pos(3, 1, 2));
	ins(pos(2, 1, 3));
	ins(pos(2, 3, 1));
	while (!kol.empty())
	{
		auto x = kol.front();
		kol.pop();
		auto next = x.gen();
		for (auto z : next)
		{
			auto y = z.first;
			if (get(y).second == make_pair(0, 0))
			{
				get(y) = make_pair(x, z.second);
				kol.push(z.first);
			}
		}
	}
	auto end = pos(a, b, c);
	if (get(end).second == make_pair(0, 0))
		printf("-1\n");
	else
	{
		vector <pair <int, int> > res;
		while (true)
		{
// 			printf("in %d %d %d\n", end.a[0], end.a[1], end.a[2]);
			auto wh = get (end);
			if (wh.second == make_pair(-1, -1))
				break;
			res.push_back(wh.second);
			end = wh.first;
		}
		printf("%d\n", (int) res.size());
		for (auto x : res)
			printf("%d %d\n", x.first, x.second);
	}
}