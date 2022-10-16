#include <bits/stdc++.h>
using namespace std;

int ask(int a, int b, int c) {  // return 1 if more imposter
    cout << "? " << a << ' ' << b << ' ' << c << '\n';
    cout.flush();
    cin >> a;
    return 1 - a;
}

int ans[10000];  // ans[i] = 1 -> imposter

pair<int, int> find_zero_one_pair(int a, int b, int c, int d, int e, int f) {
    int res_abd = ask(a, b, d);
    int res_abe = ask(a, b, e);
    if ((res_abd == 0) && (res_abe == 0)) {
        ans[a] = 0;
        ans[b] = 0;
        // both a and b is 0
        if (ask(d, e, a)) {  // both d and e is 1
            ans[d] = ans[e] = 1;
            ans[f] = ask(d, f, a);
            ans[c] = ask(c, d, a);
            return {a, d};
        } else {  // one of d and e is 1, the other is 0, f is 1
            ans[f] = 1;
            ans[d] = ask(d, f, a);
            ans[e] = 1 - ans[d];
            ans[c] = ask(c, f, a);
            return {a, f};
        }
    } else {
        // exactly 1 of a and b is 0
        ans[c] = 0;
        if (res_abd) {  // d = 1
            ans[d] = 1;
            ans[a] = ask(d, a, c);
            ans[b] = 1 - ans[a];
            ans[e] = ask(d, c, e);
            ans[f] = ask(d, c, f);
            return {c, d};
        } else {  // e = 1
            ans[e] = 1;
            ans[a] = ask(e, a, c);
            ans[b] = 1 - ans[a];
            ans[d] = ask(e, c, d);
            ans[f] = ask(e, c, f);
            return {c, e};
        }
    }
}

// Solve a tripple in 2 guess
void solve_triple(int zero, int one, int a, int b, int c, int res) {
    if (res) {  // at least 2 one
        if (ask(zero, a, b)) {
            ans[a] = ans[b] = 1;
            ans[c] = ask(zero, one, c);
        } else {
            ans[c] = 1;
            ans[a] = ask(zero, one, a);
            ans[b] = 1 - ans[a];
        }
    } else {  // at least 2 zero
        if (ask(one, a, b) == 0) {
            ans[a] = ans[b] = 0;
            ans[c] = ask(zero, one, c);
        } else {
            ans[c] = 0;
            ans[a] = ask(zero, one, a);
            ans[b] = 1 - ans[a];
        }
    }
}

int res[10000];
int n;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ans[i] = 0;
    }
    int zero = 0, one = 0;
    for (int i = 1; i <= n; i += 3) {
        res[i] = ask(i, i + 1, i + 2);
        if (res[i] == 0)
            zero = i;
        else
            one = i;
    }
    assert(one && zero);
    auto [a, b] = find_zero_one_pair(zero, zero + 1, zero + 2, one, one + 1, one + 2);
    for (int i = 1; i <= n; i += 3)
        if (i != zero && i != one) {
            solve_triple(a, b, i, i + 1, i + 2, res[i]);
        }
    int k = 0;
    for (int i = 1; i <= n; i++) k += ans[i];
    assert(k > n / 3);
    assert(k < (n * 2) / 3);
    cout << "! " << k;
    for (int i = 1; i <= n; i++)
        if (ans[i]) cout << " " << i;
    cout << '\n';
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}