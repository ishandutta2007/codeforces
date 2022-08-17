#include <cstdio>
#include <vector>
#include <memory.h>
#include <algorithm>
using namespace std;

const int N = 1000 * 1000 + 500;

const int MOD = 1000 * 1000 * 1000 + 7;

inline int add(int a, int b) {
    if ((a += b) >= MOD)
        a -= MOD;
    return a;
}

const int K = 30;
int F[N][30];


int mnp[N];

typedef long long llong;

void init() {
    for (int j = 0; j < K; j++)
        F[0][j] = (j > 0) + 1;
    for (int i = 1; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < K; j++) {
            sum = add(sum, F[i - 1][j]);
            F[i][j] = sum;
        }
    }
    memset(mnp, -1, sizeof(mnp));
    for (int i = 2; i < N; i++) {
        if (mnp[i] == -1) {
            mnp[i] = i;
            for (int j = min((llong)N, (llong)i * i); j < N; j += i) {
                if (mnp[j] == -1)
                    mnp[j] = i;
            }
        }
    }
}

inline int mul(int a, int b) {
    return ((llong)a) * b % MOD;
}

int main() {
    init();

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int r, n;
        scanf("%d %d", &r, &n);
        vector<pair<int, int>> f;
        while (n > 1) {
            int p = mnp[n];
            f.emplace_back(p, 0);
            while (n % p == 0)
                n /= p, f.back().second++;
        }
        int ans = 1;
        for (const auto& pr : f)
            ans = mul(ans, F[r][pr.second]);
        printf("%d\n", ans);
    }

}