#include <bits/stdc++.h>
using namespace std;
int a[200001];
int b[200001];
int n;
int make(int* x, int id, int* y) {
    int ans = 1e9;
    for (int i = 1; i <= n; i++) ans = min(ans, abs(y[i] - x[id]));
    return ans;
}

int64_t A() {
    int64_t ans = 0;
    ans += make(a, 1, b);
    ans += make(a, n, b);
    ans += make(b, 1, a);
    ans += make(b, n, a);
    return ans;
}
int64_t B() {
    int64_t ans = 0;
    ans += abs(a[1] - b[1]);
    ans += make(a, n, b);
    ans += make(b, n, a);
    return ans;
}
int64_t C() {
    int64_t ans = 0;
    ans += abs(a[1] - b[n]);
    ans += make(a, n, b);
    ans += make(b, 1, a);
    return ans;
}
int64_t D() {
    int64_t ans = 0;
    ans += abs(a[n] - b[1]);
    ans += make(a, 1, b);
    ans += make(b, n, a);
    return ans;
}
int64_t E() {
    int64_t ans = 0;
    ans += abs(a[n] - b[n]);
    ans += make(a, 1, b);
    ans += make(b, 1, a);
    return ans;
}
int64_t F() {
    int64_t ans = 0;
    ans += abs(a[n] - b[n]);
    ans += abs(a[1] - b[1]);
    return ans;
}
int64_t G() {
    int64_t ans = 0;
    ans += abs(a[n] - b[1]);
    ans += abs(a[1] - b[n]);
    return ans;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    cout << min(min(min(A(), B()), min(C(), D())), min(min(E(), F()), G())) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}