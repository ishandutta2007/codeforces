#include <bits/stdc++.h>
using namespace std;
constexpr int PRE_COMPUTE = 20'000'000;
int cnt[PRE_COMPUTE + 1];
int64_t ans = 0;
int get_big(int64_t value) {
    int cnt = 0;
    for (int64_t i = 2; i * i <= value; i += (1 + i % 2)) {
        if (value % i == 0) {
            cnt++;
            while (value % i == 0) value /= i;
        }
    }
    if (value > 1) cnt++;
    return (1 << cnt);
}

void prepare() {
    for (int i = 2; i <= PRE_COMPUTE; i++)
        if (cnt[i] == 0) {
            for (int j = i; j <= PRE_COMPUTE; j += i)
                if (cnt[j] == 0) cnt[j] = i;
        }
    cnt[1] = 1;
    for (int i = 2; i <= PRE_COMPUTE; i++) {
        int u = i;
        while (u % cnt[i] == 0) u /= cnt[i];
        cnt[i] = cnt[u] * 2;
    }
}
int c, d, x;

void check(int64_t g) {
    int64_t l = g * d + x;
    if (l % c) return;
    l /= c;
    if (l % g) return;
    l /= g;
    if (l <= PRE_COMPUTE)
        ans += cnt[l];
    else
        ans += get_big(l);
}

void solve() {
    cin >> c >> d >> x;
    ans = 0;
    for (int g = 1; g * g <= x; g++)
        if (x % g == 0) {
            check(g);
            if (g != (x / g)) check(x / g);
        }
    cout << ans << '\n';
}
int main() {
    prepare();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}