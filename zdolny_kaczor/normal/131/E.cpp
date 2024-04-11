# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 1e5 + 44;
struct queen
{
	int nr;
	int x;
	int y;
	int coo1;
	int coo2;
	void makecoo(int dir)
	{
		switch(dir)
		{
			case 0:
				coo1 = x + y;
				coo2 = x - y;
			break;
			case 1:
				coo1 = x - y;
				coo2 = x + y;
			break;
			case 2:
				coo1 = x;
				coo2 = y;
			break;
			case 3:
				coo1 = y;
				coo2 = x;
			break;
		}
	}
};
queen a[MN];
int cou[MN];
int ans[9];
bool operator< (queen a, queen b)
{
	return make_pair(a.coo1, a.coo2) < make_pair(b.coo1, b.coo2);
}
int main()
{
	int n;
	scanf("%*d%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
		a[i].nr = i;
	}
	for (int dir = 0; dir < 4; ++dir)
	{
		for (int i = 0; i < n; ++i)
			a[i].makecoo(dir);
		sort(a, a + n);
		for (int i = 0; i < n - 1; ++i)
		{
			if (a[i].coo1 == a[i + 1].coo1)
			{
				cou[a[i].nr]++;
				cou[a[i + 1].nr]++;
			}
		}
	}
	for (int i = 0; i < n; ++i)
		ans[cou[i]]++;
	for (int i = 0; i < 9; ++i)
		printf("%d ", ans[i]);
	printf("\n");
}