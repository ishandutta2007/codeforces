#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> pii;

const int N = 1e6 + 10, mod = 998244353;

int fpow_(int a, int b, int res = 1) {
    for (; b; b >>= 1, a = 1ll*a*a%mod)
        if (b&1) res = 1ll*res*a%mod;
    
    return res;
}

map <pii, int> mp;

struct Node {
    int c[N][2], tot, ans, cnt;

    void init_(int n) {
        tot = n, ans = fpow_(2, n);
    }

    void upd_(int x, int y, int k) {
        if (c[x][0] && c[x][1]) 
            cnt--;
        
        if (!c[x][0] && !c[x][1])
            tot--;
        
        c[x][y] += k;

        if (c[x][0] && c[x][1])
            cnt++;
        
        if (!c[x][0] && !c[x][1])
            tot++;
        
        if (cnt) ans = 0;
        else ans = fpow_(2, tot);
    }
} T[2];

int n, m, q, c[2], ans;

void upd_(int x, int y, int k) {
    int z = (x + y)&1, w = mp[pii(x, y)];

    if (w == -1) return;

    c[z^w] += k;
    T[0].upd_(x, (y&1)^w, k);
    T[1].upd_(y, (x&1)^w, k);
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    T[0].init_(n), T[1].init_(m);

    for (int i = 1, x, y, op; i <= q; i++) {
        scanf("%d%d%d", &x, &y, &op);

        if (!mp.count(pii(x, y)))
            mp[pii(x, y)] = -1;                

        upd_(x, y, -1);
        mp[pii(x, y)] = op;
        upd_(x, y, 1);
        ans = (T[0].ans + T[1].ans)%mod;

        if (!c[0]) ans--;

        if (!c[1]) ans--;

        printf("%d\n", (ans%mod + mod)%mod); 
    }
}