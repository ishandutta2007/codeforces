#include <bits/stdc++.h>
using namespace std;
constexpr int base = 1e9 + 7;
int f[40001];
bool is_palindromic(int n) {
    static vector<int> digits;
    digits.clear();
    int x = n;
    while (x) {
        digits.push_back(x % 10);
        x /= 10;
    }
    for (auto&& d : digits) (x *= 10) += d;
    return (x == n);
}
void prepare() {
    f[0] = 1;
    for (int i = 1; i <= 40000; i++) {
        if (is_palindromic(i)) {
            for (int mod = 0; mod < i; mod++) {
                if (mod + i > 40000) break;
                int sum = 0;
                for (int k = mod + i; k <= 40000; k += i) {
                    (f[k] += f[k - i]) %= base;
                }
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    cout << f[n] << '\n';
}
int main() {
    prepare();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}