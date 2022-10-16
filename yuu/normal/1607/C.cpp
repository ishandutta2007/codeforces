#include <bits/stdc++.h>
#define pd(x) cerr << __LINE__ << ": " << #x << " = " << (x) << '\n';
using namespace std;
int n;
int64_t a[200001];
multiset<int64_t> s;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    s.clear();
    for (int i = 1; i <= n; i++) s.insert(a[i]);
    int64_t offset = 0;
    int64_t ans = *s.begin();
    while (s.size() > 1) {
        offset += (*s.begin() - offset);
        s.erase(s.begin());
        ans = max(ans, *s.begin() - offset);
        if (*s.rbegin() - offset <= ans) break;
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}