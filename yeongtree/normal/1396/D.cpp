#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <map>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss

using namespace std;

const int Q = 1e9 + 7;

struct Node
{
    int mn, smn, mncnt;
    long long sum;
};

Node seg[5050505];
int arr[1010101];
int brr[1010101];

Node mrge(const Node &x, const Node &y)
{
    if(x.mn == y.mn) return { x.mn, min(x.smn, y.smn), x.mncnt + y.mncnt, x.sum + y.sum };
    if(x.mn < y.mn) return { x.mn, min(x.smn, y.mn), x.mncnt, x.sum + y.sum };
    return { y.mn, min(x.mn, y.smn), y.mncnt, x.sum + y.sum };
}

void init(int nd, int l, int r)
{
    if(l + 1 == r) seg[nd] = { arr[l], Q, brr[l], 1ll * arr[l] * brr[l] };
    else
    {
        int mid = l + r >> 1;
        init(nd << 1, l, mid);
        init(nd << 1 | 1, mid, r);
        seg[nd] = mrge(seg[nd << 1], seg[nd << 1 | 1]);
    }
}

void trib(int nd)
{
    for(int i : {nd << 1, nd << 1 | 1})
    {
        if(seg[i].mn < seg[nd].mn)
        {
            seg[i].sum += 1ll * seg[i].mncnt * (seg[nd].mn - seg[i].mn);
            seg[i].mn = seg[nd].mn;
        }
    }
}

void update(int nd, int l, int r, int s, int e, int x)
{
    if(s >= r || e <= l || seg[nd].mn >= x) return;
    if(s <= l && r <= e && seg[nd].smn > x)
    {
        seg[nd].sum += 1ll * seg[nd].mncnt * (x - seg[nd].mn);
        seg[nd].mn = x;
        return;
    }

    trib(nd);
    int mid = l + r >> 1;
    update(nd << 1, l, mid, s, e, x);
    update(nd << 1 | 1, mid, r, s, e, x);
    seg[nd] = mrge(seg[nd << 1], seg[nd << 1 | 1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, l; cin >> n >> k >> l;
    piii inp[n]; for(auto &i : inp) cin >> i.ff >> i.ee >> i.rr, --i.rr;
    vector<int> prX, prY;
    prX.push_back(-1), prX.push_back(l);
    prY.push_back(-1), prY.push_back(l);
    for(auto &i : inp) prX.push_back(i.ff), prY.push_back(i.ee);
    sort(prX.begin(), prX.end());
    sort(prY.begin(), prY.end());
    prX.resize(unique(prX.begin(), prX.end()) - prX.begin());
    prY.resize(unique(prY.begin(), prY.end()) - prY.begin());
    for(auto &i : inp)
    {
        i.ff = lower_bound(prX.begin(), prX.end(), i.ff) - prX.begin();
        i.ee = lower_bound(prY.begin(), prY.end(), i.ee) - prY.begin();
    }
    int N = prX.size() - 1;
    int M = prY.size() - 1;
    for(int i = 0; i < N; ++i) brr[i] = prX[i + 1] - prX[i];

    vector<pii> ls[M];
    for(auto &i : inp) ls[i.ee].push_back({i.ff, i.rr});

    long long ans = 0;
    for(int i = 0; i < M; ++i)
    {
        for(int j = 0; j < N; ++j) arr[j] = prX[j + 1];
        init(1, 0, N);

        map<int, int> S[k];
        for(int j = 0; j < k; ++j) S[j][N]++;
        for(auto &j : inp) if(j.ee > i) S[j.rr][j.ff]++;
        for(int j = 0; j < k; ++j)
        {
            int pr = 0;
            for(auto it = S[j].begin(); it != S[j].end(); ++it)
            {
                update(1, 0, N, pr, it->ff, prX[it->ff]);
                pr = it->ff;
            }
        }
        ans += (1ll * l * (l + 1) - seg[1].sum) % Q * (prY[i + 1] - prY[i]) % Q * (prY[M] - prY[M - 1]) % Q;
        ans %= Q;

        for(int j = M - 1; j > i; --j)
        {
            for(auto x : ls[j])
            {
                if(!--S[x.ss][x.ff])
                {
                    auto it = S[x.ss].lower_bound(x.ff);
                    it = S[x.ss].erase(it);
                    if(it == S[x.ss].begin()) update(1, 0, N, 0, it->ff, prX[it->ff]);
                    else update(1, 0, N, prev(it)->ff, it->ff, prX[it->ff]);
                }
            }
            ans += (1ll * l * (l + 1) - seg[1].sum) % Q * (prY[i + 1] - prY[i]) % Q * (prY[j] - prY[j - 1]) % Q;
            ans %= Q;
        }
    }

    cout << ans;
}