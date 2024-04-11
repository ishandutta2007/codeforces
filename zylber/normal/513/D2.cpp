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

int app[1000010];

int arr[1000010];
int back[1000010];
int forth[200010];
int visited[200010];


typedef tint tipo;
#define LVL 18
tipo vec[LVL][1<<LVL];
tipo mn(int i, int j) { // intervalo [i,j)
    if(i==j) return 0;
    int p = 31-__builtin_clz(j-i);
    return max(vec[p][i],vec[p][j-(1<<p)]);
}
void mn_init(int n) {
    int mp = 31-__builtin_clz(n);
    forn(p, mp) forn(x, n-(1<<p)) vec[p+1][x] = max(vec[p][x], vec[p][x+(1<<p)]);
}

vector<vector<pair<int, int> > > grafo;

struct caso{
    int a, b, start;
    caso(int aa, int bb, int c)
    {
        a=aa;
        b=bb;
        start=c;
        //root=r;
    }
};

int main()
{
#ifdef ACMTUYO
    freopen("D.in","r",stdin);
#endif

    int n, c;
    cin >> n >> c;
    grafo.resize(n);
    
    int rompe=0;
    forn(i, c)
    {
        int a, b;
        string s;
        cin >> a >> b >> s;
        a--; b--;
        if(a>=b) rompe=1;
        int d=0;
        if(s=="RIGHT") d++;
        grafo[a].push_back(make_pair(b, d));
        grafo[b].push_back(make_pair(a, d));
    
        app[a]=1;
        app[b]=1;
    }
    
    int ia=0;
    forn(i, n)
    {
        back[i]=ia; 
        if(app[i]){ forth[ia]=i; ia++; }
    }
    
    
    if(rompe)
    {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    dforn(i, ia)
    {
        int r=forth[i];
        vec[0][i]=r;
        int vs=grafo[r].size();
        forn(j, vs)
        {
            if(grafo[r][j].first>r) vec[0][i]=max(vec[0][i], vec[0][back[grafo[r][j].first]]);
        }
        //cout << i << " " << vec[0][i] << endl;
    }
    
    mn_init(ia);
    
    queue<caso> cola;
    caso s(0, n, 0);
    cola.push(s);
    
    while(!cola.empty())
    {
        caso act=cola.front();
        //cout << act.a << " " << act.b << " " << act.start << endl;
        
        if(act.a<act.b)
        {
            if(!app[act.a]) 
            {
                arr[act.start]=act.a+1;
                caso nc(act.a+1, act.b, act.start+1);
                cola.push(nc);
            }
            else
            {
                int vs=grafo[act.a].size();
                int ml=act.a, mr=act.b;
                forn(j, vs)
                {
                    if(grafo[act.a][j].first>act.a)
                    {
                        if(grafo[act.a][j].second)
                            mr=min(mr, grafo[act.a][j].first);
                        else
                            ml=max(ml, grafo[act.a][j].first);
                    }
                }
                
                
                    if(ml!=act.a)
                    while(ml<mr && ml<mn(back[act.a]+1, back[ml]+1)) ml=mn(back[act.a]+1, back[ml]+1);
                
                //cout << ml << " " << mr << endl;
                
                    if(ml>=mr)
                    {
                        cout << "IMPOSSIBLE" << endl;
                        return 0;
                    }
                    
                    arr[ml+act.start-act.a]=act.a+1;
                    
                    caso nc1(act.a+1, ml+1, act.start);
                    caso nc2(ml+1, act.b, ml+act.start-act.a+1);
                    cola.push(nc1);
                    cola.push(nc2);
                
                
            }
        }
        
        cola.pop();
    }
    
    forn(i, n)
    {
        if(i) printf(" ");
        printf("%i", arr[i]);
    }
    cout << endl;
    
    return 0;
}