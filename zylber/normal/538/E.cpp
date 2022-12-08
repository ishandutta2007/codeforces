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

vector<vector<int> > grafo;

int bestResultMax(int i, int player, int father)
{
    int vs=grafo[i].size();
    if((vs==1 && i!=0) || vs==0) return 1;
    
    int best;
    if(player==0)
    {
        best=2000000;
        forn(k, vs)
        {
            int j=grafo[i][k];
            if(j!=father)
                best=min(best, bestResultMax(j, 1, i));
        }
    }
    else
    {
        best=0;
        forn(k, vs)
        {
            int j=grafo[i][k];
            if(j!=father)
                best+=bestResultMax(j, 0, i);
        }
    }
    //cout << i << " " << player << " " << father << " " << best << endl;
    return best;
    
}

int main()
{
#ifdef ACMTUYO
    freopen("E.in","r",stdin);
#endif
    int n;
    cin >> n;
    grafo.resize(n);
    
    forn(i, n-1)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    
    int leaves=0;
    forn(i, n)
    {
        int vs=grafo[i].size();
        if((vs==1 && i!=0) || vs==0) leaves++;
    }
    
    int ans1=leaves-bestResultMax(0,0,-1)+1;
    int ans2=bestResultMax(0,1,-1);
    cout << ans1 << " " << ans2 << endl;
    
    return 0;
}