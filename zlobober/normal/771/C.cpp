#include <cassert>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std;

const int K = 5;

int k;

typedef long long llong;

struct info {
    int cnt[K];
    llong sum[K];
    info() {
        memset(cnt, 0, sizeof(cnt));
        memset(sum, 0, sizeof(sum));
    }
    friend info operator +(info a, info b) {
        info res;
        for (int i = 0; i < k; i++) {
            res.cnt[i] = a.cnt[i] + b.cnt[i];
            res.sum[i] = a.sum[i] + b.sum[i];
        }
        return res;
    }
    void promote() {
        rotate(sum, sum + k - 1, sum + k);
        rotate(cnt, cnt + k - 1, cnt + k);
        for (int i = 0; i < k; i++) {
            sum[i] += cnt[i];
        }
    }
};

const int N = 200500;

info I[N];
vector<int> E[N];

llong ans = 0;

info merge(info a, info b) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            int ca = a.cnt[i];
            llong sa = a.sum[i];
            int cb = b.cnt[j];
            llong sb = b.sum[j];
            int rem = k - (i + j) % k;
            if (rem == k)
                rem = 0;
            llong res = sa * cb + sb * ca + rem * (llong)ca * (llong)cb;
            assert(res % k == 0);
            res /= k;
            ans += res;
        }
    }
    return a + b;
}

void DFS(int x, int p) {
    info cur;
    cur.cnt[0] = 1;
    cur.sum[0] = 0;

    for (int y : E[x]) {
        if (y == p)
            continue;
        DFS(y, x);
        cur = merge(cur, I[y]);
    }
    I[x] = cur;
    I[x].promote();
}

int main() {
    int n;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS(0, -1);
    printf("%lld\n", ans);
}