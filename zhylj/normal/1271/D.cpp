#include <bits/stdc++.h>

const int kN = 5e3 + 5;
const int kInf = 0x3f3f3f3f;

int a[kN], b[kN], c[kN], d[kN], f[kN][kN];
std::vector<int> lst[kN];

void Update(int &x, int y) { x = std::max(x, y); }

int main() {
    memset(f, ~0x3f, sizeof(f));
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; ++i)
        scanf("%d%d%d", a + i, b + i, c + i), d[i] = i;
    for(int i = 1; i <= m; ++i) {
        int x, y; scanf("%d%d", &x, &y);
        Update(d[y], x);
    }
    for(int i = 1; i <= n; ++i) lst[d[i]].push_back(i);
    for(int i = 1; i <= n; ++i)
        sort(lst[i].begin(), lst[i].end(), [](int x, int y) { return c[x] > c[y]; });
    f[0][k] = 0;
    for(int i = 0; i <= n; ++i)
        for(int j = a[i]; j < kN; ++j) {
            int c_sum = 0;
            if(j + b[i] >= a[i + 1]) Update(f[i + 1][j + b[i]], f[i][j]);
            for(int x = 0; x < lst[i].size() && j - x - 1 + b[i] >= a[i + 1]; ++x) {
                int v = lst[i][x];
                c_sum += c[v];
                if(j - x + b[i] < kN)
                    Update(f[i + 1][j - x - 1 + b[i]], f[i][j] + c_sum);
            }
        }
    int ans = -kInf;
    for(int i = 0; i < kN; ++i) Update(ans, f[n + 1][i]);
    printf("%d", ans >= 0 ? ans : -1);
    return 0;
}