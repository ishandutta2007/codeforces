#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

template <typename T> inline T read() {
    T x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * f;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N = 1000010;
const ll INFl = 0x3f3f3f3f3f3f3f3f;

int n, m;
ll p, a[N];

#define lson (now << 1)
#define rson (now << 1 | 1)
#define mid ((l + r) >> 1)

struct Node {
    vector<ll> f;
    ll sum;
    int len;
} t[N << 2];

Node operator+(const Node &a, const Node &b) {
    Node ret;
    ret.f = vector<ll>(a.len + b.len + 2, INFl), ret.f[0] = -INFl;
    ret.sum = a.sum + b.sum, ret.len = a.len + b.len;
    for (int x = 0, y = 0; x <= a.len; x++) {
        if (y > b.len)
            y--;
        for (; y <= b.len; y++) {
            ll L = max(a.f[x], b.f[y] - a.sum + x * p),
               R = min(a.f[x + 1], b.f[y + 1] - a.sum + x * p);
            if (L >= R) {
                y = max(0, y - 1);
                break;
            }
            ret.f[x + y] = min(ret.f[x + y], L);
        }
    }
    return ret;
}

void build(int now, int l, int r) {
    if (l == r) {
        t[now] = {{-INFl, p - a[l], INFl}, a[l], 1};
        return;
    }
    build(lson, l, mid), build(rson, mid + 1, r);
    t[now] = t[lson] + t[rson];
}

void query(int now, int l, int r, int x, int y, ll &val) {
    if (x <= l && r <= y) {
        int pos = upper_bound(t[now].f.begin(), t[now].f.end(), val) -
                  t[now].f.begin() - 1;
        val = val + t[now].sum - pos * p;
        return;
    }
    if (x <= mid)
        query(lson, l, mid, x, y, val);
    if (y > mid)
        query(rson, mid + 1, r, x, y, val);
}

int main() {
    n = rdi(), m = rdi(), p = rdi();
    for (int i = 1; i <= n; i++)
        a[i] = rdi();
    build(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int l = rdi(), r = rdi();
        ll val = 0;
        query(1, 1, n, l, r, val);
        cout << val << '\n';
    }
    return 0;
}