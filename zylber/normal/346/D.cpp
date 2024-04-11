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
using namespace std;

int used[1000010];
int queued[1000010];
int ind[1000010];
int dist[1000010];
queue<int> nodes;
vector<vector<int> > grafo;

void process(int act, int peso)
{
    //cout << act << " " << peso << endl;
    used[act]=1;
    int vs=grafo[act].size();
    forn(i, vs)
    {
        int next=grafo[act][i];
        if(!queued[next])
        {
            nodes.push(next);
            dist[next]=peso+1;
            queued[next]=1;
        }
        ind[next]--;
        if(!ind[next] && !used[next])
        {
            dist[next]=peso;
            process(next, peso);
        }
    }
}

int main()
{
#ifdef ACMTUYO
    freopen("201D.in","r",stdin);
#endif
    int n, m;
    cin >> n >> m;
    grafo.resize(n);
    
    forn(i,m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        
        grafo[b].push_back(a);
        ind[a]++;
    }
    
    int s, t;
    cin >> s >> t;
    s--;
    t--;
    
    nodes.push(t);
    queued[t]=1;
    
    memset(dist,-1,sizeof(dist));
    dist[t]=0;
    
    while(!nodes.empty())
    {
        int act=nodes.front();
        nodes.pop();
        
        if(!used[act]) process(act, dist[act]);
    }
    
    cout << dist[s] << endl;
    
    return 0;
}