#include <cstdio>
#include <memory.h>
#include <cassert>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int N = 200500;

vector<int> X[N];

vector<int> app[N];

const int MODS[] = {
    32, 27, 25, 7, 11, 13, 17, 19, 23, 29, 31, 37
};

const int mn = sizeof(MODS) / sizeof(int);

int B[N];
char V[N];

int best[N];
int C[N];


int per[N];

inline int gcd(int a, int b) {
    while (b > 0)
        a %= b, swap(a, b);
    return a;
}

int calc(int l, int r, int x) {
    int n = r - l + 1;
    for (int i = 0; i < n; i++) {
        B[i] = find(X[l + i].begin(), X[l + i].end(), x) - X[l + i].begin();
        assert(B[i] != (int)X[l + i].size());
        best[i] = i + 1;
    }
    for (int mod : MODS) {
        for (int i = 0; i < n; i++) {
            per[i] = gcd(mod, X[l + i].size());
            //per[i] = 20;
            V[i] = B[i] % per[i];
            C[i] = 0;
        }
        for (int it = 0; it < mod; it++) {
            int len = 0;
            for (int i = 0; i < n; i++) {
                if (per[i] != 1) {
                    V[i]++;
                    if (V[i] != per[i]) {
                        len = 0;
                    } else {
                        V[i] = 0;
                        len++;
                    }
                } else {
                    len++;
                }
                if (C[i] < len)
                    C[i] = len;
            }
        }
        for (int i = 0; i < n; i++) {
            if (best[i] > C[i])
                best[i] = C[i];
        }
    }
    int longest = 0;
    for (int i = 0; i < n; i++) {
        if (longest < best[i])
            longest = best[i];
    }
    return longest;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        X[i].resize(k);
        for (int j = 0; j < k; j++) {
            scanf("%d", &X[i][j]);
            app[X[i][j]].push_back(i);
        }
    }
    int tot = 0;
    for (int i = 0; i < m; i++) {
        tot += X[i].size();
    }
    fprintf(stderr, "tot = %d\n", tot);
    for (int v = 1; v <= m; v++) {
        sort(app[v].begin(), app[v].end());
        int prv = -2, lprv = -2;
        int ans = 0;
        for (int i = 0; i <= (int)app[v].size(); i++) {
            int p = (i == (int)app[v].size()) ? n + 2 : app[v][i];
            if (p != prv + 1) {
                if (prv != -2) {
                    ans = max(ans, calc(lprv, prv, v));
                }
                lprv = prv = p;
            } else {
                prv = p;
            }
        }
        printf("%d\n", ans);
    }
}