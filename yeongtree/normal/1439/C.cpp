#include <iostream>

using namespace std;

const int INF = (int)1e9 + 7;
int A[202020];
struct Node
{
    long long s;
    int m, n, l;
}seg[808080];

void mrge(int ind)
{
    seg[ind].s = seg[ind << 1].s + seg[ind << 1 | 1].s;
    seg[ind].m = seg[ind << 1].m;
    seg[ind].n = seg[ind << 1 | 1].n;
    seg[ind].l = -1;
}

void prop(int s, int e, int ind)
{
    if(seg[ind].l > -1)
    {
        int mid = s + e >> 1;
        seg[ind << 1].s = 1ll * seg[ind].l * (mid - s);
        seg[ind << 1 | 1].s = 1ll * seg[ind].l * (e - mid);
        seg[ind << 1].m = seg[ind << 1 | 1].m = seg[ind].l;
        seg[ind << 1].n = seg[ind << 1 | 1].n = seg[ind].l;
        seg[ind << 1].l = seg[ind << 1 | 1].l = seg[ind].l;
        seg[ind].l = -1;
    }
}

void init(int s, int e, int ind)
{
    if(s + 1 == e)
    {
        seg[ind].s = seg[ind].m = seg[ind].n = A[s];
        seg[ind].l = -1;
        return;
    }
    int mid = s + e >> 1;
    init(s, mid, ind << 1);
    init(mid, e, ind << 1 | 1);
    mrge(ind);
}

void upd(int s, int e, int ind, int l, int r, int x)
{
    if(e <= l || r <= s || seg[ind].n >= x) return;
    if(l <= s && e <= r && seg[ind].m <= x)
    {
        seg[ind].s = 1ll * x * (e - s);
        seg[ind].m = seg[ind].n = seg[ind].l = x;
        return;
    }

    prop(s, e, ind);
    int mid = s + e >> 1;
    upd(s, mid, ind << 1, l, r, x);
    upd(mid, e, ind << 1 | 1, l, r, x);
    mrge(ind);
}

long long qr(int s, int e, int ind, int l, int r)
{
    if(e <= l || r <= s) return 0;
    if(l <= s && e <= r) return seg[ind].s;

    prop(s, e, ind);
    int mid = s + e >> 1;
    return qr(s, mid, ind << 1, l, r) + qr(mid, e, ind << 1 | 1, l, r);
}

int lb(int s, int e, int ind, int x)
{
    if(s + 1 == e) return (x < seg[ind].m ? e : s);

    int mid = s + e >> 1;
    prop(s, e, ind);
    if(x >= seg[ind << 1 | 1].m) return lb(s, mid, ind << 1, x);
    else return lb(mid, e, ind << 1 | 1, x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, T; cin >> n >> T;
    for(int i = 0; i < n; ++i) cin >> A[i];
    init(0, n, 1);
    while(T--)
    {
        int c; cin >> c;
        if(c == 1)
        {
            int x, y; cin >> x >> y;
            upd(0, n, 1, 0, x, y);
        }
        else
        {
            int ans = 0;
            int s; long long x; cin >> s >> x; --s;
            while(s < n)
            {
                long long t = qr(0, n, 1, s, s + 1);
                int q = min(n - s, int(x / t));
                ans += q;
                x -= qr(0, n, 1, s, s + q);
                s = max(s + q, lb(0, n, 1, x));
            }
            cout << ans << '\n';
        }
    }
}