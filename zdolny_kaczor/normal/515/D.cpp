# include <cstdio>
# include <cstdlib>
# include <queue>
using namespace std;
const int MN = 2e3 + 44;
char arr[MN][MN];
void err()
{
	printf("Not unique\n");
	exit(0);
}
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char first[4] = {'^', '<', 'v', '>'};
char second[4] = {'v', '>', '^', '<'};
queue <pair <int, int> > leaves;
int deg(pair <int, int> coo)
{
	int res = 0;
	for (int i = 0; i < 4; ++i)
		if (arr[coo.first + dx[i]][coo.second + dy[i]] == '.')
			res ++;
	return res;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%s", arr[i] + 1);
	for (int i = 1; i <= n; ++i)
		for (int k = 1; k <= m; ++k)
			if (arr[i][k] == '.' && deg(make_pair(i, k)) == 1)
				leaves.push(make_pair(i, k));
	while (!leaves.empty())
	{
		pair <int, int> curr = leaves.front();
		leaves.pop();
		bool found = true;
		for (int i = 0; i < 4; ++i)
			if (arr[curr.first + dx[i]][curr.second + dy[i]] == '.')
			{
				found = true;
				arr[curr.first][curr.second] = first[i];
				arr[curr.first + dx[i]][curr.second + dy[i]] = second[i];
				for (int k = 0; k < 4; ++k)
					if (arr[curr.first + dx[i] + dx[k]][curr.second + dy[i] + dy[k]] == '.' && deg(make_pair(curr.first + dx[i] + dx[k], curr.second + dy[i] + dy[k])) == 1)
						leaves.push(make_pair(curr.first + dx[i] + dx[k], curr.second + dy[i] + dy[k]));
				break;
			}
		if (!found)
			err();
	}
	for (int i = 1; i <= n; ++i)
		for (int k = 1; k <= m; ++k)
			if (arr[i][k] == '.')
				err();
	for (int i = 1; i <= n; ++i)
		printf("%s\n", arr[i] + 1);
}