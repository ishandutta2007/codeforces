# include <cstdio>
# include <stack>
# include <cstring>
# include <cstdlib>
using namespace std;
const int MN = 611;
stack <pair <int, int> > depths;
int low[MN], high[MN];
char ans[MN * 2];
void err()
{
	printf("IMPOSSIBLE\n");
	exit(0);
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", low + i, high + i);
	int curr = 0;
	for (int i = 0; i < n * 2; ++i)
	{
		if (depths.empty() || depths.top().first > i)
		{
			if (curr == n)
				err();
			depths.push(make_pair(i + low[curr], i + high[curr]));
			ans[i] = '(';
			curr ++;
		}
		else if (depths.top().second < i)
			err();
		else
		{
			depths.pop();
			ans[i] = ')';
		}
	}
	ans[n * 2] = 0;
	printf("%s\n", ans);
}