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

int main()
{
#ifdef ACMTUYO
    //freopen("199C.in","r",stdin);
#endif
    
    long long r, h;
    cin >> r >> h;
    
    long long ans=(((h*2)/r)+1)/2;
    double rest=h+r-ans*r;
    rest-=sqrt(3)/2.0*r;
    ans*=2;
    if(rest>-EPS) ans++;
    
    
    cout << ans << endl;
    
    return 0;
}