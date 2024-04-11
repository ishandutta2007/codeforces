# include <cstdio>
# include <algorithm>
# include <vector>
using namespace std;
const int MN=200*1000+20;
const int LOG=18;
vector <int> graf[MN];
vector <int> grafT[MN];
int served[MN];
vector <int> order;
int dep[MN];
int jump[MN][LOG];
vector <int> tree[MN];
int res[MN];
void dfs(int x, int curr)
{
	served[x]=curr;
	for (int v:graf[x])
		if (served[v]==0)
			dfs(v, curr);
	order.push_back(x);
}
int moveup(int ver, int dist)
{
	for (int i=0; i<LOG; ++i)
	{
		if ((1<<i)&dist)
			ver=jump[ver][i];
	}
	return ver;
}
void ans(int x)
{
  static int nr = 0;
	sort(tree[x].begin(), tree[x].end());
	for (int v:tree[x])
		ans(v);
	res[x] = ++nr;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i=0; i<m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[b].push_back(a);
		grafT[a].push_back(b);
	}
	for (int i=1; i<=n; ++i)
		if (!served[i])
		{
			order.clear();
			dfs(i, i);
			reverse(order.begin(), order.end());
			for (int x:order)
			{
				if (x==i)
					continue;
				int best=-1;
				for (int tried:grafT[x])
					if (served[tried]==i)
					{
						if (best==-1)
							best=tried;
						else
						{
							int y=best;
							int z=tried;
							bool change;
							if (dep[y]>dep[z])
								y=moveup(y, dep[y]-dep[z]);
							else
								z=moveup(z, dep[z]-dep[y]);
							if (y==z)
								change=(dep[best]<dep[tried]);
							else
							{
								for (int k=LOG-1; k>=0; --k)
								{
									int jumpy=jump[y][k];
									int jumpz=jump[z][k];
									if (jumpy!=jumpz)
									{
										y=jumpy;
										z=jumpz;
									}
								}
								change=(y>z);
							}
							if (change)
								best=tried;
						}
					}
				for (int i=LOG-1; i>=0; --i)
						if (jump[best][i]>x)
							best=jump[best][i];
// 					printf("best=%d jump[best][0]=%d\n", best, jump[best][0]);
					if (best>x)
						best=jump[best][0];
// 					printf("%d to %d\n", best, x);
					tree[best].push_back(x);
					jump[x][0]=best;
					dep[x]=dep[best]+1;
					for (int i=1; i<LOG; ++i)
						jump[x][i]=jump[jump[x][i-1]][i-1];
			}
			ans(i);
		}
	for (int i = 1; i <= n; ++i)
	  printf("%d ", res[i]);
	printf("\n");
}