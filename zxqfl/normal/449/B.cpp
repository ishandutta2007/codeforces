#include <bits/stdc++.h>

#define rloop(i, x) for (ll i = (x); i >= 0; i--)
#define sloop(i, s, x) for (ll i = (s); i < (x); i++)
#define loop(i, x) sloop(i, 0, x)
#define rep(x) loop(COUNTER, x)
#define INF ((ll) 1e9 + 1000)
#define mp make_pair
#define pb push_back
#define rint(N) scanf("%lld", &(N))

#define MAXN 1000
#define MAXK 1000001

typedef long long ll;
using namespace std;

ll N, M, K;
ll ans = 0;

struct node
{
	ll tdist;
	vector<pair<ll, node*> > edges;
	ll mdist;
	bool visited;

	node() : tdist(-1), visited(false), mdist(INF) {}

} nodes[100001];

typedef pair<ll, node*> pn;

int main()
{
	rint(N), rint(M), rint(K);

	rep(M)
	{
		ll A, B, C;
		rint(A), rint(B), rint(C);
		A--, B--;
		nodes[A].edges.pb(mp(C, nodes + B));
		nodes[B].edges.pb(mp(C, nodes + A));
	}

	rep(K)
	{
		ll A, C;
		rint(A), rint(C);
		A--;
		if (nodes[A].tdist < 0)
			nodes[A].tdist = C;
		else
		{
			nodes[A].tdist = min(nodes[A].tdist, C);
			ans++;
		}
	}

	priority_queue<pn, vector<pn>, greater<pn> > Q;
	nodes[0].mdist = 0;
	Q.push(mp(0, nodes));

	sloop(i, 1, N)
	{
		if (nodes[i].tdist >= 0)
			Q.push(mp(nodes[i].tdist, nodes + i));
	}

	while (!Q.empty())
	{
		pn x = Q.top();
		Q.pop();

		if (x.second->visited)
			continue;

		node& n = *(x.second);
		n.visited = true;

		ll td = min(n.tdist, n.mdist);
		if (n.tdist < 0)
			td = n.mdist;
		//printf("%d\n", n.mdist);
		if (n.mdist <= n.tdist)
			ans++;

		for (auto& e : n.edges)
		{
			ll nd = td + e.first;
			//printf("%d %d\n", nd, e.first);
			node* o = e.second;
			if (nd < o->mdist)
			{
				o->mdist = nd;
				if (nd < o->tdist || o->tdist < 0)
					Q.push(mp(nd, o));
			}
		}
	}

	printf("%lld\n", ans);
}