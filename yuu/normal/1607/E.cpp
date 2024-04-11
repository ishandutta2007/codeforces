#include <bits/stdc++.h>
#define pd(x) cerr << __LINE__ << ": " << #x << " = " << (x) << '\n';
using namespace std;
int n, m;
string s;
void solve() {
    cin >> n >> m;
    cin >> s;
    int lx = 1, ly = 1, hx = n, hy = m;
    int ansx = 1, ansy = 1;
    int ax = 0, ay = 0;
    for (auto&& c : s) {
        if (c == 'U')
            ax--;
        else if (c == 'D')
            ax++;
        else if (c == 'R')
            ay++;
        else
            ay--;
        lx = max(lx, 1 - ax);
        ly = max(ly, 1 - ay);
        hx = min(hx, n - ax);
        hy = min(hy, m - ay);
        if (lx > hx) break;
        if (ly > hy) break;
        ansx = lx;
        ansy = ly;
    }
    cout << ansx << ' ' << ansy << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}