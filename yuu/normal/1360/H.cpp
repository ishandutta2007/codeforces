#include <bits/stdc++.h>
using namespace std;
int n, m;
int64_t k;
int64_t a[101];
map<int64_t, bool> mem;
bool check(int64_t x) {
    if (mem.count(x)) return mem[x];
    // return false if >= ans
    // k element less than x
    int64_t less = x;
    int i = 1;
    for (i = 1; i <= n; i++) {
        if (a[i] >= x) break;
    }
    if (i == n + 1) {
        return mem[x] = (x - n >= k);
    } else {
        if (a[i] > x) {
            return mem[x] = (x - (i - 1) >= k);
        } else {
            // a[i] == 'x'
            if (x - (i - 1) < k) return mem[x] = false;
            return mem[x] = check(x - 1);
        }
    }
}
void solve() {
    mem.clear();
    cin >> n >> m;
    k = (1LL << m) - n;
    k = (k - 1) / 2;
    for (int i = 1; i <= n; i++) {
        static string s;
        cin >> s;
        a[i] = 0;
        for (auto&& x : s) (a[i] *= 2) += (x - '0');
    }
    sort(a + 1, a + n + 1);
    int64_t low = 0, high = (1LL << m) - 1, mid, res;

    while (low <= high) {
        // cerr << low << ' ' << high << '\n';
        mid = (low + high) / 2;
        if (check(mid)) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    string s;
    for (int i = 1; i <= m; i++) {
        s += "01"[res % 2];
        res /= 2;
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}