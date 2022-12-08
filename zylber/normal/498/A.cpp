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

struct pto{
    double x, y;
    pto(){};
    pto(double nx, double ny)
    {
        x=nx; y=ny;
    }
    
    pto operator-(pto p)
    {
        pto res(x-p.x, y-p.y);
        return res;
    }
};


double pc(pto a, pto b){ return a.x*b.y-a.y*b.x; }
double pc(pto a, pto b, pto c){ return pc(a-c, b-c); }
long long sg(pto a, pto b, pto c)
{
    double r=pc(a,b,c);
    if(r>EPS) return 1;
    if(r<EPS) return -1;
    return 0;
}

pto sh, su;

int main()
{
#ifdef ACMTUYO
    freopen("A.in","r",stdin);
#endif

    cin >> sh.x >> sh.y >> su.x >> su.y;

    int n;
    cin >> n;
    
    int ans=0;
    forn(i, n)
    {
        double a, b, c;
        cin >> a >> b >> c;
        if(fabs(a)>0.5)
        {
            pto p1(-c/a,0), p2(-(c+b)/a, 1);
            if(sg(sh,p1,p2)!=sg(su,p1,p2)) ans++;
        }
        else
        {
            pto p1(0,-c/b), p2(1, -(c+a)/b);
            if(sg(sh,p1,p2)!=sg(su,p1,p2)) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}