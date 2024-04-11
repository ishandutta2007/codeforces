# include <cstdio>
# include <algorithm>
# include <vector>
using namespace std;
# define MN 100110
# define colors color
int color[MN];
vector <int> conn[MN];
bool done[MN];
int main()
{
	int V, E;
	scanf("%d%d", &V, &E);
	for (int i=0; i<V; ++i)
		scanf("%d", color+i);
	for (int i=0; i<E; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		if (color[a]!=color[b])
		{
			conn[color[a]].push_back(color[b]);
			conn[color[b]].push_back(color[a]);
		}
	}
	int maxx=-1, wh=10000000;
	for (int k=0; k<V; ++k)
	{
		int nr=colors[k];
		if (!done[nr])
		{
			sort(conn[nr].begin(), conn[nr].end());
			int amo=0;
			for (int i=0; i<conn[nr].size(); ++i)
				if (i==0 || conn[nr][i]!=conn[nr][i-1])
					amo++;
			if (amo>maxx || (amo==maxx && wh>nr))
			{
				maxx=amo;
				wh=nr;
			}
			done[nr]=true;
		}
	}
	printf("%d\n", wh);
}