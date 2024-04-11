# include <cstdio>
# include <set>
using namespace std;
# define MN 100100
int deg[MN];
int color[MN];
set <pair <int, int> > vertices[2];
bool in[MN];
void edit(int x, int val)
{
	vertices[color[x]].erase(make_pair(deg[x], x));
	deg[x]=val;
	vertices[color[x]].insert(make_pair(deg[x], x));
}
void erase(int x)
{
	vertices[color[x]].erase(make_pair(deg[x], x));
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i=0; i<n; ++i)
	{
		int d;
		scanf("%d%d", color+i, &d);
		edit(i, d);
	}
	for (int i=1; i<n; ++i)
	{
		pair <int, int> del;
		if (vertices[0].size()==1)
			del=*vertices[1].begin();
		else if (vertices[1].size()==1)
			del=*vertices[0].begin();
		else
			del=min(*vertices[0].begin(), *vertices[1].begin());
		pair <int, int> alt=*vertices[1-color[del.second]].begin();
// 		for (int k=0; k<2; ++k)
// 		{
// 			printf("set %d\n", k);
// 			for (set <pair <int, int> > :: iterator it=vertices[k].begin(); it!=vertices[k].end(); ++it)
// 				printf("(%d, %d)", it->first, it->second);
// 			putchar(10);
// 		}
		printf("%d %d %d\n", 1+del.second, 1+alt.second, del.first);
		erase(del.second);
		edit(alt.second, alt.first-del.first);
	}
}