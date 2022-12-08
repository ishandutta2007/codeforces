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

int perm[310];
string grafo[310];

int compo[310];

int n;
void dfs(int a, int c)
{
    compo[a]=c;
    forn(i, n)
    {
        if(grafo[a][i]=='1' && compo[i]==-1) dfs(i, c);
    }
}

int main()
{
#ifdef ACMTUYO
    freopen("B.in","r",stdin);
#endif
    cin >> n;
    forn(i, n) cin >> perm[i];
    
    forn(i, n) cin >> grafo[i];
    
    memset(compo,-1,sizeof(compo));
    int compon=0;
    forn(i, n)
    {
        if(compo[i]==-1)
        {
            dfs(i, compon);
            compon++;
        }
    }
    
    //forn(i, n) cout << compo[i] << endl;
    
    forn(i, n)
    {
        int mini=i;
        for(int j=i; j<n; j++)
        {
            if(compo[j]==compo[i] && perm[mini]>perm[j]) mini=j;
        }
        
        if(i!=mini)
        swap(perm[i], perm[mini]);
    }
    
    forn(i,n)
    {
        if(i) cout << " ";
        cout << perm[i];
    }
    cout << endl;
    
    return 0;
}