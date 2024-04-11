#include <iostream>
#include <algorithm>
#include <vector>
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

struct SEG
{
    int seg[1616161]{};
    int lazy[1616161]{};
    void prop(int ind)
    {
        if(lazy[ind])
        {
            seg[ind << 1] += lazy[ind];
            lazy[ind << 1] += lazy[ind];
            seg[ind << 1 | 1] += lazy[ind];
            lazy[ind << 1 | 1] += lazy[ind];
            lazy[ind] = 0;
        }
    }
    int qr(int s, int e, int ind, int l, int r)
    {
        if(e <= l || r <= s) return 0;
        if(l <= s && e <= r) return seg[ind];

        prop(ind);
        int mid = s + e >> 1;
        return max(qr(s, mid, ind << 1, l, r), qr(mid, e, ind << 1 | 1, l, r));
    }
    void upd(int s, int e, int ind, int l, int r, int x)
    {
        if(e <= l || r <= s) return;
        if(l <= s && e <= r)
        {
            seg[ind] += x;
            lazy[ind] += x;
            return;
        }

        prop(ind);
        int mid = s + e >> 1;
        upd(s, mid, ind << 1, l, r, x);
        upd(mid, e, ind << 1 | 1, l, r, x);
        seg[ind] = max(seg[ind << 1], seg[ind << 1 | 1]);
    }
}A, B;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    piii arr[n]; for(auto &i : arr) cin >> i.ff >> i.ee >> i.rr;
    vector<int> pr; for(auto &i : arr) pr.push_back(i.ff), pr.push_back(i.ee);
    sort(pr.begin(), pr.end()); pr.erase(unique(pr.begin(), pr.end()), pr.end());
    for(auto &i : arr) i.ff = lower_bound(pr.begin(), pr.end(), i.ff) - pr.begin(), i.ee = lower_bound(pr.begin(), pr.end(), i.ee) - pr.begin();
    int N = pr.size();

    vector<int> X[N], Y[N];
    for(auto &i : arr)
    {
        if(i.rr == 1) X[i.ee].push_back(i.ff);
        else Y[i.ee].push_back(i.ff);
    }

    for(int i = 0; i < N; ++i)
    {
        for(auto j : X[i]) B.upd(0, N + 1, 1, 0, j + 1, 1);
        for(auto j : Y[i]) A.upd(0, N + 1, 1, 0, j + 1, 1);
        A.upd(0, N + 1, 1, i + 1, i + 2, max(A.qr(0, N + 1, 1, i, i + 1), B.qr(0, N + 1, 1, 0, i + 1)));
        B.upd(0, N + 1, 1, i + 1, i + 2, max(B.qr(0, N + 1, 1, i, i + 1), A.qr(0, N + 1, 1, 0, i + 1)));
    }

    cout << max(A.qr(0, N + 1, 1, N, N + 1), B.qr(0, N + 1, 1, N, N + 1));
}