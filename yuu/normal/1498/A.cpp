#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t n;
    cin >> n;
    auto sum_of_digit = [](int64_t n) -> int64_t {
        int64_t res = 0;
        while (n) {
            res += n % 10;
            n /= 10;
        }
        return res;
    };
    while (gcd(n, sum_of_digit(n)) == 1) n++;
    cout << n << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}