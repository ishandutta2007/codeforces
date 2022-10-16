#include <bits/stdc++.h>
using namespace std;
int h, m, hh, mm;
string s;
constexpr int mirror[] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
int GetMirrored(int a) {
    int b = a % 10;
    a /= 10;
    if ((mirror[b] == -1) || (mirror[a] == -1)) return 1e9;
    return mirror[b] * 10 + mirror[a];
}
void solve() {
    cin >> h >> m >> s;
    hh = 10 * (s[0] - '0') + s[1] - '0';
    mm = 10 * (s[3] - '0') + s[4] - '0';
    while (true) {
        auto mirror_hh = GetMirrored(mm);
        auto mirror_mm = GetMirrored(hh);
        if ((mirror_hh < h) && (mirror_mm < m)) {
            cout << setw(2) << setfill('0') << hh << ":" << setw(2) << setfill('0') << mm << '\n';
            return;
        }
        mm++;
        if (mm == m) {
            mm = 0;
            hh++;
            if (hh == h) hh = 0;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}