#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e5 + 5, P = 130;
struct people
{
    LL a, s[7];
    bool operator < (const people &oth) const { return a > oth.a; }
} peo[N];
int n, p, k;
inline int CountBit(int x)
{
    int res = 0;
    while(x) res++, x &= x - 1;
    return res;
} 
LL f[N][P];
int main()
{
    scanf("%d %d %d", &n, &p, &k);
    for(int i = 1; i <= n; i++) scanf("%lld", &peo[i].a);
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < p; j++)
            scanf("%lld", &peo[i].s[j]);
    sort(peo + 1, peo + n + 1);
    int full = 1 << p;
    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < full; j++)
        {
            int cnt = CountBit(j);
            f[i][j] = f[i - 1][j];
            if(i <= cnt + k) f[i][j] = max(f[i][j], f[i - 1][j] + peo[i].a);
            for(int t = 0; t < p; t++) if(j >> t & 1)
                f[i][j] = max(f[i][j], f[i - 1][j ^ (1 << t)] + peo[i].s[t]);
        }
    }
    printf("%lld\n", f[n][full - 1]);
    return 0;
}