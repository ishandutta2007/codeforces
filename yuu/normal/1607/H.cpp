#include <bits/stdc++.h>
#define pd(x) cerr << __LINE__ << ": " << #x << " = " << (x) << '\n';
using namespace std;
int n;
class Dish {
  public:
    int a, b, m, l, r, id;
} d[200001];
vector<int> s;
int ans;
void solve(int l, int r) {
    for (int i = l; i <= r; i++) {
        int low = max(0, d[i].m - d[i].b);
        int high = min(d[i].m, d[i].a);
        d[i].l = d[i].a - high;
        d[i].r = d[i].a - low;
    }
    sort(d + l, d + r + 1, [](const Dish& A, const Dish& B) { return A.l < B.l; });
    int stop = 1e9;
    for (int i = l; i <= r; i++) {
        if (stop < d[i].l) {
            ans++;
            for (auto&& u : s) {
                assert(d[u].l <= stop);
                assert(d[u].r >= stop);
                d[u].a = d[u].a - stop;
                d[u].b = d[u].m - d[u].a;
            }
            s.clear();
            stop = 1e9;
        }
        s.push_back(i);
        stop = min(stop, d[i].r);
    }
    if (!s.empty()) {
        ans++;
        for (auto&& u : s) {
            assert(d[u].l <= stop);
            assert(d[u].r >= stop);
            d[u].a = d[u].a - stop;
            d[u].b = d[u].m - d[u].a;
        }
        s.clear();
    }
}

void solve() {
    cin >> n;
    for (int i = 1, a, b, m; i <= n; i++) {
        cin >> d[i].a >> d[i].b >> d[i].m;
        d[i].r = d[i].a + d[i].b - d[i].m;
        d[i].id = i;
    }
    ans = 0;
    sort(d + 1, d + n + 1, [](const Dish& A, const Dish& B) { return A.r < B.r; });
    for (int i = 1, j; i <= n; i++) {
        j = i;
        while ((j < n) && (d[j + 1].r == d[j].r)) j++;
        solve(i, j);
        i = j;
    }
    sort(d + 1, d + n + 1, [](const Dish& A, const Dish& B) { return A.id < B.id; });
    cout << ans << '\n';
    for (int i = 1; i <= n; i++) cout << d[i].a << ' ' << d[i].b << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}