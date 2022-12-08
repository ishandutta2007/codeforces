#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define forsn(a, s, n) for(int a = (s); a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define eps 0.000000000001
#define BIG 10000000000LL
typedef long long tint;
using namespace std;

#define LVL 20
int vec[LVL][1<<(LVL+1)];
int mn(int i, int j) { // intervalo [i,j)
	int p = 31-__builtin_clz(j-i);
	return min(vec[p][i],vec[p][j-(1<<p)]);
}
void mn_init(int n) {
	int mp = 31-__builtin_clz(n);
	forn(p, mp) forn(x, n-(1<<p)) vec[p+1][x] = min(vec[p][x], vec[p][x+(1<<p)]);
}

int p[1<<(LVL+1)]; // primera aparicion del nodo, se rellena solo
int n2n[1<<(LVL+1)]; // que nodo esta asociado a un numero, se rellena solo
int cont_nodos, ulti_pos;
void dfsl(int nodo, int padre, vector<vector<int>>& grafo){
    int val = cont_nodos++;
    p[nodo] = ulti_pos; n2n[val] = nodo;
    vec[0][ulti_pos++] = val;
    forn(i,grafo[nodo].size()) if (grafo[nodo][i] != padre){
        dfsl(grafo[nodo][i],nodo,grafo);
        vec[0][ulti_pos++] = val;
    }
}
void lca_init(int root, vector<vector<int>>& grafo){
    cont_nodos = 0; ulti_pos = 0;
    dfsl(root, -1,grafo);
    mn_init(ulti_pos);
}
int lca(int i, int j){
    return n2n[mn(min(p[i],p[j]),max(p[i],p[j])+1)];
}

void dfs(int i, vector<vector<int>>& grafo, vector<int>& visited, int cc) {
	visited[i] = cc;
	for(auto j: grafo[i]) if(visited[j] == -1) dfs(j, grafo, visited, cc);
}

void dfsp(int i, vector<vector<int>>& grafo, vector<int>& p) {
	for(auto j: grafo[i]) if(j != p[i]) {
		p[j] = i;
		dfsp(j, grafo, p);
	}
}

int cl(int i, vector<int>& compo) {
	return (compo[i] == i ? i : compo[i] = cl(compo[i], compo)); 
}

void join(int i, int j, vector<int>& compo) { 
	if(cl(i, compo)!=cl(j, compo)) compo[cl(i, compo)] = cl(j, compo); 
}

int main() {
	int n, k, m;
	
	scanf("%d %d %d", &n, &k, &m);
	vector<vector<int>> grafo(n);
	forn(i, k) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--; b--;
		grafo[a].push_back(b);
		grafo[b].push_back(a);
	}
	
	vector<pair<int,pair<int,int>>> queries;
	
	forn(i, m) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--; b--;
		queries.push_back({c,{a,b}});
	}
	
	sort(queries.begin(), queries.end());
	
	vector<int> compo(n, -1);
	forn(i, n) {
		if(compo[i] == -1) {
			dfs(i, grafo, compo, i);
		}
	}
	
	tint res = 0;
	for(auto t: queries) {
		int a = t.second.first, b = t.second.second;
		if(cl(a, compo) != cl(b, compo)) {
			join(a, b, compo);
			res -= t.first;
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}
	}
	
	lca_init(0, grafo);
	vector<int> p(n, 0);
	dfsp(0, grafo, p);
	forn(i, n) compo[i] = i;
	for(auto t: queries) {
		int a = t.second.first, b = t.second.second, c = lca(a, b);
		a = cl(a, compo), b = cl(b, compo);
		while(a != cl(c, compo)) {
			res += t.first;
			join(a, p[a], compo);
			a = cl(a, compo);
		}
		while(b != cl(c, compo)) {
			res += t.first;
			join(b, p[b], compo);
			b = cl(b, compo);
		}
	}
	
	forn(i, n) if(cl(i, compo) != cl(0, compo)) {
		res = -1;
	}
	cout << res << endl;
}