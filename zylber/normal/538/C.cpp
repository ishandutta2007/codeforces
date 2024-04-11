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

int main()
{
#ifdef ACMTUYO
    freopen("C.in","r",stdin);
#endif

    int n, m;
    cin >> n >> m;
    
    int prevd=0, prevh=0, best=0;
    forn(i, m)
    {
        int d, h;
        scanf("%d %d", &d, &h);
        
        if(i==0) best=h+d-1;
        else
        {
            if(d-prevd<abs(h-prevh))
            {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            
            int sobra=d-prevd-abs(h-prevh);
            int alto =max(h, prevh);
            best=max(best, alto+sobra/2);
        }
        prevd=d; prevh=h;
    }
    best=max(best, prevh+n-prevd);
    
    cout << best << endl;
    return 0;
}