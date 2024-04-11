#include <bits/stdc++.h>
using namespace std;
int f[501][501][2][2];
bool done[501][501][2][2];
int F(int zz, int zo, bool mid, bool switchable) {
    if (done[zz][zo][mid][switchable]) return f[zz][zo][mid][switchable];
    done[zz][zo][mid][switchable] = 1;
    if (zz == 0 && zo == 0 && mid == 0) return f[zz][zo][mid][switchable] = 0;
    if ((switchable) && (zo > 0))
        f[zz][zo][mid][switchable] = -F(zz, zo, mid, 0);
    else
        f[zz][zo][mid][switchable] = -1e9;
    if (mid) f[zz][zo][mid][switchable] = max(f[zz][zo][mid][switchable], -F(zz, zo, 0, 1) - 1);
    if (zz) f[zz][zo][mid][switchable] = max(f[zz][zo][mid][switchable], -F(zz - 1, zo + 1, mid, 1) - 1);
    if (zo) f[zz][zo][mid][switchable] = max(f[zz][zo][mid][switchable], -F(zz, zo - 1, mid, 1) - 1);
    return f[zz][zo][mid][switchable];
}
void solve() {
    int n;
    string s;
    cin >> n >> s;
    int l = 0, r = n - 1;
    int zz = 0;
    int zo = 0;
    bool mid = 0;
    while (l < r) {
        if (s[l] == '0') {
            if (s[r] == '0')
                zz++;
            else
                zo++;
        } else if (s[r] == '0') {
            zo++;
        }
        l++;
        r--;
    }
    if (l == r) mid = (s[l] == '0');
    if (F(zz, zo, mid, 1) > 0) {
        cout << "ALICE\n";
    } else if (F(zz, zo, mid, 1) < 0) {
        cout << "BOB\n";
    } else {
        cout << "DRAW\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}