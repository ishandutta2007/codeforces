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

int res[10];

int main()
{
#ifdef ACMTUYO
    freopen("B.in","r",stdin);
#endif

    int n;
    cin >> n;
    
    int pot=1;
    while(n>0)
    {
        int a=n%10;
        forn(i, a) res[i]+=pot;
        n/=10;
        pot*=10;
    }
    
    int tot=0;
    while(res[tot]) tot++;
    cout << tot << endl;
    forn(i, tot)
    {
        if(i) cout << " ";
        cout << res[i];
    }
    cout << endl;
    
    return 0;
}