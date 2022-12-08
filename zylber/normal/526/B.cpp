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

int up[4096];
int largo[4096];

int main()
{
#ifdef ACMTUYO
    freopen("B.in","r",stdin);
#endif

    int n;
    cin >> n;
    forn(i, (1<<(n+1))-2) cin >> up[i+2];
    
    for(int i=(1<<(n+1)); i>1; i--)
    {
        largo[i/2]=max(largo[i/2], largo[i]+up[i]);
    }
    
    int ans=0;
    for(int i=1; i<=(1<<n); i++)
    {
        ans+=abs(largo[2*i]+up[2*i]-largo[2*i+1]-up[2*i+1]);
    }
    cout << ans << endl;
    
    return 0;
}