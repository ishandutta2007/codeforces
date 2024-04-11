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

#define INF 1000000000 // Infinito de FLUJO
#define DINF INF // Infinito de distancia
#define MAX_M 90000 // Maximo de aristas
#define MAX_N 300 // Maximo de nodos
int v[2*MAX_M], l[2*MAX_M]; // Vecino, link. link te tira el indice de la arista "al reves" asociada en la lista del vecino.
long c[2*MAX_M]; // Capacidad
int sz[MAX_N], po[MAX_N], r[MAX_N], n, S, T;
typedef map<int,long> Mii;
Mii CAP[MAX_N];
void iniG() {
    n = 0;
    memset(sz,0,sizeof(sz));
    forn(i,MAX_N) CAP[i].clear();
}

void aEje(int d,int h,long cap) {
    if (d == h) return; // Ignoramos completamente autoejes, obvio :D
    n = max(n,max(d,h));
    pair<Mii::iterator,bool> par = CAP[d].insert(make_pair(h,0));
    if (par.second) {
        CAP[h][d] = 0;
        sz[d]++;
        sz[h]++;
    }
    par.first->second += max(cap,(long)0);
}

void _aEje(int d,int h,long capDH, long capHD) {
#define ASIG(d,h,cap) {v[po[d]] = h; c[po[d]] = cap; l[po[d]] = po[h];}
    ASIG(d,h,capDH);
    ASIG(h,d,capHD);
    po[d]++; po[h]++;
}

void _iniG() {
    po[0] = 0;
    forn(i,n-1) po[i+1] = po[i] + sz[i];
    forn(u,n) forall(v,CAP[u])
    if (u < v->first) _aEje(u,v->first,v->second,CAP[v->first][u]);
}

long aumentar() {
// bfs
    forn(i,n) r[i] = DINF;
    r[T] = 0;
    static int q[MAX_N];
    int qf = 0, qb = 0;
    q[qb++] = T;
    while (qb != qf) {
        int x = q[qf++];
        int d = r[x] + 1, b = po[x];
        if (r[S] < DINF) break;
        for(int j=b; j<b+sz[x]; j++)
        if (c[l[j]]>0 && r[v[j]] == DINF) {
            r[v[j]] = d;
            q[qb++] = v[j];
        }
    }
// dfs que hace la magia :P
    long res = 0;
    static int path[MAX_N]; path[0] = S;
    static int p[MAX_N],ind[MAX_N];
    forn(i,n) p[i] = -1;
    int pp = 0; // Path pointer, es la longitud
    while (pp >= 0) {
        int x = path[pp];
        if (x == T) { // Llegamo, hay que hacer magia. O sea, ajustar todas las capacidades a lo largo del caminito que se satura.
            long f = INF;
            int pri = 0;
            dforn(i,pp) if (c[ind[i]]<=f) f = c[ind[i]], pri = i;
            forn(i,pp) c[ind[i]] -= f, c[l[ind[i]]] += f;
            res += f;
            pp = pri;
        }
        else if (++p[x] < sz[x]) {
            int j = po[x]+p[x];
            if (p[v[j]] < 0 && c[j] > 0 && r[v[j]] < r[x])
            ind[pp] = j, path[++pp] = v[j];
        }
        else pp--;
    }
    return res;
}

long flujo(int ss,int tt) {
    S = ss; T = tt;
    n = max(n,max(S,T)) + 1; // Aca, n ya tiene el valor posta
    _iniG();
    forn(i,n) po[i] -= sz[i];
    long res = 0,c;
    do {res += (c = aumentar());} while (c>0);
    return res;
}


int nums[256];
int ady[256][256];
int ida[256], vuelta[256];
int added[256];
vector<vector<int> > mesas;

int main()
{
#ifdef ACMTUYO
    freopen("C.in","r",stdin);
#endif

    int n;
    cin >> n;
    forn(i, n)
    {
        cin >> nums[i];
    }
    
    int odd=0;
    forn(i, n)
    {
        if(nums[i]%2) odd++;
    }
    
    if(odd*2!=n)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    
    int io=0, ie=odd;
    forn(i, n)
    {
        if(nums[i]%2)
        {
            ida[i]=io;
            vuelta[io]=i;
            io++;
        }
        else
        {
            ida[i]=ie;
            vuelta[ie]=i;
            ie++;
        }
        //cout << i << " " << ida[i] << endl;
    }
    
    forn(i, n)
        forn(j, n)
        {
            int goal=nums[i]+nums[j], anda=1;
            for(int d=2; d*d<=goal; d++)
            {
                if(goal%d==0)
                {
                    anda=0;
                    break;
                }
            }
            //cout << i << " " << j << " " << goal << " " << anda << endl;
            if(anda) ady[ida[i]][ida[j]]=1;
        }
    /*forn(i, n)
        forn(j, n)
            if(ady[ida[i]][ida[j]]) cout << i << " " << j << endl;*/
    
    iniG();
    
    forn(i, odd){ aEje(n, i, 2); aEje(i+odd, n+1, 2); }
    
    forn(i, odd)
        forn(j, odd)
        {
            if(ady[i][j+odd]){ aEje(i, j+odd, 1); }
        }
    
    int res=flujo(n, n+1);
    //cout << res << endl;
    
    if(res!=n)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    
    forn(i, n)
    if(!added[i])
    {
        vector<int> nmesa;
        int vengo=-1, act=i;
        while(added[act]!=1)
        {
            //cout << act << " " << vuelta[act] << endl;
            added[act]=1;
            nmesa.push_back(vuelta[act]+1);
            
            int pact=act;
            for(int k=po[pact]; k<po[pact]+sz[pact]; k++)
            {
                //cout << pact << " " << v[k] << " " << c[k] << endl;
                if(c[k]==(pact>=odd) && v[k]<n && v[k]!=vengo)
                {
                    act=v[k];
                }
            }
            vengo=pact;
        }
        mesas.push_back(nmesa);
    }
    
    int ms=mesas.size();
    cout << mesas.size() << endl;
    forn(i, ms)
    {
        int as=mesas[i].size();
        cout << as;
        forn(j, as)
        {
            cout << " ";
            cout << mesas[i][j];
        }
        cout << endl;
    }
    return 0;
}