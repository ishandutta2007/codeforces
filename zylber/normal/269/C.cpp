#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>
#include <queue>
#include <vector>
#include <map>
using namespace std;

#define forn(a,n) for(int a = 0; a<(n); ++a)
#define forsn(a,s,n) for(int a = (s); a<(n); ++a)
#define dforn(a,n) for(int a = (n)-1; a>=0; --a)

#define forall(a,all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)

#define MAXN 200004

typedef long long tint;

int n,m;
tint falta[MAXN];

vector<pair<int,tint> > ady[MAXN];
map<pair<int,int>, int> dicc;
pair<int,int> eje[MAXN];
int doyVuelta[MAXN];

int main()
{
#ifdef ACMTUYO
    freopen("test.in", "r", stdin);
#endif
    
    scanf("%i%i",&n,&m);
    dicc.clear();
    
    forn(i,n){ ady[i].clear();}
    forn(i,m) doyVuelta[i] = -1;
    forn(i,m){
        int a, b;
        tint c;
        cin >> a >> b >> c;
        a--; b--;
        ady[a].push_back(make_pair(b,c));
        ady[b].push_back(make_pair(a,c));
        eje[i] = make_pair(a,b);
        dicc[make_pair(min(a,b),max(a,b))] = i;
    }
    
    forn(i,n){
        tint suma = 0;
        forn(j,ady[i].size()) suma += ady[i][j].second;
        falta[i] = suma/2;
    }
    
    queue<int> proc;
    proc.push(0);
    falta[0] = falta[n-1] = -1;
    while(!proc.empty()){
        int nodo = proc.front(); proc.pop();
        //cout << "Nodo: " << nodo << endl;
        forn(i,ady[nodo].size()){
            //cout << "Veo " << ady[nodo][i].first << endl;
            int a = nodo, b = ady[nodo][i].first;
            if(a>b) swap(a,b);
            int posEje = dicc[make_pair(a,b)];
            int &vuelta = doyVuelta[posEje];
            //cout << posEje << endl;
            if(vuelta != -1) continue;

            if(eje[posEje].first != nodo)
                vuelta = 1;
            else
                vuelta = 0;
            
           // cout << falta[ady[nodo][i].first] << endl;
            falta[ady[nodo][i].first] -= ady[nodo][i].second;
           // cout << falta[ady[nodo][i].first] << endl;
            if(falta[ady[nodo][i].first] == 0)
                proc.push(ady[nodo][i].first);
        }
    }
    
    //cout << "IMPRIME" << endl;
    forn(i,m) cout << doyVuelta[i] << endl;
    
    return 0;
}