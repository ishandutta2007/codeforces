# include <cstdio>
# include <vector>
using namespace std;
const int MN=100200;
const int MOD=1000*1000*1000+7;
vector <pair <int, int> > graf[MN];
int color[MN];
bool dfs(int x, int c=0)
{
	color[x]=c;
	for (int i=0; i<graf[x].size(); ++i)
	{
		if (color[graf[x][i].first]==-1)
			if (!dfs(graf[x][i].first, c^graf[x][i].second))
				return false;
		if (color[graf[x][i].first]^color[x]^graf[x][i].second)
			return false;
	}
	return true;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i=0; i<m; ++i)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		graf[a].push_back(make_pair(b, c^1));
		graf[b].push_back(make_pair(a, c^1));
	}
	for (int i=1; i<=n; ++i)
		color[i]=-1;
	int res=1;
	bool pre=false;
	for (int i=1; i<=n; ++i)
		if (color[i]==-1)
			if (dfs(i))
			{
				if (pre)
					res=res*2%MOD;
				else
					pre=true;
			}
			else
				res=0;
	printf("%d\n", res);
}