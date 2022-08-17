#include <cstdio>
#include <tuple>
#include <algorithm>
#include <cstdlib>
using namespace std;

const int N = 80;
const int MOD = 1000 * 1000 * 1000 + 7;
const int R = 20;

char buf[N];

int tpt[N];
pair<int, int> T[N][N];

int D[N][1 << R];

int n;

void init_trans() {
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = i + 1; j <= n; j++) {
            cur = 2 * cur + buf[j - 1] - '0';
            if (cur >= 1 && cur <= R)
                T[i][tpt[i]++] = make_pair(j, 1 << (cur - 1));
            if (cur > R)
                break;
        }
    }
}

int main() {
    scanf("%d", &n);
    scanf("%s", buf);
    init_trans();
    for (int i = 0; i < n; i++) {
        D[i][0] = 1;
        for (int t = 0; t < tpt[i]; t++) {
            int j, by;
            tie(j, by) = T[i][t];
            for (int msk = 0; msk < (1 << R); msk++) {
                int nmsk = msk | by;
                D[j][nmsk] += D[i][msk];
                if (D[j][nmsk] >= MOD)
                    D[j][nmsk] -= MOD;
            }
        }
    }
    int ans = 0;
    for (int m = 1; m <= R; m++) {
        int msk = (1 << m) - 1;
        for (int i = 0; i <= n; i++) {
            ans += D[i][msk];
            if (ans >= MOD)
                ans -= MOD;
        }
    }
    printf("%d\n", ans);
    //fprintf(stderr, "%d\n", (int)sizeof(D));
}