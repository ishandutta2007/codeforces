#include <bits/stdc++.h>
using namespace std;

const int maxn = 4010, maxt = 20010;
int n, p, q, ans[maxt], lid[maxt], rid[maxt];
vector<array<int, 2>> item[maxt];
vector<array<int, 3>> Q[maxt];
vector<array<int, maxn>> L, R;

void chk(int &x, int y) {
    if (x < y) x = y;
}

int main() {
    scanf("%d %d", &n, &p);
    for (int i = 1, c, h, t; i <= n; i++) {
        scanf("%d %d %d", &c, &h, &t);
        item[t].push_back({c, h});
    }
    scanf("%d", &q);
    for (int i = 1, a, b; i <= q; i++) {
        scanf("%d %d", &a, &b);
        for (int j = 1; j < maxt; j += p) {
            if (j <= a && j + p > a) Q[j].push_back({a, b, i});
        }
    }
    for (int i = 1; i < maxt; i += p) if (!Q[i].empty()) {
        L.clear(), R.clear();
        array<int, maxn> tmp;
        fill(tmp.begin(), tmp.begin() + maxn, 0);
        L.push_back(tmp), R.push_back(tmp);
        for (int j = i; j && j > i - p; j--) {
            for (auto &p : item[j]) {
                tmp = L.back();
                for (int k = maxn - p[0] - 1; ~k; k--) {
                    chk(tmp[k + p[0]], tmp[k] + p[1]);
                }
                L.push_back(tmp);
            }
            lid[j] = L.size() - 1;
        }
        rid[i] = 0;
        for (int j = i + 1; j < maxt && j < i + p; j++) {
            for (auto &p : item[j]) {
                tmp = R.back();
                for (int k = maxn - p[0] - 1; ~k; k--) {
                    chk(tmp[k + p[0]], tmp[k] + p[1]);
                }
                R.push_back(tmp);
            }
            rid[j] = R.size() - 1;
        }
        for (auto &q : Q[i]) {
            for (int j = 0; j <= q[1]; j++) {
                chk(ans[q[2]], L[lid[max(1, q[0] - p + 1)]][j] + R[rid[q[0]]][q[1] - j]);
            }
        }
    }
    for (int i = 1; i <= q; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}