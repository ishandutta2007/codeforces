#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, a[N], tp[N], p[N], m;
bool flag[N], fir[N], lst[N];
struct node {
    int tl, tr, a[2][2];
    void init(int type) {
        memset(a, 0x3f, sizeof a);
        tl = tr = type;
        a[1][1] = 1;
        if (type != 3) {
            a[0][0] = 0;
        }
    }
    int val() {
        return min({a[0][0], a[0][1], a[1][0], a[1][1]});
    }
} t[N << 2]; 
inline node operator+(const node &lhs, const node &rhs) {
    node res;
    res.tl = lhs.tl;
    res.tr = rhs.tr;
    bool f = (lhs.tr + rhs.tl == 3);
    memset(res.a, 0x3f, sizeof res.a);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int x = 0; x < 2; ++x) {
                if (f && !j && !x) {
                    continue;
                }
                for (int y = 0; y < 2; ++y) {
                    res.a[i][y] = min(res.a[i][y], lhs.a[i][j] + rhs.a[x][y]);
                }
            }
        }
    }
    return res;
}
inline void push_up(int p) {
    t[p] = t[p << 1] + t[p << 1 | 1];
}
void build(int p, int l, int r) {
    if (l == r) {
        t[p].init(tp[l]);
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    push_up(p);
}
void modify(int p, int l, int r, int pos) {
    if (l == r) {
        t[p].init(tp[l]);
        return;
    }
    int mid = (l + r) >> 1;
    if (mid >= pos) {
        modify(p << 1, l, mid, pos);
    } else {
        modify(p << 1 | 1, mid + 1, r, pos);
    }
    push_up(p);
}
node query(int p, int l, int r, int ll, int rr) {
    if (l >= ll && r <= rr) {
        return t[p];
    }
    int mid = (l + r) >> 1;
    if (mid >= ll && mid < rr) {
        return query(p << 1, l, mid, ll, rr) + query(p << 1 | 1, mid + 1, r, ll, rr);
    }
    if (mid >= ll) {
        return query(p << 1, l, mid, ll, rr);
    }
    return query(p << 1 | 1, mid + 1, r, ll, rr);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i]) {
            p[++m] = a[i];
        }
    }
    sort(p + 1, p + m + 1);
    m = unique(p + 1, p + m + 1) - p - 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i]) {
            a[i] = lower_bound(p + 1, p + m + 1, a[i]) - p;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (!flag[a[i]]) {
            fir[i] = flag[a[i]] = true;
        }
    }
    memset(flag, false, sizeof flag);
    for (int i = n; i; --i) {
        if (!flag[a[i]]) {
            lst[i] = flag[a[i]] = true;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= m; ++i) {
        tp[i] = 2;
    }
    if (m > 0) {
        build(1, 1, m);
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] > 0) {
            ans += 1;
            if (a[i] > 1) {
                // for (int j = 1; j < a[i]; ++j) {
                //     printf("%d", tp[j]);
                // }
                // puts("");
                ans += query(1, 1, m, 1, a[i] - 1).val();
            }
            if (fir[i]) {
                tp[a[i]] += 1;
                modify(1, 1, m, a[i]);
            }   
            if (lst[i]) {
                tp[a[i]] -= 2;
                modify(1, 1, m, a[i]);
            }
        }
    }   
    cout << ans << "\n";
    return 0;
}