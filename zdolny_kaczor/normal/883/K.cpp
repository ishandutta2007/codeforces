#include<bits/stdc++.h>
#define PII pair<int,int>
#define f first
#define s second
#define VI vector<int>
#define LL long long
#define MP make_pair
#define LD long double
#define PB push_back
#define ALL(V) V.begin(),V.end()
#define abs(x) max((x),-(x))
#define PDD pair<LD,LD> 
#define VPII vector< PII > 
#define siz(V) ((int)V.size())
#define FOR(x, b, e)  for(int x=b;x<=(e);x++)
#define FORD(x, b, e) for(int x=b;x>=(e);x--)
#define REP(x, n)     for(int x=0;x<(n);x++)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#ifdef DEB 
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
using namespace std;
const int MN = 2e5 + 44;
int s[MN], g[MN], b[MN];
int main()
{
    int n;
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", s + i, g + i);
    b[0] = s[0] + g[0];
    FOR(i, 1, n)
        b[i] = min(b[i - 1] + 1, s[i] + g[i]);
    mini(b[n - 1], s[n - 1] + g[n - 1]);
    FORD(i, n - 2, 0)
        mini(b[i], min(b[i + 1] + 1, s[i] + g[i]));
    REP(i, n) {
        if (b[i] < s[i]) {
            printf("-1\n");
            return 0;
        }
    }
    LL ans = 0;
    REP(i, n) {
        ans += b[i] - s[i];
    }
    printf("%lld\n", ans);
    REP(i, n) printf("%d ", b[i]);
}