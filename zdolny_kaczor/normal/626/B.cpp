# include <cstdio>
# include <vector>
using namespace std;
struct state
{
	int cou[3];
	state(int arr[3])
	{
		for (int i = 0; i < 3; ++i)
			cou[i] = arr[i];
	}
};
const int MN = 202;
bool found[MN][MN][MN];
void dfs(state a)
{
	for (int i = 0; i < 3; ++i)
		if (a.cou[i] >= MN)
			return;
	if (found[a.cou[0]][a.cou[1]][a.cou[2]])
		return;
	else
	{
		found[a.cou[0]][a.cou[1]][a.cou[2]] = true;
		for (int i = 0; i < 3; ++i)
			if (a.cou[i])
			{
				state b = a, c = a;
				b.cou[i] ++;
				for (int k = 0; k < 3; ++k)
					c.cou[k]++;
				c.cou[i] -= 2;
				dfs(b);
				dfs(c);
			}
	}
}
int a [] = {1, 0, 0};
int r, g, b;
int main()
{
	dfs(state(a));
// 	printf("done\n");
	int n;
	char cu[MN];
	scanf("%d%s", &n, cu);
	for (int i = 0; i < n; ++i)
		if (cu[i] == 'R')
			r++;
		else if (cu[i] == 'G')
			g++;
		else
			b++;
	if (found[b][r][g])
		putchar('B');
	if (found[g][r][b])
		putchar('G');
	if (found[r][g][b])
		putchar('R');
}