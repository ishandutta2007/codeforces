# include <cstdio>
# include <vector>
using namespace std;
# define MN 401
vector <pair <int, int> > graph[MN];
# define graf graph
# define INF (1<<20)
# define vnr first
# define enr second
int res[MN][MN]; //[i][k] minimalna liczba krawdzi do odcicia k z poddrzew pod i oraz jego prawym rodzestwem
int via[MN][MN]; //warto k dla ktrej osiga simin w liczeniu dynamicznie res[][]
int under[MN][MN]; //[i][k] minimalna liczba krawdzi do odcicia k z poddrzewa pod i
pair <int, int> up[MN];
int next[MN];
int n, size;
void remake(int x, int from=-1)
{
// 	printf("remake(%d %d)\n", x, from);
	for (int i=0; i<graf[x].size(); ++i)
		if (graf[x][i].vnr==from)
		{
			up[x]=graf[x][i];
			graf[x][i]=graf[x].back();
			graf[x].pop_back();
			i--;
		}
		else
			remake(graf[x][i].vnr, x);
	if (graf[x].size())
	{
		for (int i=0; i<graf[x].size()-1; ++i)
			next[graf[x][i].vnr]=graf[x][i+1].vnr;
		next[graf[x].back().vnr]=-1;
	}
}
void solve(int x)
{
	for (int i=graf[x].size()-1; i>=0; --i)
		solve(graph[x][i].vnr);
	under[x][0]=1;
	if (graf[x].size()==0)
	{
		under[x][1]=0;
		for (int i=2; i<MN; ++i)
			under[x][i]=INF;
	}
	else
	{
		for (int i=1; i<=n; ++i)
			under[x][i]=res[graf[x][0].vnr][i-1];
	}
	if (next[x]==-1)
	{
		for (int i=0; i<=n; ++i)
		{
			res[x][i]=under[x][i];
		}
	}
	else
	{
		for (int i=0; i<=n; ++i)
		{
			res[x][i]=INF;
			for (int k=0; k<=i; ++k)
			{
				if (res[x][i]>res[next[x]][k]+under[x][i-k])
				{
					res[x][i]=res[next[x]][k]+under[x][i-k];
					via[x][i]=k;
				}
			}
		}
	}
}
void uprint(int, int);
void rprint(int, int);
void uprint(int x, int amo)
{
	if (amo==0)
	{
		if (up[x].enr!=-1)
			printf("%d ", up[x].enr);
	}
	else if (graf[x].size())
		rprint(graf[x][0].vnr, amo-1);
}
void rprint(int x, int amo)
{
	if (next[x]==-1)
		uprint(x, amo);
	else
	{
		rprint(next[x], via[x][amo]);
		uprint(x, amo-via[x][amo]);
	}
}
int main()
{
	scanf("%d%d", &n, &size);
	for (int i=1; i<n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--, y--;
		graph[x].push_back(make_pair(y, i));
		graph[y].push_back(make_pair(x, i));
	}
	up[0]=make_pair(-1, -1);
	next[0]=-1;
	remake(0);
// 	printf("remade\n");
	solve(0);
// 	printf("solved\n");
// 	for (int i=0; i<n; ++i)
// 		printf("next[%d]=%d\n", i, next[i]);
// 	for (int i=0; i<n; ++i)
// 	{
// 		printf("res[%d]:\n", i);
// 		for (int k=0; k<=n; ++k)
// 			printf("%d.%d\n", k, res[i][k]);
// 		printf("under[%d]:\n", i);
// 		for (int k=0; k<=n; ++k)
// 			printf("%d.%d\n", k, under[i][k]);
// 	}
	for (int i=0; i<=n; ++i)
		under[0][i]--;
	int min=INF;
	int where;
	for (int i=0; i<n; ++i)
		if (under[i][size]<min)
		{
			min=under[i][size];
			where=i;
		}
	printf("%d\n", min+1);
// 	printf("where=%d\n", where);
	if (where)
		printf("%d ", up[where].enr);
// 	return 0;
	uprint(where, size);
	putchar(10);
}