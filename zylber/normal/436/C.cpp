#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

#define forn(a,n) for(int a = 0; a<(n); ++a)
#define forsn(a,s,n) for(int a = (s); a<(n); ++a)
#define forall(a,all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)

int n, m, k, w;

string mapas[1004][16];

int padre[1004];

int f(int a){
    if(padre[a] == -1)
        return a;
    padre[a] = f(padre[a]);
    return padre[a];
}

void u(int a, int b){
    padre[f(a)] = b;
}

int d(int a, int b){
    int ret = 0;
    
    forn(i,n) forn(j,m) if(mapas[a][i][j] != mapas[b][i][j])
        ret++;
    return ret;
}

vector<int> ady[1004];

void dfs(int nodo, int ant){
    if(ant != -1){
        cout << nodo << " " << ant << endl;
    }
    
    forn(i, ady[nodo].size()) if(ant != ady[nodo][i]){
        dfs(ady[nodo][i], nodo);
    }
}

int main() {
#ifdef ACMTUYO
    freopen("a.in", "r", stdin);
#endif
    cin >> n >> m >> k >> w;
    
    forn(i,k){
        forn(j,n) cin >> mapas[i][j];
    }
    
    vector<pair<int, pair<int, int> > > dists;
    forn(i,k) forsn(j, i+1, k){
        dists.push_back(make_pair(d(i,j)*w, make_pair(i+1,j+1)));
    }
    forn(i,k){
        dists.push_back(make_pair(n*m, make_pair(0,i+1)));
    }
    
    memset(padre,-1,sizeof(padre));
    
    sort(dists.begin(), dists.end());
    
    int ret = 0;
    forn(i,k) ady[i].clear();
    forn(i, dists.size()) {
        int a = dists[i].second.first, b = dists[i].second.second;
        if(f(a) != f(b)){
            u(a, b);
            
            ady[a].push_back(b);
            ady[b].push_back(a);
            ret += dists[i].first;
        }
    }
    
    cout << ret << endl;
    
    dfs(0, -1);
    return 0;
}