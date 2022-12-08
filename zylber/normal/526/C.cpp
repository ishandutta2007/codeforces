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
    tint c, hr, hb, wr, wb;
    cin >> c >> hr >> hb >> wr >> wb;
    
    tint ans=0;
    tint t=max(0LL,c/(wr*wb)-2LL);
    if(wb*hr>=wr*hb) ans+=t*hr*wb; else ans+=t*hb*wr;
    c-=t*wr*wb; 
    
    tint best=0;
    if(wb>wr)
    {
        swap(wb, wr);
        swap(hb, hr);
    }
    
    for(tint i=0; i*wr<=c; i++)
    {
        tint r=(c-i*wr)/wb;
        best=max(best,  r*hb+i*hr);
    }
    
    ans+=best;
    cout << ans << endl;
    
    return 0;
}