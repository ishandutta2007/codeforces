#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

inline LL mul(LL a, LL b, LL mod) {
    return (a * b - (LL)((long double)a / mod * b + 0.5) * mod + mod) % mod;
}

inline LL Pow(LL x, LL y, LL mod) {
    LL res = 1;
    for (; y; y >>= 1, x = (LL)mul(x, x, mod)) if (y & 1) res = mul(res, x, mod);
    return res;
}

const int _A[] = {2, 3, 5, 7, 11, 13, 131};

inline bool Miller_Rabin(LL n) {
    if (n == 1) return false;
    LL tmp = n - 1; int ct = 0;
    while (!(tmp & 1)) tmp >>= 1, ct++;
    for (int i = 0; i < 7; i++) {
        if (n == _A[i]) return true;
        LL a = Pow(_A[i], tmp, n), nxt = a;
        for (int j = 1; j <= ct; j++) {
            nxt = mul(a, a, n);
            if (nxt == 1 && a != 1 && a != n - 1) return false;
            a = nxt;
        }
        if (a != 1) return false;
    }
    return true;
}

inline LL _rand(LL x, LL c, LL mod) {
    return (mul(x, x, mod) + c) % mod;
}

inline LL _rand() {
    return (LL)rand() << 48 | (LL)rand() << 32 | rand() << 16 | rand();
}

inline LL _abs(LL x) {
    return x >= 0 ? x : -x;
}

LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}

inline LL Pollard_Rho(LL n) {
    LL s = 0, t = 0, c = _rand() % (n - 1) + 1, val = 1;
    for (int cir = 1; ; cir <<= 1, s = t, val = 1) {
        for (int i = 0; i < cir; i++) {
            t = _rand(t, c, n), val = mul(val, _abs(t - s), n);
            if (i % 127 == 0) {
                LL g = gcd(val, n);
                if (g != 1) return g;
            } 
        }
        LL g = gcd(val, n);
        if (g != 1) return g;
    }
}

vector<LL> divisors; 

inline void Factor(LL n) {
    if (n < 1) return ;
    if (n == 1) return;
    if (Miller_Rabin(n)) return divisors.push_back(n), void();
    LL d = n;
    while (d == n) d = Pollard_Rho(n);
    while (n % d == 0) n /= d;
    Factor(n), Factor(d);
}

int n;
long long seq[200050];
map<long long,int> mp,vis;

int mrand()
{
    return rand() << 15 | rand();
}

int main()
{
    srand((unsigned long long)(new char));
    scanf("%d",&n);
    int lim = 0;
    for(int i = 1;i <= n; ++ i)
    {
        scanf("%lld",&seq[i]);
        lim += seq[i] % 2;
    }
    int sz = 1000;
    for(int i = 1;i <= sz; ++ i)
    {
        int po = mrand() % n + 1;
        Factor(seq[po] + mrand() % 3 - 1);
        vis.clear();
        for(auto v : divisors)
        {
            if(v > 35)
            {
                if(vis[v]) continue;
                vis[v] = 1;
                mp[v] ++;
            }
        }
        divisors.clear();
    }
    for(long long j = 2;j <= 35; ++ j)
    {
        if(j > 1)
        {
            if(Miller_Rabin(j))
            {
                long long cur = 0;
                for(int k = 1;k <= n; ++ k)
                {
                    long long val = seq[k] / j * j;
                    if(!val)
                    {
                        cur += val + j - seq[k];
                    }
                    else
                        cur += min(seq[k] - val,val + j - seq[k]);
                    if(cur > lim)
                        break;
                }
                lim = min(lim * 1ll,cur);
            }
        }
    }
    for(auto v : mp)
    {
        {
            long long j = v.first;
            long long cur = 0;
            for(int k = 1;k <= n; ++ k)
            {
                long long val = seq[k] / j * j;
                if(!val) cur += val + j - seq[k];
                else cur += min(seq[k] - val,val + j - seq[k]);
                if(cur > lim)
                    break;
            }
            lim = min(lim * 1ll,cur);
        }
    }
    printf("%d\n",lim);
}