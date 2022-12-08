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

#define MAXN 4096
tint choose[MAXN][MAXN];

tint bell[MAXN];

int main()
{
#ifdef ACMTUYO
    //freopen("A.in","r",stdin);
#endif

    forn(i, MAXN)
    {
        choose[i][0]=1;
        if(i==0) continue;
        
        for(int j=1; j<i; j++)
            choose[i][j]=(choose[i-1][j-1]+choose[i-1][j])%MOD;
            
        choose[i][i]=1;
    }
    
    int n;
    cin >> n;
    bell[0]=1;
    bell[1]=1;
    for(int i=2; i<=n; i++)
    {
        for(int j=0; j<i; j++)
        {
            bell[i]+=(choose[i-1][j]*bell[i-j-1])%MOD;
            bell[i]%=MOD;
        }
    }
    
    tint s=0;
    forn(i, n) s=(s+(choose[n][i]*bell[i])%MOD)%MOD;
    cout << s << endl;
    
    return 0;
}