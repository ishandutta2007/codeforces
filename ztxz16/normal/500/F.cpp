#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

const int N = 4005;
const int M = 20005;

struct Node {
    int c, h, t;
    
    friend bool operator < (const Node &a, const Node &b) {
        return a.t < b.t;
    }
} a[N];

int f[N][N];
int ans[M];

struct Query {
    int l, r, tag, use;
    
    Query (int l = 0, int r = 0, int tag = 0, int use = 0) :
        l(l), r(r), tag(tag), use(use) {}
};

void solve(int l, int r, vector <Query> &v) {
    if (v.size() == 0) {
        return;
    }
//printf("%d %d %d\n", l, r, (int)v.size());
    int mid = (l + r) >> 1;
    for (int i = 0; i <= 4000; i++) {
        if (i >= a[mid].c) {
            f[mid][i] = a[mid].h;
        } else {
            f[mid][i] = 0;
        }
    }
    
    for (int i = mid - 1; i >= l; i--) {
        for (int j = 0; j <= 4000; j++) {
            if (j >= a[i].c) {
                f[i][j] = max(f[i + 1][j], f[i + 1][j - a[i].c] + a[i].h);
            } else {
                f[i][j] = f[i + 1][j];
            }
        }
    }
    
    if (r - l >= 1) {
        for (int i = 0; i <= 4000; i++) {
            if (i >= a[mid + 1].c) {
                f[mid + 1][i] = a[mid + 1].h;
            } else {
                f[mid + 1][i] = 0;
            }
        }
        
        for (int i = mid + 2; i <= r; i++) {
            for (int j = 0; j <= 4000; j++) {
                if (j >= a[i].c) {
                    f[i][j] = max(f[i - 1][j], f[i - 1][j - a[i].c] + a[i].h);
                } else {
                    f[i][j] = f[i - 1][j];
                }
            }
        }
    }
    
    vector <Query> v1, v2;
    for (int i = 0; i < (int)v.size(); i++) {
        if (v[i].r < mid) {
            v1.push_back(v[i]);
        } else if (v[i].l > mid + 1) {
            v2.push_back(v[i]);
        } else {
            int l = v[i].l, r = v[i].r;
            if (r == mid) {
                ans[v[i].tag] = f[l][v[i].use];
            } else if (l == mid + 1) {
                ans[v[i].tag] = f[r][v[i].use];
            } else {
                int cc = v[i].use, tt = v[i].tag;
                for (int j = 0; j <= cc; j++) {
                    ans[tt] = max(ans[tt], f[l][j] + f[r][cc - j]);
                }
            }
        }
    }
    
    solve(l, mid, v1);
    solve(mid + 1, r, v2);
}

int n, p, q;
int vvv[N];
vector <Query> v;

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    scanf("%d %d", &n, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &a[i].c, &a[i].h, &a[i].t);
    }
    
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        vvv[i] = a[i].t;
    }
    
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        int x;
        scanf("%d", &x);
        Query now = Query(lower_bound(vvv + 1, vvv + n + 1, x - p + 1) - vvv, 
                        upper_bound(vvv + 1, vvv + n + 1, x) - vvv - 1, i);
        scanf("%d", &now.use);
        if (now.l > now.r) {
            ans[i] = 0;
            continue;
        }
        
        v.push_back(now);
    }
    
    solve(1, n, v);
    for (int i = 1; i <= q; i++) {
        printf("%d\n", ans[i]);
    }
    
    return 0;
}