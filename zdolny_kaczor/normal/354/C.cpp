# include <cstdio>
# include <vector>
using namespace std;
const int MN = 1e6 + 44;
const int MD = 120;
short divs[MN][MD];
int divcou[MN];
int cou[MN];
void init()
{
	for (int i = 1; i * i < MN; ++i)
		for (int k = i * i; k < MN; k += i)
		{
			divs[k][divcou[k]] = i;
			divcou[k] ++;
		}
}
bool to_check_flag[MN];
vector <int> to_check;
bool poss[MN];
bool done;
void edit(int x, int nr)
{
	cou[x] += nr;
	if (done && cou[x] == 0 && !to_check_flag[x])
	{
		to_check.push_back(x);
		to_check_flag[x] = true;;
	}
}
void insert(int x, int nr)
{
// 	printf("insert %d %d\n", x, nr);
	for (int i = 0; i < divcou[x]; ++i)
	{
		edit(divs[x][i], nr);
		if (divs[x][i] * divs[x][i] != x)
			edit(x / divs[x][i], nr);
	}
}
void update()
{
// 	printf("update\n");
	if (done)
	{
		for (int x : to_check)
		{
// 			printf("check %d\n", x);
			if (cou [x] == 0)
				poss[x] = false;
			to_check_flag[x] = false;
		}
	}
	else
	{
		for (int i = 0; i < MN; ++i)
			if (cou [i])
				poss[i] = true;
	}
	to_check.clear();
	done = true;
}
int res()
{
	for (int i = MN - 1; i >= 0; i--)
		if (poss[i])
			return i;
}
bool used[MN];
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	init();
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		used[x] = true;
	}
	for (int i = 1; i < MN; ++i)
	{
		insert(i, 1);
		if (i - k - 1 > 0)
			insert(i - k - 1, -1);
		if (used[i])
			update();
	}
	printf("%d\n", res());
}