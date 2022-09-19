# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 211;
vector <int> pos[MN];
int ans[MN];
int main()
{
	int n;
	scanf("%d", &n);
	n *= 2;
	for (int i = 0; i < n; ++i)
	{
		int x;
		scanf("%d", &x);
		pos[x].push_back(i);
	}
	int last = 0;
	vector <int> trash;
	int cou[2] = {};
	int curr = 0;
	for (int i = 0; i < MN; ++i)
	{
		if (pos[i].size() == 1)
		{
			ans[pos[i][0]] = curr;
			cou[curr] ++;
			curr = 1 - curr;
		}
		else if (pos[i].size() > 1)
		{
			for (int k = 0; k < 2; ++k)
			{
				ans[pos[i][k]] = k;
				cou[k] ++;
			}
			for (int k = 2; k < pos[i].size(); ++k)
				trash.push_back(pos[i][k]);
		}
	}
	int res = cou[0] * cou[1];
	for (auto x : trash)
		if (cou[0] < n / 2)
		{
			ans[x] = 0;
			cou[0]++;
		}
		else
			ans[x] = 1;
	printf("%d\n", res);
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i] + 1);
	printf("\n");
}