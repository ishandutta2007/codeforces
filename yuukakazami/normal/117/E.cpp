/*
 * E. Tree or not Tree.cpp
 *
 *  Created on: 2011-9-25
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
#define DEBUG cout<<__LINE__<<endl;
using namespace std;

const int MAX_N_VERTICES = int(1e5) + 10;

struct Root;
struct Tree;

struct Vertex {
	vector<Vertex*> adj;
	bool visited;
	bool inCycle;
	Root*root;
	int idx;
	Vertex*father, *top;
	Tree*tree;
	int size, idxInPath;
	Vertex(int _idx) :
			idx(_idx), visited(false), inCycle(false), root(0), father(0), top(0) {
	}
};

struct Root {
	Root*left, *right;
	int idx;
	Vertex*root;
	Root(Vertex*_root) :
			root(_root) {
	}

	void markAll(Vertex*u) {
		if (u->root != 0)
			return;
		u->root = this;
		foreach(e,u->adj) {
			if ((*e)->inCycle)
				continue;
			markAll(*e);
		}
	}
};

Vertex*vs[MAX_N_VERTICES];

int nVertices, nQueries;

int one;

void readInput() {
	cin >> nVertices >> nQueries;
	for (int i = 0; i < nVertices; ++i) {
		vs[i] = new Vertex(i);
	}
	for (int i = 0; i < nVertices; ++i) {
		int a, b;
		scanf("%d%d", &a, &b), --a, --b;
		vs[a]->adj.push_back(vs[b]);
		vs[b]->adj.push_back(vs[a]);
	}
}

vector<Root*> cycle;

Vertex* findCycle(Vertex*u, Vertex*p) {
	if (u->visited)
		return u;
	else
		u->visited = true;
	foreach(e,u->adj) {
		Vertex*v = *e;
		if (v == p)
			continue;
		Vertex*t = findCycle(v, u);
		if (t != 0) {
			v->inCycle = true;
			cycle.push_back(new Root(v));
			return u == t ? 0 : t;
		}
	}
	return 0;
}

struct Tree {
	Tree*pl, *pr;
	int l, r;
	int cnt[2];
	bool isRev;

	void apply() {
		isRev ^= 1;
		swap(cnt[0], cnt[1]);
	}

	void relax() {
		if (isRev) {
			isRev = false;
			pl->apply();
			pr->apply();
		}
	}

	void update() {
		for (int i = 0; i < 2; ++i) {
			cnt[i] = pl->cnt[i] + pr->cnt[i];
		}
	}

	Tree(int _l, int _r) :
			l(_l), r(_r), isRev(false) {
		cnt[0] = r - l;
		cnt[1] = 0;
		if (l + 1 == r) {
			pl = pr = 0;
			return;
		}
		int m = (l + r) >> 1;
		pl = new Tree(l, m);
		pr = new Tree(m, r);
		update();
	}

	void reverse(int L, int R) {
		if (L >= r || l >= R)
			return;
		if (L <= l && r <= R) {
			apply();
			return;
		}
		relax();
		pl->reverse(L, R);
		pr->reverse(L, R);
		update();
	}

	int ask(int L, int R) {
		if (L >= r || l >= R)
			return 0;
		if (L <= l && r <= R) {
			return cnt[1];
		}
		relax();
		return pl->ask(L, R) + pr->ask(L, R);
	}
};

void build(Root*rt) {
	Vertex*r = rt->root;
	vector<Vertex*> que;
	que.push_back(r);
	int qh = 0;
	while (qh < que.size()) {
		Vertex*u = que[qh++];
		foreach(e,u->adj) {
			Vertex*v = *e;
			if (!v->inCycle && v != u->father) {
				v->father = u;
				que.push_back(v);
			}
		}
	}

	for (int i = que.size() - 1; i >= 0; --i) {
		Vertex*u = que[i];
		u->size = 1;
		foreach(e,u->adj) {
			Vertex*v = *e;
			if (v->father == u) {
				u->size += v->size;
			}
		}
	}

	for (int i = 0; i < que.size(); ++i) {
		Vertex*top = que[i];
		if (top->top)
			continue;
		Vertex*u = top;
		int cur = 0;

		for (;;) {
			u->top = top;
			u->idxInPath = cur++;

			Vertex*next = 0;
			foreach(e,u->adj) {
				Vertex*v = *e;
				if (v->father == u) {
					if (next == 0 || v->size > next->size) {
						next = v;
					}
				}
			}

			if (next == 0)
				break;
			u = next;
		}

		top->tree = new Tree(0, cur);
	}
}

void updateToRoot(Vertex*u) {
	Vertex*r = u->root->root;
	while (u) {
		Vertex*top = u->top;
		one -= top->tree->cnt[1];
		top->tree->reverse(top == r ? 1 : 0, u->idxInPath + 1);
		one += top->tree->cnt[1];
		u = top->father;
	}
}

Tree*rt;

void doitCycle(Root*a, Root*b) {
	bool isSwaped = false;
	if (a->idx > b->idx) {
		swap(a, b);
		isSwaped = true;
	}
	int R = b->idx - a->idx, L = cycle.size() - R;
	int how;
	if (R < L)
		how = 0;
	else if (L < R)
		how = 1;
	else {
		if (!isSwaped)
			how = a->right->root->idx > a->left->root->idx;
		else
			how = b->left->root->idx > b->right->root->idx;
	}
	if (!how)
		rt->reverse(a->idx, b->idx);
	else {
		rt->reverse(0, a->idx);
		rt->reverse(b->idx, cycle.size());
	}
}

void doit(Vertex*u, Vertex*v) {
	updateToRoot(u);
	updateToRoot(v);
	doitCycle(u->root, v->root);
}

void work() {
	findCycle(vs[0], 0);
	for (int i = 0; i < cycle.size(); ++i) {
		Root*cur = cycle[i], *next = cycle[(i + 1) % cycle.size()];
		cur->right = next;
		next->left = cur;
		cur->idx = i;
		cur->markAll(cur->root);
		build(cur);
	}

	one = 0;
	rt = new Tree(0, cycle.size());

	for (int i = 0; i < nQueries; ++i) {
		int a, b;
		scanf("%d%d", &a, &b), --a, --b;
		doit(vs[a], vs[b]);

		int ans = nVertices - one - rt->cnt[1];
		if (rt->cnt[0] == 0)
			++ans;
		printf("%d\n", ans);
	}
}

int main() {
	readInput();
	work();
	return 0;
}