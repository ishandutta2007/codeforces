#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, V, sz, t[maxn], a[maxn], f[maxn], c[maxn];

void upd(int p, int v) {
    for (p++; p <= sz; p += p & -p) c[p] = max(c[p], v);
}

int query(int p) {
    int s = -1e9;
    for (p++; p; p -= p & -p) s = max(s, c[p]);
    return s;
}

int main() {
    scanf("%d %d", &n, &V);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    fill(f + 1, f + n + 1, -1e9);
    auto rec = [&](auto self, int l, int r) {
        if (l == r) return;
        int mid = (l + r) / 2;
        self(self, l, mid);
        vector<int> L, R;
        vector<ll> nums;
        for (int i = l; i <= r; i++) {
            (i <= mid ? L : R).push_back(i);
            nums.push_back(a[i] - 1LL * V * t[i]);
        }
        auto solve = [&]() {
            sort(L.begin(), L.end(), [&](int i, int j) { return a[i] < a[j]; });
            sort(R.begin(), R.end(), [&](int i, int j) { return a[i] < a[j]; });
            sort(nums.begin(), nums.end());
            nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
            sz = nums.size(), fill(c + 1, c + sz + 1, -1e9);
            for (int i = 0, j = 0; i < R.size(); i++) {
                for (; j < L.size() && a[L[j]] <= a[R[i]]; j++) {
                    int k = lower_bound(nums.begin(), nums.end(), a[L[j]] - 1LL * V * t[L[j]]) - nums.begin();
                    upd(sz - k - 1, f[L[j]] + 1);
                }
                int k = lower_bound(nums.begin(), nums.end(), a[R[i]] - 1LL * V * t[R[i]]) - nums.begin();
                f[R[i]] = max(f[R[i]], query(sz - k - 1));
            }
        };
        solve();
        for (int i = l; i <= r; i++) a[i] *= -1;
        nums.clear();
        for (int i = l; i <= r; i++) {
            nums.push_back(a[i] - 1LL * V * t[i]);
        }
        solve();
        for (int i = l; i <= r; i++) a[i] *= -1;
        self(self, mid + 1, r);
    };
    rec(rec, 0, n);
    printf("%d\n", *max_element(f, f + n + 1));
    return 0;
}