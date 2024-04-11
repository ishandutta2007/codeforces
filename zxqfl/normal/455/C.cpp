#include <bits/stdc++.h>

#define sloop(i, s, x) for (int i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define repmac(x) loop(COUNTER, x)
#define mp make_pair
#define pb push_back
#define INF ((int) 1e9)
#define rint(x) scanf("%d", &(x))
#define r2d(x) (((x)+1)/2)

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int N, M, Q;

struct node
{
	vector<node*> edges;
	node* rep;
	int diam;
	bool visit[2];
	int dist;
	int id;

	node() : diam(-1), rep(NULL)
	{
		visit[0] = visit[1] = false;
	}
} nodes[300001];

vector<int> V;

int bfs(int idx, int t)
{
	nodes[idx].visit[t] = true;
	nodes[idx].dist = 0;
	queue<int> Q;
	Q.push(idx);
	int last;

	while (!Q.empty())
	{
		int v = last = Q.front();
		if (t == 1)
			V.pb(v);
		Q.pop();

		for (node* n : nodes[v].edges)
		{
			if (!n->visit[t])
			{
				n->dist = nodes[v].dist + 1;
				n->visit[t] = true;
				Q.push(n->id);
			}
		}
	}

	return last;
}

void do_thingy(int idx)
{
	V.clear();
	idx = bfs(idx, 0);
	idx = bfs(idx, 1);

	for (int n : V)
	{
		nodes[n].rep = nodes + idx;
	}

	nodes[idx].rep = NULL;
	nodes[idx].diam = nodes[idx].dist;
}

node* par(node* n)
{
	node* o = n;
	//printf("climbing\n");
	while (n->rep != NULL)
	{
		n = n->rep;
	}
	while (o->rep != NULL)
	{
		//printf("%d\n", o->id);
		node* next = o->rep;
		o->rep = n;
		o = next;
	}
	return n;
}

int main()
{
	int N, M, Q;
	rint(N), rint(M), rint(Q);

	loop(i, N) nodes[i].id = i;

	repmac(M)
	{
		int a, b;
		rint(a), rint(b);
		a--, b--;
		nodes[a].edges.pb(nodes + b);
		nodes[b].edges.pb(nodes + a);
	}

	loop(i, N) if (!nodes[i].visit[0])
	{
		do_thingy(i);
	}

	repmac(Q)
	{
		int t, a, b;
		rint(t), rint(a);
		if (t == 2)
		{
			rint(b);
			b--;
		}
		a--;

		if (t == 2)
		{
			node* n1 = par(nodes + a);
			node* n2 = par(nodes + b);
			//printf("id: %d %d\n", n1->id, n2->id);
			if (n1 == n2)
				continue;
			n1->diam = max(max(n1->diam, n2->diam), r2d(n1->diam) + r2d(n2->diam) + 1); // dreaming flashbacks
			n2->rep = n1;
		}
		else
		{
			printf("%d\n", par(nodes + a)->diam);
		}
	}
}