#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 998244353; 
LL qpow(LL a, LL p)
{
    if(a == 0) return 0;
    LL res = 1;
    while(p)
    {
        if(p & 1) res = res * a % MOD;
        a = a * a % MOD;
        p >>= 1;
    }
    return res;
}
int main()
{
    LL n, m, l, r;
    cin >> n >> m >> l >> r; 
    if(n * m & 1) cout << qpow((r - l + 1) % MOD, n * m % (MOD - 1)) << endl;
    else
    {
        LL E = (r >> 1) - (l - 1 >> 1);
        LL O = r - l + 1 - E;
        cout << ((qpow((O + E) % MOD, n * m % (MOD - 1)) + qpow((O - E + MOD) % MOD, n * m % (MOD - 1))) * 499122177 % MOD) << endl; // 499122177  mod 998244353  2 
    }
    return 0;
}