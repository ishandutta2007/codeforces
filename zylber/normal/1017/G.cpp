// C++11
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <sys/time.h>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
#define GETT(i, j) get(i, j, n, k, board, mask)
typedef long long tint;
using namespace std;

struct eje{
    int nodo, caminoact, caminomax;
};

void compress(int act, vector<int>& queried, vector<int>& color, vector<vector<int>>& grafo, eje cand, vector<vector<eje>>& res) {
    if(queried[act]) {
        int pad = cand.nodo;
        cand.nodo = act;
        if(pad != -1) res[pad].push_back(cand);
        cand.caminoact = 0;
        cand.caminomax = 0;
    }
    
    cand.caminomax++;
    if(color[act] == 0) cand.caminoact++;
    
    for(auto v: grafo[act]) {
        compress(v, queried, color, grafo, cand, res);
    }
}   

void propagate(vector<vector<eje>>& grafored, int act, vector<int>& color, vector<int>& prof) {
    color[act] = 1;
    prof[act]++;
    for(auto &e: grafored[act]) {
        e.caminoact--;
        if(e.caminoact < 0) {
            propagate(grafored, e.nodo, color, prof);
        }
    }
}

void clear(vector<vector<eje>>& grafored, int act, vector<int>& color, vector<int>& prof, vector<int>& cleared) {
    prof[act] = 0;
    cleared[act] = 1;
    color[act] = 0;
    for(auto &e: grafored[act]) {
        e.caminoact = e.caminomax;
        clear(grafored, e.nodo, color, prof, cleared);
    }
}

void batchpaint(int act, vector<vector<int>>& grafo, vector<int>& prof, vector<int>& clrd, vector<int>& color, vector<int>& queried, int curprof, int curclrd) {
    if(queried[act]) {
        if(clrd[act]) curclrd = 1;
        curprof = prof[act];
    }
    
    if(curclrd) color[act] = 0;
    if(color[act] == 0) if(curprof) {
        color[act] = 1;
        curprof--;
    }
    
    for(auto v: grafo[act]) {
        batchpaint(v, grafo, prof, clrd, color, queried, curprof, curclrd);
    }
}

void process(vector<vector<int>>& grafo, vector<int>& color, vector<pair<int, int>>& batch) {
    int n = grafo.size();
    vector<int> queried(n, 0);
    forn(i, batch.size()) queried[batch[i].second] = 1;
    //cout << "BATCH: " << batch.size() << endl;
    //forn(i, batch.size()) cout << batch[i].first << " " << batch[i].second << endl;
    
    eje cand;
    cand.nodo = -1;
    vector<vector<eje>> grafored(n);
    compress(0, queried, color, grafo, cand, grafored);
    vector<int> prof(n, 0);
    vector<int> clrd(n, 0);
    vector<int> ccolor = color;
    forn(i, batch.size()) {
        if(batch[i].first == 1) {
            propagate(grafored, batch[i].second, ccolor, prof);
        }
        
        if(batch[i].first == 2) {
            clear(grafored, batch[i].second, ccolor, prof, clrd);
        }

        if(batch[i].first == 3) {
            if(ccolor[batch[i].second]) {
                printf("black\n");
            } else {
                printf("white\n");
            }
        }
    }
    
    batchpaint(0, grafo, prof, clrd, color, queried, 0, 0);
    //forn(i, n) cout << color[i] << " ";
    //cout << endl;
    
}

int main() {
	//freopen("gen.out", "r", stdin);
    int n, q;
    scanf("%d %d", &n, &q);
    
    vector<vector<int>> grafo(n);
    forn(i, n-1) {
        int a;
        scanf("%d", &a);
        a--;
        grafo[a].push_back(i+1);
    }
       
    int bs = 0;
    while(bs*bs < q) bs++;
    
    vector<int> color(n, 0);
    vector<pair<int, int> > batch;
    forn(i, q) {
	int t, v;
	cin >> t >> v;        
	v--;	
	batch.push_back({t,v});
        if((i+1)%bs == 0 or i == q-1) {
            process(grafo, color, batch);
            batch.clear();
        }
    }
}