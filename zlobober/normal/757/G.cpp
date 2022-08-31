#include <cassert>
#include <tuple>
#include <map>
#include <unistd.h>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int N = 200501;
const int LGN = 19;

typedef long long llong;

int n;

struct vert {
    int c = -1;
    llong d = -1;
};

vector<vert> info;

struct layer {
    std::vector<pair<int, llong>> srt;
    std::vector<int> x;
    std::vector<llong> S;
    int depth = 0;
} L[N];

bool rem[N];
int sz[N];

vector<pair<int, int>> E[N];

int centroid(int x, int all_sz, int p = -1) {
    sz[x] = 1;
    int glob_res = -1;
    for (auto pr : E[x]) {
        int y = pr.first;
        if (rem[y] || p == y)
            continue;
        int res = centroid(y, all_sz, x);
        if (res != -1) {
            glob_res = res;
        }
        sz[x] += sz[y];
    }
    if (glob_res != -1)
        return glob_res;
    bool is_centroid = all_sz - sz[x] <= all_sz / 2;
    for (auto pr : E[x]) {
        int y = pr.first;
        if (rem[y] || p == y)
            continue;
        is_centroid &= sz[y] <= all_sz / 2;
    }
    if (is_centroid)
        return x;
    return -1;
}

int A[N], IA[N];

void DFS(int x, int depth, int c, int p = -1, llong d = 0) {
    info[x * LGN + depth].c = c;
    info[x * LGN + depth].d = d;
    sz[x] = 1;
    L[c].srt.emplace_back(IA[x], d - ((depth > 0) ? info[x * LGN + depth - 1].d : 0));

    for (auto pr : E[x]) {
        int y = pr.first;
        int w = pr.second;
        if (y == p || rem[y])
            continue;
        DFS(y, depth, c, x, d + w);
        sz[x] += sz[y];
    }
}

void build_layer(int x, int all_sz, int depth) {
    assert(!rem[x]);
    int c = centroid(x, all_sz);
    assert(c != -1);
    x = c;
    L[x].depth = depth;
    for (auto pr : E[x]) {
        int y = pr.first;
        int w = pr.second;
        if (rem[y])
            continue;
        DFS(y, depth, x, x, w);
    }
    L[x].srt.emplace_back(IA[x], 0 - ((depth > 0) ? info[x * LGN + depth - 1].d : 0));

    info[x * LGN + depth].c = x;
    info[x * LGN + depth].d = 0;
    rem[x] = true;
    for (auto pr : E[x]) {
        int y = pr.first;
        if (!rem[y]) {
            build_layer(y, sz[y], depth + 1);
        }
    }
}

llong query(int v, int l, int r) {
    assert(1 <= l && l <= r && r <= n);
    assert(1 <= v && v <= n);
    llong sum = 0;
    llong c1 = 0, c2 = 0;
    for (int depth = 0; ; depth++) {
        int c = info[v * LGN + depth].c;
        llong d = info[v * LGN + depth].d;
        if (c == -1)
            break;
        llong sumd = 0;
        int i1 = lower_bound(L[c].x.begin(), L[c].x.end(), l) - L[c].x.begin() - 1;
        int i2 = upper_bound(L[c].x.begin(), L[c].x.end(), r) - L[c].x.begin() - 1;
        if (i1 >= 0) {
            sumd -= L[c].S[i1];
        }
        if (i2 >= 0) {
            sumd += L[c].S[i2];
        }
        sum += sumd + (d + c2) * (i2 - i1);
        c1 = -1, c2 = -d;
    }
    return sum;
}

void change(int x1, int x2, int v1, int v2) {
    assert(v1 != v2);
    assert(x1 + 1 == x2);
    int depth;
    for (depth = 0; ; depth++) {
        if (info[v1 * LGN + depth].c != info[v2 * LGN + depth].c)
            break;
        int c = info[v1 * LGN + depth].c;
        int i1 = lower_bound(L[c].x.begin(), L[c].x.end(), x1) - L[c].x.begin();
        assert(i1 + 1 <= L[c].S.size() && L[c].x[i1] == x1);
        int i2 = i1 + 1;
        assert(i2 + 1 <= L[c].S.size() && L[c].x[i2] == x2);
        auto pi = i1 - 1;
        llong ps = 0;
        if (pi >= 0) {
            ps = L[c].S[pi];
        }
        llong s1 = L[c].S[i1] - ps;
        llong s2 = L[c].S[i2] - L[c].S[i1];
        //assert(cnt1 == 1 && cnt2 == 1);
        L[c].S[i1] = ps + s2;
        //assert(it2->second == make_pair(ps + s2 + s1, pcnt + cnt2 + cnt1));
    }
    for (int depth1 = depth; ; depth1++) {
        int c = info[v1 * LGN + depth1].c;
        if (c == -1)
            break;
        int i1 = lower_bound(L[c].x.begin(), L[c].x.end(), x1) - L[c].x.begin();
        assert(i1 < (int)L[c].x.size() && L[c].x[i1] == x1);
        L[c].x[i1]++;
    }
    for (int depth2 = depth; ; depth2++) {
        int c = info[v2 * LGN + depth2].c;
        if (c == -1)
            break;
        int i2 = lower_bound(L[c].x.begin(), L[c].x.end(), x2) - L[c].x.begin();
        assert(i2 < (int)L[c].x.size() && L[c].x[i2] == x2);
        L[c].x[i2]--;
    }
    A[x1] = v2, A[x2] = v1, IA[v1] = x2, IA[v2] = x1;
}

const bool bitch_input = true;

int main() {
    info.resize(N * LGN);
    int q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        IA[A[i]] = i;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        E[u].emplace_back(v, w);
        E[v].emplace_back(u, w);
    }
    build_layer(1, n, 0);
    for (int i = 1; i <= n; i++)
        assert(rem[i]);

    llong pans = 0;
    const int BIT = (1 << 30) - 1;

    for (int i = 1; i <= n; i++) {
        sort(L[i].srt.begin(), L[i].srt.end());
        llong s = 0;
        int cnt = 0;
        for (int j = 0; j < (int)L[i].srt.size(); j++) {
            L[i].x.emplace_back(L[i].srt[j].first);
            s += L[i].srt[j].second;
            cnt++;
            L[i].S.emplace_back(s);
        }
        L[i].srt.clear();
    }

    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 1) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            int l, r, v;
            if (bitch_input) {
                l = (pans & BIT) ^ a;
                r = (pans & BIT) ^ b;
                v = (pans & BIT) ^ c;
            } else {
                l = a, r = b, v = c;
            }
            llong ans = query(v, l, r);
            printf("%lld\n", ans);
            pans = ans;
        } else {
            int a;
            scanf("%d", &a);
            int x;
            if (bitch_input) {
                x = (pans & BIT) ^ a;
            } else {
                x = a;
            }
            change(x, x + 1, A[x], A[x + 1]);
        }
    }
}