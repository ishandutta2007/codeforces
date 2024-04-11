/*
 * H. Road Problem.cpp
 *
 *  Created on: 2011-5-21
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
#include <cassert>
#include <utility>
#include <set>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

struct Vertex;

int dfsCur;
vector<Vertex*> stack;
vector<Vertex*> comps;

typedef pair<int, int> ipair;
set<ipair> edgeSet;

struct Vertex {
	vector<int> ids;
	int ord, low;
	Vertex*comp;
	Vertex() {
		ord = low = -1;
	}
	Vertex(int id) {
		ids.push_back(id);
		ord = low = -1;
	}
	vector<Vertex*> adj;
	void dfs(Vertex*f) {
		ord = low = dfsCur++;
		stack.push_back(this);
		foreach(iter,adj) {
			Vertex*v = *iter;
			if (v != f) {
				if (v->ord == -1) {
					v->dfs(this);
					low = min(low, v->low);
				} else {
					low = min(low, v->ord);
				}
			}
		}

		if (ord == low) {
			comp = new Vertex;
			for (;;) {
				Vertex*u = stack.back();
				stack.pop_back();
				u->comp = comp;
				comp->ids.insert(comp->ids.end(), u->ids.begin(), u->ids.end());
				if (u == this)
					break;
			}
			comps.push_back(comp);
		}
	}

	int cnt;
	Vertex* dfs2(Vertex*f) {
		if (adj.size() == 1) {
			return this;
		}
		Vertex*leaf = 0;
		foreach(iter,adj) {
			Vertex*u = *iter;
			if (u == f)
				continue;
			u->cnt = cnt + adj.size() - 2;
			Vertex*tmp = u->dfs2(this);
			if (leaf == 0 || tmp->cnt > leaf->cnt) {
				leaf = tmp;
			}
		}
		return leaf;
	}

	Vertex*goLeft(Vertex*fa) {
		if (adj.size() == 1)
			return this;
		for (int i = 0; i < adj.size(); ++i) {
			if (adj[i] != fa)
				return adj[i]->goLeft(this);
		}
	}

	Vertex*goRight(Vertex*fa) {
		if (adj.size() == 1)
			return this;
		for (int i = adj.size() - 1; i >= 0; --i) {
			if (adj[i] != fa)
				return adj[i]->goRight(this);
		}
	}
};

vector<Vertex*> vs;
int nVs, nEs;

void buildEdge(Vertex*u, Vertex*v) {
	u->adj.push_back(v);
	v->adj.push_back(u);
}

void readInput() {
	cin >> nVs >> nEs;
	vs.resize(nVs);
	for (int i = 0; i < nVs; ++i) {
		vs[i] = new Vertex(i + 1);
	}
	for (int i = 0; i < nEs; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edgeSet.insert(make_pair(a, b));
		edgeSet.insert(make_pair(b, a));
		--a;
		--b;
		buildEdge(vs[a], vs[b]);
	}
}

void buildComps(const vector<Vertex*> vs) {
	dfsCur = 0;
	stack.clear();
	comps.clear();
	vs[0]->dfs(0);

	for (int i = 0; i < vs.size(); ++i) {
		Vertex*u = vs[i];
		foreach(iter,u->adj) {
			Vertex*v = *iter;
			if (u->comp != v->comp && u->comp < v->comp) {
				buildEdge(u->comp, v->comp);
			}
		}
	}
}

vector<int> a1, a2;

void addAns(Vertex*u, Vertex*v) {
	foreach(it1,u->ids) {
		foreach(it2,v->ids) {
			int a = *it1, b = *it2;
			if (edgeSet.count(make_pair(a, b)))
				continue;
			a1.push_back(a);
			a2.push_back(b);
			edgeSet.insert(make_pair(a, b));
			edgeSet.insert(make_pair(b, a));
			return;
		}
	}
}

bool cmpVertexPtrByCnt(Vertex*a, Vertex*b) {
	return a->cnt < b->cnt;
}

void work() {
	while (comps.size() > 1) {
		Vertex*maxDeg = 0;
		foreach(iter,comps) {
			Vertex*u = *iter;
			if (maxDeg == 0 || u->adj.size() > maxDeg->adj.size())
				maxDeg = u;
		}
		Vertex*L, *R;
		if (comps.size() == 2) {
			L = comps[0], R = comps[1];
		} else {
			maxDeg->cnt = 0;
			vector<Vertex*> leafs;
			foreach(iter,maxDeg->adj) {
				Vertex*v = *iter;
				v->cnt = 0;
				leafs.push_back(v->dfs2(maxDeg));
			}
			//			cout << leafs.size() << endl;
			sort(leafs.begin(), leafs.end(), cmpVertexPtrByCnt);
			L = leafs.back(), R = leafs[leafs.size() - 2];
		}
		addAns(L, R);
		buildEdge(L, R);
		if (comps.size() == 2) {
			break;
		}
		vector<Vertex*> oldComps = comps;
		buildComps(oldComps);
	}

	printf("%d\n", a1.size());
	for (int i = 0; i < a1.size(); ++i) {
		printf("%d %d\n", a1[i], a2[i]);
	}
}

void solve() {
	readInput();
	if (nVs == 2) {
		puts("-1");
		return;
	}
	buildComps(vs);
	work();
}

int main() {
	solve();
}