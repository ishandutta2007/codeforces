#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353, N = 1<<17;

int n, p[N], val, m, g[N], f[N], rk[N], tot;

map <int, int> mp;

void build_(int o, int l, int r, int p) {
    g[o] = p + 1;

    if (l == r)
        return;
    
    int mid = (l + r)>>1;
    build_(o<<1, l, mid, p<<1), build_(o<<1|1, mid + 1, r, p<<1); 
}

void dfs_(int o, int l, int r, int S) {
    if (l == r) {
        rk[l] = f[o];
        return;
    }

    int mid = (l + r)>>1;

    if (S&(1<<o - 1))
        f[o<<1] = g[o<<1], f[o<<1|1] = f[o];
    else
        f[o<<1] = f[o], f[o<<1|1] = g[o<<1|1];
    
    dfs_(o<<1, l, mid, S), dfs_(o<<1|1, mid + 1, r, S);
}

int main() {
    scanf("%d%d%d", &n, &p[1], &val), m = 1<<n, tot = (1<<m/2 - 1);

    for (int i = 2; i <= (1<<n); i++)
        p[i] = 1ll*p[i - 1]*p[1]%mod;
    
    build_(1, 1, m/2, 1);

    mp.clear();

    for (int i = 0, x; i < tot; i++) {
        f[1] = 1, x = 0, dfs_(1, 1, m/2, i);

        for (int j = 1; j <= m/2; j++) 
            x = (x + 1ll*j*p[rk[j]])%mod;
    
        mp[x] = i;
    }

    for (int i = 0, x; i < tot; i++) {
        f[1] = 2, x = 0, dfs_(1, m/2 + 1, m, i);

        for (int j = m/2 + 1; j <= m; j++)  
            x = (x + 1ll*j*p[rk[j]])%mod;
        
        x = ((val - x)%mod + mod)%mod;
        
        if (mp.count(x)) {
            f[1] = 1, dfs_(1, 1, m/2, mp[x]);

            for (int j = 1; j <= m; j++)
                printf("%d ", rk[j]);
            
            return 0;
        }
    }

    mp.clear();

    for (int i = 0, x; i < tot; i++) {
        f[1] = 1, x = 0, dfs_(1, m/2 + 1, m, i);

        for (int j = m/2 + 1; j <= m; j++)
            x = (x + 1ll*j*p[rk[j]])%mod;
    
        mp[x] = i;
    }

    for (int i = 0, x; i < tot; i++) {
        f[1] = 2, x = 0, dfs_(1, 1, m/2, i);

        for (int j = 1; j <= m/2; j++)  
            x = (x + 1ll*j*p[rk[j]])%mod;

        x = ((val - x)%mod + mod)%mod;
        
        if (mp.count(x)) {
            f[1] = 1, dfs_(1, m/2 + 1, m, mp[x]);

            for (int j = 1; j <= m; j++)
                printf("%d ", rk[j]);
            
            return 0;
        }
    }

    puts("-1");
}