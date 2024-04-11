#include <cstdio>
#include <memory.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;

const int N = 200500;

vector<int> E[N];

typedef long long llong;

int A[N], B[N];
llong W[N];

int was[N];

llong path[N];

const int M = 62;
vector<llong> Q;
vector<llong> paths;

void DFS(int x, int p) {
    was[x] = true;
    paths.push_back(path[x]);
    for (int e : E[x]) {
        int y = A[e] ^ B[e] ^ x;
        if (y == p)
            continue;
        if (!was[y]) {
            path[y] = path[x] ^ W[e];
            DFS(y, x);
        } else {
            Q.push_back(path[x] ^ path[y] ^ W[e]);
        }
    }
}

int cnt[M][2];

int pw2[N];

int solve(int x) {
    Q.clear();
    paths.clear();
    DFS(x, -1);
    int rk = 0;
    for (int j = 0; j < M; j++) {
        int p = -1;
        for (int i = rk; i < (int)Q.size(); i++) {
            if ((Q[i] >> j) & 1ll) {
                p = i;
                break;
            }
        }
        if (p == -1) {
            continue;
        }
        swap(Q[p], Q[rk]);
        for (int i = rk + 1; i < (int)Q.size(); i++) {
            if ((Q[i] >> j) & 1ll) {
                Q[i] ^= Q[rk];
            }
        }
        rk++;
    }
    Q.resize(rk);
    bool has1[M];
    for (int i = 0; i < M; i++) {
        has1[i] = false;
        for (llong p : Q)
            has1[i] |= ((p >> i) & 1ll);
    }
    memset(cnt, 0, sizeof(cnt));
    int ans = 0;
    for (llong p : paths) {
        for (int j = 0; j < M; j++) {
            int our = (p >> j) & 1ll;
            for (int their = 0; their < 2; their++) {
                int add = has1[j] ? pw2[(int)Q.size() - 1] : ((their + our) & 1) ? pw2[(int)Q.size()] : 0;
                add = 1ll * add * pw2[j] % MOD;
                ans = (ans + 1ll * cnt[j][their] * add) % MOD;
            }
        }
        for (int j = 0; j < M; j++) {
            cnt[j][(p >> j) & 1ll]++;
        }
    }
    return ans;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %lld", &A[i], &B[i], &W[i]);
        --A[i], --B[i];
        E[A[i]].push_back(i);
        E[B[i]].push_back(i);
    }

    int ans = 0;

    pw2[0] = 1;
    for (int i = 1; i < N; i++) {
        pw2[i] = pw2[i - 1] * 2;
        if (pw2[i] >= MOD)
            pw2[i] -= MOD;
    }

    for (int i = 0; i < n; i++) {
        if (!was[i]) {
            ans = (ans + solve(i)) % MOD;
        }
    }
    printf("%d\n", ans);
}