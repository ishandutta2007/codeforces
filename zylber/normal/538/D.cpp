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

string tab[64];
string res[128];

int main()
{
#ifdef ACMTUYO
    freopen("D.in","r",stdin);
#endif

    int n;
    cin >> n;
    
    forn(i, n)
    {
        cin >> tab[i];
    }
    
    vector<pair<int, int> > moves;
    for(int dx=-(n-1); dx<=n-1; dx++)
        for(int dy=-(n-1); dy<=n-1; dy++)
        {
            int validmove=1;
            forn(i, n)
                forn(j, n)
                    if(tab[i][j]=='o')
                    {
                        int ni=i+dx, nj=j+dy;
                        if(0<=ni && ni<n && 0<=nj && nj<n && tab[ni][nj]=='.') validmove=0;
                    }
            if(validmove) moves.push_back(make_pair(dx, dy));
        }
        
    int ms=moves.size();
    forn(i,n) forn(j, n) if(tab[i][j]=='x')
    {
        int attacked=0;
        forn(k, ms)
        {
            int ni=i-moves[k].first, nj=j-moves[k].second;
            if(0<=ni && ni<n && 0<=nj && nj<n && tab[ni][nj]=='o') attacked=1;
        }
        if(!attacked)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    
    forn(i, 2*n-1)
        forn(j, 2*n-1)
            res[i]+='.';
            
    forn(i, ms)
        res[moves[i].first+n-1][moves[i].second+n-1]='x';
    
    res[n-1][n-1]='o';
    
    cout << "YES" << endl;
    forn(i, 2*n-1) cout << res[i] << endl;
    
    return 0;
}