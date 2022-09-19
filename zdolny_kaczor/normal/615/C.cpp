# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <vector>
using namespace std;
const int MN = 2116;
char pattern[MN];
int plen;
char target[MN];
int tlen;
int push(int from, int pos, int dir)//zwraca liczb liter, ktre si zgadzaj
{
	int res;
	for (res = 0; pos >= 0 && pos < plen && from < tlen; res ++, pos += dir, from ++)
		if (target[from] != pattern[pos])
			break;
	return res;
}
vector <pair <int, int> > res;
int main()
{
	scanf("%s%s", pattern, target);
	plen = strlen (pattern);
	tlen = strlen (target);
	int from = 0;
	while (from < tlen)
	{
		int maxfound = -1;
		pair <int, int> wh;
		for (int dir = -1; dir <= 1; dir += 2)
			for (int pos = 0; pos < plen; ++pos)
			{
				int found = push (from, pos, dir);
				if (found > maxfound)
				{
					maxfound = found;
					wh = make_pair(pos, pos + (found - 1) * dir);
				}
			}
		res.push_back(wh);
		if (maxfound == 0)
		{
			printf("-1\n");
			exit(0);
		}
		from += maxfound;
	}
	printf("%d\n", (int) res.size());
	for (int i = 0; i < (int)res.size(); ++i)
		printf("%d %d\n", res[i].first + 1, res[i].second + 1);
}