#include <bits/stdc++.h>

#define sloop(i, s, x) for (int i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define rep(x) loop(COUNTER, x)
#define mp make_pair
#define pb push_back
#define INF ((int) 1e9)
#define rint(x) scanf("%d", &(x))

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N, M;
vector<int> V;
int S = -1;

struct gnode
{
	vector<gnode*> edges;
	int id;
	int dist;
	gnode* from;
	int parity;

	gnode() : dist(INF) {}
} gnodes[100000];

struct tnode
{
	vector<tnode*> children;
	int parity;
	bool all0;
	int id;

	void sa0()
	{
		all0 = true;
		for (tnode* o : children)
		{
			o->sa0();
			all0 = all0 && o->all0 && o->parity == 0;
		}
	}

	void solve()
	{
		V.pb(id);
		parity ^= 1;
		for (tnode* o : children)
		{
			if (!o->all0)
			{
				o->solve();
				V.pb(id);
				parity ^= 1;
			}
			if (o->parity)
			{
				V.pb(o->id);
				o->parity ^= 1;
				V.pb(id);
				parity ^= 1;
			}
		}
	}

} tnodes[100000];

int main()
{
	rint(N), rint(M);

	rep(M)
	{
		int a, b;
		rint(a), rint(b);
		a--, b--;
		gnodes[a].edges.pb(gnodes + b);
		gnodes[b].edges.pb(gnodes + a);
	}

	loop(i, N)
	{
		gnodes[i].id = i;
		rint(gnodes[i].parity);
		if (gnodes[i].parity)
			S = i;
	}
	if (S < 0)
	{
		printf("0\n");
		return 0;
	}

	gnodes[S].dist = 0;
	queue<gnode*> Q;
	Q.push(gnodes + S);

	while (!Q.empty())
	{
		gnode* n = Q.front();
		Q.pop();
		int d = n->dist;
		for (gnode* o : n->edges)
		{
			if (o->dist == INF)
			{
				o->dist = d + 1;
				o->from = n;
				Q.push(o);
			}
		}
	}

	loop(i, N)
	{
		if (gnodes[i].dist == INF && gnodes[i].parity)
		{
			printf("-1\n");
			return 0;
		}

		if (gnodes[i].dist != INF && i != S)
		{
			tnodes[gnodes[i].from->id].children.pb(tnodes + i);
		}
		tnodes[i].parity = gnodes[i].parity;
		tnodes[i].id = i;
	}

	tnodes[S].sa0();
	tnodes[S].solve();
	int count = 0;
	loop(i, V.size()) if (V[i] == S)
		count++;

	if (count % 2 != 1)
		V.pop_back();

	printf("%d\n", V.size());
	for (int x : V)
	{
		printf("%d ", x+1);
	}
	printf("\n");
}