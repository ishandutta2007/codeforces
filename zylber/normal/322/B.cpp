#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <set>
#include <queue>
using namespace std;

#define forn(a,n) for(int a = 0; a<(n); ++a)
#define forsn(a,s,n) for(int a = (s); a<(n); ++a)
#define dforn(a,n) for(int a = (n)-1; a>=0; --a)

#define forall(a,all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)

typedef long long tint;

int main()
{
#ifdef ACMTUYO
    //freopen("test.in", "r", stdin);
#endif
    tint r,g,b;
    
    cin >> r >> g >> b;
    tint res = 0;
    
    for(tint saco = 0; saco<4; ++saco){
        if(min(r,min(g,b)) < saco) continue;
        
        tint c = (r-saco)/3LL + (g-saco)/3LL + (b-saco)/3LL + saco;
        res = max(res,c);
    }
    cout << res << endl;
    
    return 0;
}