#include <bits/stdc++.h>
using namespace std;
constexpr int base = 1e9 + 7;
int64_t low_b, prd_b, num_b, high_b;
int64_t low_c, prd_c, num_c, high_c;
int64_t ans;
void make(int64_t prd_a) {
    if (lcm(prd_a, prd_b) != prd_c) return;
    int64_t mod = low_c % prd_a;
    int64_t low_a = low_c - prd_c + 1;
    if (low_a % prd_a < mod) {
        low_a += mod - low_a % prd_a;
    } else if (low_a % prd_a > mod) {
        low_a += prd_a + mod - low_a % prd_a;
    }
    if (low_a > low_c) return;
    int64_t high_a = high_c + prd_c - 1;
    mod = high_c % prd_a;
    if (high_a % prd_a > mod) {
        high_a -= high_a % prd_a - mod;
    } else if (high_a % prd_a < mod) {
        high_a -= high_a % prd_a + prd_a - mod;
    }
    if (high_a < high_c) return;
    int64_t count_high = (high_a - high_c) / prd_a + 1;
    int64_t count_low = (low_c - low_a) / prd_a + 1;
    count_high %= base;
    count_low %= base;
    (ans += count_high * count_low) %= base;
}

void solve() {
    cin >> low_b >> prd_b >> num_b;
    high_b = low_b + prd_b * (num_b - 1);

    cin >> low_c >> prd_c >> num_c;
    high_c = low_c + prd_c * (num_c - 1);
    if (prd_c % prd_b) {
        cout << "0\n";
        return;
    }
    if ((low_c < low_b) || (high_c > high_b)) {
        cout << "0\n";
        return;
    }
    assert(num_c <= num_b);
    if ((low_c - low_b) % prd_b) {
        cout << "0\n";
        return;
    }
    if ((low_c - prd_c < low_b) || (high_c + prd_c > high_b)) {
        cout << "-1\n";
        return;
    }
    // prd_c == lcm(prd_a, prd_b)
    ans = 0;
    for (int i = 1; i * i <= prd_c; i++) {
        if (prd_c % i == 0) {
            make(i);
            if (i * i != prd_c) make(prd_c / i);
        }
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