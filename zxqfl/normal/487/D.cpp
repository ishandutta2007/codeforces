#include <bits/stdc++.h>

#define jjs(i, s, x) for (int i = (s); i < (x); i++)
#define jjl(i, x) jjs(i, 0, x)
#define ji(x) jjl(i, x)
#define jj(x) jjl(j, x)
#define jk(x) jjl(k, x)
#define jij(a, b) ji(a) jj(b)
#define INF ((int) 1e9+10)
#define pb push_back
#define mp make_pair
#define rint(x) scanf("%d", &(x))
#define rlong(x) scanf("%lld", &(x))
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;

char grid[100000][10];
int N, M, Q;

pi simulate(int a, int i, int idx)
{
	if (grid[a][i] == '<')
	{
		if (i == 0)
			return mp(a+1, 0);
		else if (i-1 == idx)
			return mp(-1, -1);
		else
			return simulate(a, i-1, i);
	}
	else if (grid[a][i] == '>')
	{
		if (i == M-1)
			return mp(a+1, M+1);
		else if (i+1 == idx)
			return mp(-1, -1);
		else
			return simulate(a, i+1, i);
	}
	else
		return mp(-2, i);
}

struct stree
{
	int a, b;
	stree *left, *right;
	pi result[10];

	stree(int l, int r)
	{
		a = l; b = r;
		if (a == b)
		{
			left = right = NULL;
			calc();
		}
		else
		{
			int mid = (a+b) / 2;
			left = new stree(a, mid);
			right = new stree(mid+1, b);
			calc();
		}
	}

	void calc()
	{
		if (a == b)
		{
			ji(M)
			{
				if (grid[a][i] == '^')
				{
					result[i] = mp(-2, i);
				}
				else if (grid[a][i] == '<')
				{
					if (i == 0)
						result[i] = mp(a+1, 0);
					else
						result[i] = simulate(a, i-1, i);
				}
				else
				{
					if (i == M-1)
						result[i] = mp(a+1, M+1);
					else
						result[i] = simulate(a, i+1, i);
				}
			}
		}
		else
		{
			ji(M)
			{
				pi r = right->result[i];
				if (r.first != -2)
				{
					result[i] = r;
				}
				else
				{
					result[i] = left->result[r.second];
				}
			}
		}
	}

	void recalc(int x)
	{
		if (x < a || x > b)
			return;
		if (left)
		{
			left->recalc(x);
			right->recalc(x);
		}
		calc();
	}

	pi query(int x, int y)
	{
		if (b == x)
			return result[y];

		if (x >= right->a)
		{
			pi p = right->query(x, y);
			if (p.first >= -1) return p;
			return left->result[p.second];
		}
		return left->query(x, y);
	}
};

int main()
{
	rint(N); rint(M); rint(Q);
	ji(N)
	{
		char buf[20];
		scanf("%s", buf);
		jj(M)
			grid[i][j] = buf[j];
	}

	stree tree(0, N-1);
	jk(Q)
	{
		// printf("exec query %d\n", k);
		// fflush(NULL);
		char buf[5];
		scanf("%s", buf);
		int x, y;
		rint(x); rint(y);
		x--, y--;
		if (*buf == 'A')
		{
			pi r = tree.query(x, y);
			if (r.first == -2)
				printf("%d %d\n", 0, r.second+1);
			else
				printf("%d %d\n", r.first, r.second);
		}
		else
		{
			scanf("%s", buf);
			grid[x][y] = *buf;
			tree.recalc(x);
		}
	}
}