#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
typedef long long tint;
using namespace std;
#define MUCHO 1000000000

struct nodo{
	tint v;
	int izq;
	int der;
};

struct pst{
	vector<int> roots;
	vector<nodo> nodos;
	int n;
};

pst init(int n) {
	pst tree;
	tint k = 1;
	while(k<n) k*=2;
	tree.nodos.resize(2*k);
	tree.roots.push_back(1);
	tree.n = k;
	forn(i, 2*k) {
		tree.nodos[i].v = MUCHO;
		if(i<=k) {
			tree.nodos[i].izq = 2*i;
			tree.nodos[i].der = 2*i+1;
		} else {
			tree.nodos[i].izq = -1;
			tree.nodos[i].der = -1;
		}
	}
	return tree;
}

void update(pst& tree, tint p, tint v) {
	vector<int> camino;
	int act = tree.roots[tree.roots.size()-1];
	int l = 0, r = tree.n;
	while(r-l > 1) {
		camino.push_back(act);
		if(p < (r+l)/2) {
			act = tree.nodos[act].izq;
			r = (r+l)/2;
		} else {
			act = tree.nodos[act].der;
			l = (r+l)/2;
		}
		
	}
	nodo nnodo;
	nnodo.v = v;
	nnodo.izq = -1;
	nnodo.der = -1;
	tree.nodos.push_back(nnodo);
	dforn(i, camino.size()) {
		nnodo = tree.nodos[camino[i]];
		nnodo.v = min(nnodo.v, v);
		if(p%2) {
			nnodo.der = tree.nodos.size()-1;
		} else {
			nnodo.izq = tree.nodos.size()-1;
		}
		tree.nodos.push_back(nnodo);
		p/=2;
	}
	tree.roots.push_back(tree.nodos.size()-1);
}

tint get(pst& tree, int act, int l, int r, int a, int b) {
	if(a>=l && b<=r) return tree.nodos[act].v;
	if(b<=l || a>=r) return MUCHO;
	
	int c = (a+b)/2;
	return min(get(tree, tree.nodos[act].izq, l, r, a, c), get(tree, tree.nodos[act].der, l, r, c, b));
}

tint get(pst& tree, int l, int r, int t) {
	return get(tree, tree.roots[t], l, r, 0, tree.n);
}

void dfs(int act, int p, vector<int>& rec, vector<vector<int>>& grafo) {
	rec.push_back(act);
	forn(i, grafo[act].size()) {
		if(grafo[act][i]!=p) {
			dfs(grafo[act][i], act, rec, grafo);
		}
	}
	rec.push_back(act);
}

int main()
{
	int n, r;
	scanf("%d %d", &n, &r);
	vector<vector<int> > grafo(n);
	vector<int> pesos(n);
	forn(i, n) {
		scanf("%d", &(pesos[i]));
	}
	
	forn(i, n-1) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}
	
	vector<int> nodos;
	dfs(r-1, -1, nodos, grafo);
	vector<vector<int> > pos(n);
	forn(i, nodos.size()) {
		pos[nodos[i]].push_back(i);
	}
	
	
	pst tree = init(nodos.size());
	vector<int> dist(n, -1);
	vector<int> ts;
	dist[r-1] = 0;
	queue<int> bfs;
	bfs.push(r-1);
	int actd = 0;
	while(!bfs.empty()) {
		int act = bfs.front();
		if(dist[act] > actd) {
			ts.push_back(tree.roots.size()-1);
		}
		actd = dist[act];
		
		forn(i, pos[act].size()) {
			update(tree, pos[act][i], pesos[act]);
		}
		
		forn(i, grafo[act].size()) {
			int next = grafo[act][i];
			if(dist[next] == -1) {
				bfs.push(next);
				dist[next] = dist[act]+1;
			}
		}
		bfs.pop();
	}
	ts.push_back(tree.roots.size()-1);
	int m;
	scanf("%d", &m);
	tint last = 0;
	forn(i, m) {
		tint p, q;
		scanf("%I64d %I64d", &p, &q);
		tint x = (p+last)%n, k = (q+last)%n;
		k += dist[x];
		k = min(k, (tint) ts.size()-1);
		last = get(tree, pos[x][0], pos[x][1], ts[k]);
		printf("%I64d\n",last);
	}
    return 0;
}