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

void buscarComponentes(int nodo, vector<int> &indices, vector<vector<int> >& componentes, vector<vector<pair<tint,tint>>> &grafo, vector<int> &lowLink, vector<int> &nodos, vector<int> &apilado, stack<int> &pila) {
	int actual = nodos.size();
	indices[nodo] = actual;
	nodos.push_back(nodo);
	lowLink[nodo] = actual;
	pila.push(nodo);
	apilado[nodo] = true;
	
	forn(i, grafo[nodo].size()) {
		int siguiente = grafo[nodo][i].first;
		if(indices[siguiente] == -1) {
			buscarComponentes(siguiente, indices, componentes, grafo, lowLink, nodos, apilado, pila);
			lowLink[nodo] = min(lowLink[nodo], lowLink[siguiente]);
		} else if(apilado[siguiente]) {
			lowLink[nodo] = min(lowLink[nodo], indices[siguiente]);
		}
	}
	
	if(lowLink[nodo] == indices[nodo]) {
		vector<int> nuevaComponente;
		while(apilado[nodo]) {
			int proximo = pila.top();
			nuevaComponente.push_back(proximo);
			apilado[proximo] = false;
			pila.pop();
		}
		componentes.push_back(nuevaComponente);
	}
}

vector<vector<int> > tarjan(vector<vector<pair<tint,tint>>> &grafo) {
	int n = grafo.size();
	vector<int> indices(n, -1);
	vector<vector<int> > componentes; 
	vector<int> lowLink(n, -1);
	vector<int> nodos;
	vector<int> apilado(n, 0);
	stack<int> pila;
			
	forn(i, n) {
		if(indices[i] == -1) {
			buscarComponentes(i, indices, componentes, grafo, lowLink, nodos, apilado, pila);
		}
	}
	
	return componentes;
}

tint calcMush(tint n, vector<tint>& ss) {
	tint top = ss.size(), bot = 0;
	while(top-bot>1) {
		tint mid=(top+bot)/2;
		if(mid*(mid+1)<=2*n) {
			bot = mid;
		} else {
			top = mid;
		}
	}
	return top*n - ss[bot];
}

tint calcdp(tint i, vector<tint>& pesos, vector<vector<pair<tint,tint>>>& grafRed, vector<tint>& dp) {
	if(dp[i] != -1) return dp[i];
	dp[i] = pesos[i];
	forn(j, grafRed[i].size()) {
		dp[i] = max(dp[i], pesos[i]+grafRed[i][j].second+calcdp(grafRed[i][j].first, pesos, grafRed, dp));
	}
	return dp[i];
}

int main()
{
	tint n, m;
	scanf("%I64d %I64d", &n, &m);
	vector<vector<pair<tint, tint> > > grafo(n);
	forn(i, m) {
		tint x, y, w;
		scanf("%I64d %I64d %I64d", &x, &y, &w);
		x--; y--;
		grafo[x].push_back({y,w});
	}
	vector<vector<int> > scc = tarjan(grafo);
	
	vector<tint> ss(1,0);
	tint start = 1;
	while(start*(start+1)<200000010LL) {
		ss.push_back(ss[start-1]+(start*(start+1))/2);
		start++;
	}
	
	vector<tint> comp(n);
	//forn(i,100) cout << i << " " << calcMush(i, ss) << endl;
	
	
	forn(i, scc.size()) forn(j, scc[i].size()) {
		comp[scc[i][j]] = i;
	}
	
	vector<vector<pair<tint,tint>>> grafRed(scc.size());
	vector<tint> pesos(scc.size(),0);
	forn(i, n) forn(j, grafo[i].size()) {
		if(comp[i]!=comp[grafo[i][j].first]) {
			grafRed[comp[i]].push_back({comp[grafo[i][j].first],grafo[i][j].second});
		} else {
			pesos[comp[i]]+=calcMush(grafo[i][j].second, ss);
		}
	}
	
	int s;
	cin >> s;
	vector<tint> dp(scc.size(), -1);
	
	cout << calcdp(comp[s-1], pesos, grafRed, dp) << endl;
}