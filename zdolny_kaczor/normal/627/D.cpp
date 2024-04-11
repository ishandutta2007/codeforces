# include <cstdio>
# include <vector>
using namespace std;
int n, k;
const int MN = 2e5 + 44;
vector <int> graf[MN];
struct data
{
	bool isall;
	int inall;
	int inoth;
	data(bool a = true, int b = 0, int c = 0)
	{
		isall = a;
		inall = b;
		inoth = c;
	}
	void expand(bool root)
	{
		if (root)
		{
			if (isall)
			{
				inall++;
			}
			else
			{
				inoth = inall + inoth + 1;
				inall = 0;
			}
		}
		else
		{
			isall = false;
			inall = inoth = 0;
		}
	}
	int res()
	{
		return inall + inoth;
	}
};
data operator* (data a, data b)
{
	return data(a.isall && b.isall, a.inall + b.inall, max(a.inoth, b.inoth));
}
data neu();
data down[MN], up[MN];
int key[MN];
bool state[MN];
void dfsdown(int x, int y = -1)
{
	down[x] = neu;
	for (auto v : graf[x])
		if (v != y)
		{
			dfsdown(v, x);
			down[x] = down[x] * down[v];
		}
	down[x].expand(state[x]);
}
data temp[MN];
data temp2[MN];
void dfsup(int x, int y = -1)
{
	if (y == -1)
		up[x] = neu;
	data start;
	for (int i = 0; i < graf[x].size(); ++i)
		if (graf[x][i] != y)
		{
			temp[i] = start;
			start = start * down[graf[x][i]];
		}
	start = neu;
	for (int i = graf[x].size() - 1; i >= 0; --i)
		if (graf[x][i] != y)
		{
			temp2[i] = start;
			start = start * down[graf[x][i]];
		}
	for (int i = 0; i < graf[x].size(); ++i)
		if (graf[x][i] != y)
		{
			up[graf[x][i]] = temp[i] * temp2[i] * up[x];
			up[graf[x][i]].expand(state[x]);
		}
	for (auto v : graf[x])
		if (v != y)
			dfsup(v, x);
}
bool check(int med)
{
// 	printf("check %d\n", med);
	for (int i = 1; i <= n; ++i)
	{
		state[i] = (key[i] >= med);
// 		printf("state %d = %s\n", i, state[i] ? "true" : "false");
	}
	dfsdown(1);
	dfsup(1);
// 	for (int i = 1; i <= n; ++i)
// 	{
// 		printf("up [%d] = (%5s %d %d)\tdown[%d] = (%5s %d %d)\n", i, up[i].isall ? "true" : "false", up[i].inall, up[i].inoth, i, down[i].isall ? "true" : "false", down[i].inall, down[i].inoth);
// 	}
	bool ret = false;
	for (int i = 1; i <= n; ++i)
		if (up[i].res() >= k || down[i].res() >= k)
			ret = true;
// 	printf("return %s\n", ret ? "true" : "false");
	return ret;
}
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		scanf("%d", key + i);
	for (int i = 1; i < n; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	int low = 0, high = 1e6 + 44;
	int ans = 0;
	while (low <= high)
	{
		int med = (low + high) / 2;
		if (check(med))
		{
			ans = med;
			low = med + 1;
		}
		else
		{
			high = med - 1;
		}
	}
	printf("%d\n", ans);
}