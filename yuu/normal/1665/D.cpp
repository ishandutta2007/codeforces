#include <bits/stdc++.h>
using namespace std;

// #define YUU_LOCAL
int local_ans;
int local_ask(int a, int b) { return gcd(local_ans + a, local_ans + b); }
void local_guess(int x) {
    assert(local_ans == x);
    cerr << "CORRECT\n";
}

int ask(int a, int b) {
#ifdef YUU_LOCAL
    return local_ask(a, b);
#endif
    cout << "? " << a << ' ' << b << '\n';
    cout.flush();
    cin >> a;
    return a;
}
void guess(int x) {
#ifdef YUU_LOCAL
    local_guess(x);
    return;
#endif
    cout << "! " << x << '\n';
    cout.flush();
}

void solve() {
#ifdef YUU_LOCAL
    cin >> local_ans;
#endif
    int ans = 2;  // we will guess for x + 2 instead
    for (int p = 2, turn = 1; turn <= 30; p *= 2, turn++) {
        int res = ask(ans, ans + p);
        if (res % p != 0) ans += p / 2;
    }
    guess((1 << 30) - ans);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}