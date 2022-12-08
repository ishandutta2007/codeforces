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

int ans[64];

int main()
{
#ifdef ACMTUYO
    freopen("B.in","r",stdin);
#endif

    tint n, m;
    cin >> n >> m;
    m--;
    
    tint r=1LL<<(n-1);
    
    int i1=0, i2=n-1;
    forn(i, n)
    {
        r/=2;
        if(m<r)
        {
            ans[i1]=i+1;
            i1++;
        }
        else
        {
            ans[i2]=i+1;
            i2--;
            m-=r;
        }
    }
    
    forn(i, n)
    {
        if(i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}