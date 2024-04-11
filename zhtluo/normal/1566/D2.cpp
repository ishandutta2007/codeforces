#include <bits/stdc++.h>

int T, N, M;
int lb[500 * 500], lbs;
int st[500 * 500];
int es[500 * 500];
int occ[500 * 500];
std::vector<int> arr[500 * 500];

bool cmp(int i, int j) {
    if (i / M < j / M) return false;
    if (i / M > j / M) return true;
    return i < j;
}

int main() {
    scanf("%d", &T); while (T--) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N * M; ++i) scanf("%d", &es[i]);
        for (int i = 0; i < N * M; ++i) lb[i] = es[i];
        std::sort(lb, lb + N * M); lbs = std::unique(lb, lb + N * M) - lb;
        for (int i = 0; i < N * M; ++i) st[i] = es[i];
        std::sort(st, st + N * M);
        for (int i = 0; i < N * M; ++i) {
            arr[std::lower_bound(lb, lb + lbs, st[i]) - lb].push_back(i);
        }
        for (int i = 0; i < lbs; ++i) std::sort(arr[i].begin(), arr[i].end(), cmp);
        int ans = 0;
        std::fill(occ, occ + N * M, 0);
        for (int i = 0; i < N * M; ++i) {
            int loc = arr[std::lower_bound(lb, lb + lbs, es[i]) - lb].back();
            arr[std::lower_bound(lb, lb + lbs, es[i]) - lb].pop_back();
            for (int j = (loc / M) * M; j < loc; ++j) {
                if (occ[j]) ++ans;
            }
            occ[loc] = 1;
        }
        printf("%d\n", ans);
        for (int i = 0; i < N * M; ++i) arr[i].clear();
    }
}