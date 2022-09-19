# include <cstdio>
# include <algorithm>
# include <cstdlib>
void err()
{
	printf("-1\n");
	exit (0);
}
using namespace std;
int size = 1;
const int MN = 1e5+10;
pair <int, int> res[MN];
void used(int nr)
{
// 	printf("used %d\n", nr);
	res[nr] = make_pair(size, size+1);
	size ++ ;
}
int nx = 1, ny = 3;
void unused(int nr)
{
// 	printf("unused %d\n", nr);
	if (ny > size)
		err();
	res[nr]=make_pair(nx, ny);
	nx ++;
	if (nx+1 == ny)
	{
		nx=1;
		ny++;
	}
}
typedef pair < pair <int, bool>, int> str;
str all[MN];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i=0; i<m; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		all[i] = make_pair (make_pair(x, (y==0)), i);
	}
	sort(all, all+m);
	for (int i=0; i<m; ++i)
	{
		if (all[i].first.second)
			unused(all[i].second);
		else
			used(all[i].second);
	}
	for (int i=0; i<m; ++i)
		printf("%d %d\n", res[i].first, res[i].second);
}