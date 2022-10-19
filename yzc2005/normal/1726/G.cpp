#include <bits/stdc++.h>
using namespace std;
 
const int P = 998244353;
const int inf = 0x3f3f3f3f;
 
const int N = 200005;
int n, a[N], b[N], cnt[2][N << 1];
int fac[N];
 
namespace t0 {
    pair<int, int> val[N << 3];
    int lazy[N << 3];
 
    inline void push_up(int p) {
        val[p] = min(val[p << 1], val[p << 1 | 1]);
    }
 
    inline void tag(int p, int x) {
        lazy[p] += x;
        val[p].first += x;
    }
 
    inline void push_down(int p) {
        if (lazy[p]) {
            tag(p << 1, lazy[p]);
            tag(p << 1 | 1, lazy[p]);
            lazy[p] = 0;
        }
    }
 
    void build(int p, int l, int r, int *cnt) {
        lazy[p] = 0;
        if (l == r) {
            val[p] = (cnt[l] == 0) ? make_pair(inf, 0) : make_pair(l, l);
            return;
        }
 
        int mid = (l + r) >> 1;
        build(p << 1, l, mid, cnt);
        build(p << 1 | 1, mid + 1, r, cnt);
 
        push_up(p);
    }
 
    void modify(int p, int l, int r, int ll, int rr, int x) {
        if (l >= ll && r <= rr) {
            tag(p, x);
            return;
        }
 
        int mid = (l + r) >> 1;
        push_down(p);
 
        if (mid >= ll) {
            modify(p << 1, l, mid, ll, rr, x);
        }
        if (mid < rr) {
            modify(p << 1 | 1, mid + 1, r, ll, rr, x);
        }
 
        push_up(p);
    }
 
    void erase(int p, int l, int r, int pos) {
        if (l == r) {
            val[p] = make_pair(inf, 0);
            return;
        }
 
        int mid = (l + r) >> 1;
        push_down(p);
 
        if (mid >= pos) {
            erase(p << 1, l, mid, pos);
        }  else {
            erase(p << 1 | 1, mid + 1, r, pos);
        }
 
        push_up(p);
    }
}
 
namespace t1 {
    pair<int, int> val[N << 3];
    int lazy[N << 3];
 
    inline void push_up(int p) {
        val[p] = max(val[p << 1], val[p << 1 | 1]);
    }
 
    inline void tag(int p, int x) {
        lazy[p] += x;
        val[p].first += x;
    }
 
    inline void push_down(int p) {
        if (lazy[p]) {
            tag(p << 1, lazy[p]);
            tag(p << 1 | 1, lazy[p]);
            lazy[p] = 0;
        }
    }
 
    void build(int p, int l, int r, int *cnt) {
        lazy[p] = 0;
        if (l == r) {
            val[p] = (cnt[l] == 0) ? make_pair(-inf, 0) : make_pair(l, l);
            return;
        }
 
        int mid = (l + r) >> 1;
        build(p << 1, l, mid, cnt);
        build(p << 1 | 1, mid + 1, r, cnt);
 
        push_up(p);
    }
 
    void modify(int p, int l, int r, int ll, int rr, int x) {
        if (l >= ll && r <= rr) {
            tag(p, x);
            return;
        }
 
        int mid = (l + r) >> 1;
        push_down(p);
 
        if (mid >= ll) {
            modify(p << 1, l, mid, ll, rr, x);
        }
        if (mid < rr) {
            modify(p << 1 | 1, mid + 1, r, ll, rr, x);
        }
 
        push_up(p);
    }
 
    void erase(int p, int l, int r, int pos) {
        if (l == r) {
            val[p] = make_pair(-inf, 0);
            return;
        }
 
        int mid = (l + r) >> 1;
        push_down(p);
 
        if (mid >= pos) {
            erase(p << 1, l, mid, pos);
        }  else {
            erase(p << 1 | 1, mid + 1, r, pos);
        }
 
        push_up(p);
    }
}
 
void update(int x, int y) {
    if (x < 2 * n) {
        t0::modify(1, 1, 2 * n, x + 1, 2 * n, y);
    }
    if (x > 1) {
        t1::modify(1, 1, 2 * n, 1, x - 1, y);
    }
}
 
int calc(int x) {
    memset(cnt, 0, sizeof cnt);
 
    int ans = 1;
    int rest = 0;
    for (int i = 1, j = n, k = 1; i <= n; ++i) {
        if (a[i] == x) {
            if (b[i] == 1) {
                ans = 1ll * ans * (j--) % P;
            } else {
                ans = 1ll * ans * (k++) % P;
            }
        } else {
            ++rest;
            ++cnt[b[i]][a[i]];
        }
    }
 
    t0::build(1, 1, 2 * n, cnt[0]);
    t1::build(1, 1, 2 * n, cnt[1]);
 
    for (int i = 1; i <= n; ++i) {
        update(a[i], 1);
    }
 
    while (rest) {
        auto a = t0::val[1], b = t1::val[1];
 
        if (a.first != x && b.first != x) {
            return 0;
        }
        if (a.first == x && (b.first != x || b.second < a.second)) {
            int c = cnt[0][a.second];
            ans = 1ll * ans * fac[c] % P;
 
            t0::erase(1, 1, 2 * n, a.second);
            rest -= c;
            update(a.second, -c);
            update(x, c);
        } else {
            if (cnt[1][b.second] > 1) {
                return 0;
            }
            
            t1::erase(1, 1, 2 * n, b.second);
            rest -= 1;
            update(b.second, -1);
            update(x, 1);
        }
    }
 
    return ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
 
    if (n == 1) {
        cout << 1 << "\n";
        return 0;
    }
 
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = 1ll * fac[i - 1] * i % P;
    }
 
    int x = *min_element(a + 1, a + n + 1);
    cout << (calc(x) + calc(x + n - 1)) % P << "\n";
 
    return 0;
}