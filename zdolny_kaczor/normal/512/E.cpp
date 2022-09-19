# include <cstdio>
# include <cassert>
# include <vector>
# include <algorithm>
using namespace std;
const int MN = 1e3 + 44;
struct triangulation
{
	bool is[MN][MN];
	int n;
	void init(int n_, vector <pair <int, int> > arr)
	{
		n = n_;
		for (int i = 1; i <= n; ++i)
			for (int k = 1; k <= n; ++k)
				is[i][k] = false;
		for (auto e : arr)
			is[e.first][e.second] = is[e.second][e.first] = true;
		for (int i = 1; i < n; ++i)
			is[i][i + 1] = is[i + 1][i] = true;
		is[1][n] = is[n][1] = true;
	}
	void show()
	{
		printf("This is me:\n");
		for (int i = 1; i <= n; ++i)
			for (int k = i; k <= n; ++k)
				if (is[i][k])
					printf("%d %d\n", i, k);
		printf("The one who can\'t be free\n");
	}
	void read(int n)
	{
		vector <pair <int, int> > in;
		for (int i = 0; i < n - 3; ++i)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			in.push_back(make_pair(a, b));
			init(n, in);
		}
	}
	pair <int, int> rotate(int a, int b)
	{
// 		printf("rotate %d %d\n", a, b);
		assert(is[a][b]);
		int c = -1, d = -1;
		for (int i = 1; i <= n; ++i)
			if (is[a][i] && is[b][i])
			{
				if (c == -1)
					c = i;
				else
					d = i;
			}
		is[a][b] = is[b][a] = false;
		is[c][d] = is[d][c] = true;
// 		show();
		return make_pair(c, d);
	}
	void insert(int l, int r, vector <pair <int, int> > &res, bool inv)
	{
// 		printf("insert %d %d\n", l, r);
		if (l + 1 == r)
			return;
		if (is[l][r])
		{
// 			printf("case 1\n");
			pair <int, int> oth = rotate(l, r);
			if (inv)
				res.push_back(oth);
			else
				res.push_back(make_pair(l, r));
			int a = oth.first == 1 ? oth.second : oth.first;
			insert(l, a, res, inv);
			insert(a, r, res, inv);
		}
		else
		{
// 			printf("case 2\n");
			int last = l;
			for (int i = l + 1; i < r; ++i)
				if (is [1][i])
				{
					insert(last, i, res, inv);
					last = i;
				}
			insert(last, r, res, inv);
		}
	}
	vector <pair <int, int> > solve(bool inv)
	{
		vector <pair <int, int> > ret;
		insert(2, n, ret, inv);
		if (inv)
			reverse(ret.begin(), ret.end());
		return ret;
	}
};
void show(vector <pair <int, int> > a)
{
	for (auto x : a)
		printf("%d %d\n", x.first, x.second);
}
int main()
{
	int n;
	scanf("%d", &n);
	triangulation start, end;
	start.read(n);
	end.read(n);
// 	start.show();
	vector <pair <int, int> > r1 = start.solve(false);
	
	vector <pair <int, int> > r2 = end.solve(true);
	printf("%d\n", (int)(r1.size() + r2.size()));
	show(r1);
	show(r2);
}