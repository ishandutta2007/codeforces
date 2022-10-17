#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss

using namespace std;

string str;
string str2;

struct Node
{
    int x, l;
}seg[808080];

void prop(int s, int e, int ind)
{
    int mid = s + e >> 1;

    if(seg[ind].l == 0)
    {
        seg[ind << 1].l = 0;
        seg[ind << 1 | 1].l = 0;
        seg[ind << 1].x = 0;
        seg[ind << 1 | 1].x = 0;
    }

    if(seg[ind].l == 1)
    {
        seg[ind << 1].l = 1;
        seg[ind << 1 | 1].l = 1;
        seg[ind << 1].x = mid - s;
        seg[ind << 1 | 1].x = e - mid;
    }

    seg[ind].l = -1;
}

void mrge(int ind)
{
    seg[ind].x = seg[ind << 1].x + seg[ind << 1 | 1].x;
}

void init(int s, int e, int ind)
{
    if(s + 1 == e)
    {
        seg[ind].x = str[s] - '0';
        seg[ind].l = -1;
        return;
    }

    int mid = s + e >> 1;
    init(s, mid, ind << 1);
    init(mid, e, ind << 1 | 1);
    mrge(ind); seg[ind].l = -1;
}

void upd(int s, int e, int ind, int l, int r, int x)
{
    if(e <= l || r <= s) return;
    if(l <= s && e <= r)
    {
        if(x == 0) seg[ind].x = 0;
        else seg[ind].x = e - s;
        seg[ind].l = x;
        return;
    }

    prop(s, e, ind);
    int mid = s + e >> 1;
    upd(s, mid, ind << 1, l, r, x);
    upd(mid, e, ind << 1 | 1, l, r, x);
    mrge(ind);
}

int qr(int s, int e, int ind, int l, int r)
{
    if(e <= l || r <= s) return 0;
    if(l <= s && e <= r) return seg[ind].x;

    prop(s, e, ind);
    int mid = s + e >> 1;
    return qr(s, mid, ind << 1, l, r) + qr(mid, e, ind << 1 | 1, l, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, q; cin >> n >> q;
        cin >> str2 >> str;
        pii ls[q];
        for(int i = 0; i < q; ++i) cin >> ls[i].ff >> ls[i].ss, --ls[i].ff;
        init(0, n, 1);

        bool flag = true;
        for(int i = q - 1; i >= 0; --i)
        {
            int t = qr(0, n, 1, ls[i].ff, ls[i].ss);
            if(t * 2 < ls[i].ss - ls[i].ff) upd(0, n, 1, ls[i].ff, ls[i].ss, 0);
            else if(t * 2 > ls[i].ss - ls[i].ff) upd(0, n, 1, ls[i].ff, ls[i].ss, 1);
            else { flag = false; break; }
        }

        for(int i = 0; i < n; ++i) if(str2[i] - '0' != qr(0, n, 1, i, i + 1)) { flag = false; break; }

        cout << (flag ? "YES" : "NO") << '\n';
    }
}