#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k;
    cin >> k;
    vector<int> c(k);
    long long sum = 0;
    for (int &x : c) {
        cin >> x, sum += x;
    }
    vector<long long> fib{1, 1};
    while (accumulate(fib.begin(), fib.end(), 0LL) < sum) {
        fib.push_back(fib[fib.size() - 2] + fib.back());
    }
    if (sum == 1) fib.pop_back();
    if (accumulate(fib.begin(), fib.end(), 0LL) != sum) {
        cout << "NO\n"; return;
    }
    vector<int> cnt(fib.size());
    int num = 0, bad = 0;
    for (int x : c) {
        for (int i = fib.size() - 1; i > 0; i--) if (x >= fib[i]) {
            if (!cnt[i]++) num++;
            x -= fib[i], i--;
        }
        if (x) bad++;
    }
    auto orig = cnt;
    int o = num;
    for (int x : c) {
        num = o, cnt = orig;
        int v = x;
        for (int i = fib.size() - 1; i > 0; i--) if (v >= fib[i]) {
            if (!--cnt[i]) num--;
            v -= fib[i], i--;
        }
        int _bad = bad - (v > 0);
        v = x - 1;
        for (int i = fib.size() - 1; i > 1; i--) if (v >= fib[i]) {
            if (!cnt[i]++) num++;
            v -= fib[i], i--;
        }
        if (!v && !_bad && num == fib.size() - 1) {
            cout << "YES\n"; return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}