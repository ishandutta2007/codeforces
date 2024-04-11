#include <bits/stdc++.h>
using namespace std;
int64_t best[100001];
void prepare() {
    for (int i = 1; i <= 100000; i++) {
        int64_t a = i / 3;
        int64_t b = a;
        int64_t c = a;
        if (a + b + c < i) c++;
        if (a + b + c < i) b++;
        best[i] = (a * b + b * c + c * a) * 2;
    }
}
void solve() {
    int64_t n;
    cin >> n;
    int pos = lower_bound(best + 1, best + 100001, n) - best;
    while (best[pos] < n) pos++;
    cout << pos << '\n';
}
int main() {
    prepare();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}