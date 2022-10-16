#include <bits/stdc++.h>
using namespace std;
int64_t h_c, d_c, h_m, d_m, k, d_p, h_p;
int64_t get_turn_to_kill(int64_t d, int64_t h) { return (h - 1) / d + 1; }
bool win(int64_t h, int64_t d, int64_t mh, int64_t md) { return get_turn_to_kill(d, mh) <= get_turn_to_kill(md, h); }
void solve() {
    cin >> h_c >> d_c >> h_m >> d_m >> k >> d_p >> h_p;

    for (int i = 0; i <= k; i++)
        if (win(h_c + h_p * i, d_c + d_p * (k - i), h_m, d_m)) {
            cout << "YES\n";
            return;
        }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}