

#include <cstdio>
#include <cassert>
#include <set>
#include <vector>
using namespace std;

const int N = 100500;

char C[N];
int sz[N];          

set<int> E[N];

int vA[N], vB[N];

void deledge(int i)
{
	int a = vA[i];
	int b = vB[i];
	E[a].erase(i);
	E[b].erase(i);
}                    

//#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define eprintf(...) 42//fprintf(stderr, __VA_ARGS__)

bool DFS(int x, char c, int p, int tot, int d = 0)
{
	for (int i = 0; i < d; i++)
		eprintf("  ");
	eprintf("at %d, c = %c, p = %d, tot = %d\n", x, c, p, tot);
	if (x == -1)
		return false;
	assert(c < 'Y');
	sz[x] = 1;
	bool all = true;
	for (set<int>::iterator it = E[x].begin(); it != E[x].end(); it++)
	{
		int e = *it;
		int y = x ^ vA[e] ^ vB[e];
		if (y == p)
			continue;
		if (DFS(y, c, x, tot, d))
			return true;
		sz[x] += sz[y];
		all &= sz[y] <= tot / 2;
	}
	all &= (tot - sz[x]) <= tot / 2;
	if (all)
	{
		vector<int> V(E[x].begin(), E[x].end());
		for (int i = 0; i < V.size(); i++)
			deledge(V[i]);
		C[x] = c;
		for (int i = 0; i < d; i++)
			eprintf("  ");
		eprintf("splitting here\n");
		for (int i = 0; i < V.size(); i++)
		{
			int y = vA[V[i]] ^ vB[V[i]] ^ x;
			if (y == p)
				DFS(y, c + 1, -1, tot - sz[x], d + 1);
			else
				DFS(y, c + 1, -1, sz[y], d + 1);
		}
		return true;
	}
	return false;
}

int main()
{
	//freopen("10", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		vA[i] = a;
		vB[i] = b;
		E[a].insert(i);
		E[b].insert(i);
	}
	assert(DFS(1, 'A', -1, n));
	for (int i = 1; i <= n; i++)
		printf("%c%c", C[i], " \n"[i == n]);

	return 0;	 
}