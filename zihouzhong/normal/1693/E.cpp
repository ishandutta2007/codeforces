#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a[maxn];
vector<int> V[maxn];

namespace BIT {
int c[maxn];

void add(int p, int v) {
    for (; p <= n; p += p & -p) c[p] += v;
}

int query(int p) {
    int s = 0;
    for (; p; p -= p & -p) s += c[p];
    return s;
}
} // namespace BIT

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i], V[a[i]].push_back(i);
    }
    long long ans = 0;
    int l = 1, r = n;
    for (int x = n; x; x--) if (!V[x].empty()) {
        for (int i : V[x]) BIT::add(i, 1);
        int _l = min(r + 1, V[x][0]), _r = max(l - 1, V[x].back());
        l = _l, r = _r;
        ans += BIT::query(r) - BIT::query(l - 1);
    }
    cout << ans << "\n";
    return 0;
}